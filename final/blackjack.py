import random

# constants
suits = ["Hearts", "Diamonds", "Clubs", "Spades"]
values = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]

# create deck of 52 cards sorted in order
deck = [f"{value} of {suit}" for suit in suits for value in values]

# function to shuffle deck
def shuffle_deck(deck):
    random.shuffle(deck)

# function to deal a card
def deal_card(deck):
    return deck.pop()

# function to calculate hand value
def calculate_hand_value(hand):
    value = 0
    ace_count = 0

    for card in hand:
        rank = card.split(' ')[0]
        if rank in ["J", "Q", "K"]:
            value += 10
        elif rank=="A":
            ace_count += 1
            value += 11
        else:
            value += int(rank)

    # adjust for aces
    while value > 21 and ace_count > 0:
        value -= 10
        ace_count -= 1

    return value


# main game flow
def blackjack():
    print("Welcome to BlackJack")

    while True:
        # deal one card each
        player_hand, dealer_hand = deal_card(deck)

        
