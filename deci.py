

import random


def roll_deci():
    return random.randint(1, 6)


roll_count = 0


while True:
    user_type = input("Roll the dice?(y/n): ").lower()
    if user_type == "y":
        try:
            num_dice = int(input("How many dice do you want to roll?: "))

            if num_dice <= 0:
                print("Please enter a positive number.")
                continue

            print("Rolling...")
            result = []

            for _ in range(num_dice):
                result.append(roll_deci())

            roll_count += 1

            print("You rolled:", result)
            print("Total:", sum(result))
            print("You have rolled the dice",
                  roll_count, "time(s) this session ")
        except ValueError:
            print("Please enter a valid number.")

    elif user_type == "n":
        print("Not rolling.Quit")
        print("You rolled the dice", roll_count, "time(s) in total")
        break
    else:
        print("Invalid input")
