
def play(answer, guess):
    wrong = 0
    correct = 0
    guessed = set()
    for c in guess:
        if c in guessed:
            continue
        if c not in answer:
            wrong += 1
        else:
            correct += answer.count(c)
        guessed.add(c)
        if correct >= len(answer):
            break

    # print(correct, len(answer))
    assert correct <= len(answer)
    if wrong > 6:
        print("You lose.")
    elif correct == len(answer):
        print("You win.")
    else:
        print("You chickened out.")


def main():
    round = input()
    while int(round) > 0:
        answer = input()
        guess = input()
        print("Round", round)
        play(answer, guess)
        round = input()


if __name__ == '__main__':
    main()
