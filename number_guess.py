import random
best_score = None
leaderboard = []

# Get valid range


def get_valid_range():
    while True:
        try:
            min_val = int(input("Enter the minimum value for the range: "))
            max_val = int(input("Enter the maximum value for the range: "))
            if min_val <= 0 or max_val > 100 or min_val >= max_val:
                print("Please enter a valid range (0 < min < max <= 100).")
                continue
            return min_val, max_val
        except ValueError:
            print("Please enter valid integers for the range.")

 # Play one game


def play_game(name, min_val, max_val):
    nnumber = random.randint(min_val, max_val)
    attempts = 0
    print(f"Welcome {name}! Let' play a number guessing game!")
    print(
        f"I'm thinking of a number between {min_val} and {max_val}. Can you guess it?")
    while True:
        try:
            guess = int(input("Enter your guess: "))
        except ValueError:
            print("Please enter a valid integer.")
            continue
        if guess < min_val or guess > max_val:
            print("Your guess is out of bounds.")
            print(f"Please enter a number between {min_val} and {max_val}.")
            continue
        attempts += 1
        if guess < nnumber:
            print("Too low! Try again.")
        elif guess > nnumber:
            print("Too high! Try again.")
        else:
            print(
                f"Congratulations {name}! You've guessed the number {nnumber} in {attempts} attempts!")
            return attempts


# Leaderboard functions
def update_leaderboard(name, attemps):
    leaderboard.append((name, attemps))
    leaderboard.sort(key=lambda x: x[1])


def display_leaderboard():
    print("\nLeaderboard:")
    for i, (name, attempts) in enumerate(leaderboard[:5], start=1):
        print(f"{i}. {name} - {attempts} attempts")


# Main function
while True:
    name = input("Enter your name : ")

    min_val, max_val = get_valid_range()

    attempts = play_game(name, min_val, max_val)

    if best_score is None or attempts < best_score:
        best_score = attempts
        print(f"New best score: {best_score} attempts!")

    update_leaderboard(name, attempts)
    display_leaderboard()

    play_again = input("Do you want to play again? (yes/no): ").strip().lower()
    if play_again != 'yes':
        print("Thanks for playing! Goodbye!")
        break
