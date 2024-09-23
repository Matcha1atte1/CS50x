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
    while True:
        dollars = get_float("Change owed: ")
        try:
            dollars = get_float("Change owed: ")
        except ValueError:
            pass
    quarters = calculate_quarters(dollars)
    dollars = dollars - (quarters * 0.25)

    dimes = calculate_dimes(dollars)
    dollars = dollars - (dimes * 0.10)

    nickels = calculate_nickels(dollars)
    dollars = dollars - (nickels * 0.05)

    pennies = calculate_pennies(dollars)
    dollars = dollars - (pennies * 0.01)

    coins = quarters + dimes + nickels + pennies

    print(coins)

main()





