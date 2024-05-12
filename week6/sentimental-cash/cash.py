import cs50

def calculate_quarters(cents):
    __quarters = 25
    if cents == __quarters: return 1

    quaters = 0
    while cents >= __quarters:
        quaters += 1
        cents -= __quarters
    return quaters

def calculate_dimes(cents):
    __dimes = 10
    if cents == __dimes: return 1

    dimes = 0
    while cents >= __dimes:
        dimes += 1
        cents -= __dimes
    return dimes

def calculate_nickels(cents):
    __nickels = 5
    if cents == __nickels: return 1

    nickels = 0
    while cents >= __nickels:
        nickels += 1
        cents -= __nickels
    return nickels

def calculate_pennies(cents):
    pennies = 0
    while cents >= 1:
        pennies += 1
        cents -= 1
    return pennies

while True:
    cents = cs50.get_float("Change: ")

