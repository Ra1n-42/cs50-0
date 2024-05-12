


while True:
    height_input = input("Height: ")


    if height_input.isdigit():
        height = int(height_input)

        if 1 <= height <= 8:
            break

space = height

for i in range(1, height+1):
    print(" " * (space - i) + "#" * i)
