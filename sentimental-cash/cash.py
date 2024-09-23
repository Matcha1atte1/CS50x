def calculate_quarters(cents):
    quarters = 0
    if cents < 25:
        return quarters
    while cents >= 25:
        quarters += 1
        cents -= 25
    return quarters


def calculate_dimes(cents):
    dimes = 0
    if cents < 10:
        return dimes
    while cents >= 10:
        dimes += 1
        cents -= 10
    return dimes


def calculate_nickels(cents): 
    nickels = 0
    if cents < 5:
        return nickels
    while cents > 5:
        nickels += 1
        cents -= 5
    return nickels


def calculate_pennies(cents):
    pennies = 0
    if cents < 1:
        return pennies
    while cents > 1:
        pennies += 1
        cents -= 1
    return pennies


from cs50 import get_float

def main():
    while True:
        try:
            dollars = get_float("Change owed: ")
            if dollars >= 0:
                break
        except ValueError:
            pass
    cents = dollars * 100
    quarters = calculate_quarters(cents)
    cents = cents - (quarters * 25)

    dimes = calculate_dimes(cents)
    cents = cents - (dimes * 10)

    nickels = calculate_nickels(cents)
    cents = cents - (nickels * 5)

    pennies = calculate_pennies(cents)
    cents = cents - (pennies * 1)

    coins = quarters + dimes + nickels + pennies

    print(coins)

main()





