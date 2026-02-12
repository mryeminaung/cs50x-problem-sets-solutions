from cs50 import get_int

# ask user for half pyramid's height until height is between 1 and 8
height = 0
while True:
    try:
        height = get_int("Height: ")
    except ValueError:
        continue

    if height >= 1 and height <= 8:
        break
    else:
        continue

space = height - 1
gap = 2

# loop through
for row in range(height):
    # add space before #
    for _ in range(space):
        print(" ", end="")

    # left pyramid
    for _ in range(row + 1):
        print("#", end="")

    # add gap size 2 as space before #
    for _ in range(gap):
        print(" ", end="")

    # right pyramid
    for _ in range(row + 1):
        print("#", end="")

    space -= 1
    print()
