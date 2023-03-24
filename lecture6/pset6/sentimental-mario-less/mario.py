# import get_int
from cs50 import get_int


def main():
    bricks = 1
    height = get_height()

    # loop for printer mario bricks
    for i in range(height):
        height -= 1
        printer(" ", height)
        printer("#", bricks)
        bricks += 1
        print()


# get a height value of user
def get_height():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    return height


# printer function
def printer(char, num):
    for i in range(num):
        print(f"{char}", end='')


main()
