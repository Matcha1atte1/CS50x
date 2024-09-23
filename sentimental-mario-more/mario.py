while True:
        try:
            height = int(input("Height: "))
        except ValueError:

         if 1 <= height <= 8:
            break

for row in range(height):
    for space in range(height - row - 1):
        print(" ", end="")
    for column in range(row + 1):
        print("#", end="")
    print("  ", end="")
    for column in range(row + 1):
        print("#", end="")
    print()


