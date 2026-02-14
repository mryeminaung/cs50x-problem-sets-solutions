from cs50 import get_string
import math


def count_letters(text):
    # return the number of letters in text
    no_of_letters = 0

    for char in text:
        if char.isalpha():
            no_of_letters += 1

    return no_of_letters


def count_words(text):
    # return the number of words in text
    spaces = 0

    for char in text:
        if char.isspace():
            spaces += 1

    return spaces + 1 if text else 0


def count_sentences(text):
    # return the number of sentences in text
    no_of_sentences = 0

    for char in text:
        if char in [".", "!", "?"]:
            no_of_sentences += 1

    return no_of_sentences


def main():
    # prompt the user for some text
    text = get_string("Text: ")

    # count the number of letters, words, and sentences in the text
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # L => average number of letters per 100 words
    L = (letters / words) * 100

    # S => average number of sentences per 100 words
    S = (sentences / words) * 100

    # Coleman-Liau index formula
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # print the grade level
    if index < 1:
        print("Before Grade 1")
    elif 1 <= index <= 15:
        print(f"Grade {index}")
    else:
        print("Grade 16+")


if __name__ == "__main__":
    main()
