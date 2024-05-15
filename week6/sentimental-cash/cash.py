import cs50

def calculate_coins(cents, coin_value):
    coins = 0
    while cents >= coin_value:
        coins += 1
        cents -= coin_value
    return coins

while True:
    dollars = cs50.get_float("Change: ")

    if dollars is not None and dollars > 0:
        cents = round(dollars * 100)  # Convert dollars to cents
        quarters = calculate_coins(cents, 25)
        cents -= quarters * 25

        dimes = calculate_coins(cents, 10)
        cents -= dimes * 10

        nickels = calculate_coins(cents, 5)
        cents -= nickels * 5

        pennies = cents

        total_coins = quarters + dimes + nickels + pennies
        print(total_coins)
        break
