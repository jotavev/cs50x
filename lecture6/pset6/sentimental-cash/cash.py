from cs50 import get_float


def main():
    change = get_change()
    result = total_coin(change)
    print(result)


def get_change():
    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break
    return change


def cents_to_int(n):
    return int(n * 100)


def calculate_how_many_coins_give(change, coin_value):
    count = 0
    while change >= coin_value:
        change -= coin_value
        count += 1
    return count


def total_coin(change):
    coins_list = [25, 10, 5, 1]
    total_coins = 0

    change = cents_to_int(change)

    for coin in coins_list:
        value = calculate_how_many_coins_give(change, coin)
        total_coins += value
        change -= value * coin

    return total_coins


main()
