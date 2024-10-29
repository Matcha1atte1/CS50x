import random

# constants
suits = ["Hearts", "Diamonds", "Clubs", "Spades"]
values = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]

# create deck of 52 cards sorted in order
deck = [f"{value} of {suit}" for suit in suits for value in values]


