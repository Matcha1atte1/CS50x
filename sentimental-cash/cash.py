def calculate_quarters(dollars):
    quarters = 0
    if dollars < 0.25:
        return quarters
    while dollars >= 0.25:
        quarters += 1
        dollars -= 0.25
    return quarters


def calculate_dimes(dollars):
    dimes = 0
    if dollars < 0.10:
        return dimes
    while dollars >= 0.10:
        dimes += 1
        dollars -= 0.10
    return dimes


def calculate_nickels(dollars):
    nickels = 0
    if dollars < 0.05:
        return nickels
    while dollars > 0.05:
        nickels += 1
        dollars -= 0.05
    return nickels


def calculate_pennies(dollars):
    pennies = 0
    if dollars < 0.01:
        return pennies
    while dollars > 0.01:
        pennies += 1
        dollars -= 0.01
    return pennies

from cs50 import get_float
def main():
    while dollars < 0:
        try:
            dollars = get_float("Change owed: ")
        except ValueError:
            pass




