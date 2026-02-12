from cs50 import get_float

QUARTERS = 25
DIMES = 10
NICKELS = 5
PENNIES = 1

def get_dollar():
    while True:
        dollar = get_float("Change: ")
        if dollar < 0:
            continue
        else:
            break
    return dollar

def calculate_quarters(cents):
    quarters = 0
    while (cents >= QUARTERS):
        quarters += 1
        cents = cents - QUARTERS
    return quarters

def calculate_dimes(cents):
    dimes = 0
    while (cents >= DIMES):
        dimes += 1
        cents = cents - DIMES
    return dimes

def calculate_nickels(cents):
    nickels = 0
    while (cents >= NICKELS):
        nickels += 1
        cents = cents - NICKELS
    return nickels

def calculate_pennies(cents):
    pennies = 0
    while (cents >= PENNIES):
        pennies += 1
        cents = cents - PENNIES
    return pennies

cents = int(get_dollar() * 100)

quarters = calculate_quarters(cents)
cents = cents - (quarters * QUARTERS)

dimes = calculate_dimes(cents)
cents = cents - (dimes * DIMES)

nickels = calculate_nickels(cents)
cents = cents - (nickels * NICKELS)

pennies = calculate_pennies(cents)
cents = cents - (pennies * PENNIES)

owed_coins = quarters + dimes + nickels + pennies

print(f"{owed_coins}")
