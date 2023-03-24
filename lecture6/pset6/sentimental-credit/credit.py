from re import match
from cs50 import get_int


def main():
    number = get_credit_number()
    if is_valid(number):
        check_flag(number)
    else:
        print("INVALID")

    # check_flag(number)

    test_valid(378282246310005)
    test_valid(371449635398431)
    test_valid(5555555555554444)
    test_valid(5105105105105100)
    test_valid(4111111111111111)
    test_valid(4012888888881881)
    test_valid(1234567890)
    print()
    test_is_even(1234567890, "even")
    test_is_even(2, "even")
    test_is_even(3, "odd")
    test_is_even(13, "odd")
    test_is_even(5, "odd")
    print()
    test_digit_sum(6, 3)
    test_digit_sum(8, 7)
    test_digit_sum(7, 5)
    test_digit_sum(5, 1)


def test_valid(number):
    if is_valid(number):
        print("OK")
    else:
        print("test_valid ERROR")


def test_is_even(number, expected):
    if is_even(number):
        print(f"even : {expected}")
    else:
        print(f"odd : {expected}")


def test_digit_sum(number, expected):
    result = digit_sum(number)
    if result == expected:
        print(f"{result} : {expected}")
    else:
        print(f"ERROR {result} : {expected}")


def get_credit_number():
    while True:
        change = get_int("Number: ")
        if change >= 0:
            break
    return change


def is_even(number):
    if (number % 2) == 0:
        return True
    else:
        return False


def is_valid(card_number):

    last_number = card_number % 10
    lenght = len(str(card_number))
    counter = 1
    even_sum = 0
    odd_sum = 0

    while(lenght > 0):
        if is_even(counter):
            even_sum += calculate(last_number)
        else:
            odd_sum += last_number

        card_number //= 10
        last_number = card_number % 10
        lenght -= 1
        counter += 1

    if (even_sum + odd_sum) % 10 == 0:
        return True
    else:
        return False


def digit_sum(number):
    number *= 2
    return (number // 10 % 10) + (number % 10)


def calculate(number):
    last_number = number % 10

    if (last_number * 2) > 9:
        return digit_sum(last_number)
    else:
        return last_number * 2


def check_flag(card_number):
    card_number = str(card_number)
    if match(r'^3[47]\d{13}$', card_number):
        print("AMEX")
    elif match(r'^4[0-9]{12}(?:[0-9]{3})?$', card_number):
        print("VISA")
    elif match(r'^5[1-5][0-9]{14}$', card_number):
        print("MASTER")
    else:
        print("INVALID")


main()
