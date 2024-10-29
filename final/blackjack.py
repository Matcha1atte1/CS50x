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

def display_hand(person, hand):
    print(f"{person}'s hand value: {calculate_hand_value(hand)}")


# main game flow
def blackjack():
    print("Welcome to BlackJack")

    while True:
        # shuffle deck
        shuffle_deck(deck)

        # deal two cards each
        player_hand = [deal_card(deck), deal_card(deck)]
        dealer_hand =  [deal_card(deck), deal_card(deck)]

        # player turn
        while True:
            display_hand("player", player_hand)
            if calculate_hand_value(player_hand) > 21:
                print("Bust, you lose!")
                break

            action = input("Do u want to hit (h) or stand (s)?").lower()
            if action == "h":
                player_hand.append(deal_card(deck))
            elif action =="s":
                break
            else:
                print("Invalid input")

        # check if player busted
        if caclulate_hand_value(player_hand) > 21:
            print("Dealer wins!")
        else:
            # dealer turn
            while calculate_hand_value(dealer_hand) < 17:
                dealer_hand.appened(deal_card(deck))

            display_hand("dealer", dealer_hand)

            # determine winner
            if calculate_hand_value(dealer_hand) > 21:
                print("Dealer busts, you win!")
            elif calculate_hand_value(player_hand) > calculate_hand_value(dealer_hand):
                print("You win!")
            elif calculate_hand_value(player_hand) < calculate_hand_value(dealer_hand):
                print("You lose!")
            else:
                print("Tie!")

        # ask to play again
        play_again = input("Do you want to play again? (y/n): ").lower()
        if play_again != y:
            break

    print("Thank you for playing!")

# start game
blackjack()





