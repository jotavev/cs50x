from cs50 import get_string
import re


def main():
    text = get_text()
    letters = how_many_letters(text)
    sentences = how_many_sentences(text)
    words = how_many_word(text)

    total = coleman_liau(letters, sentences, words)
    total = round(total)

    if total > 16:
        print("Grade 16+")
    elif total < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {total}")


def coleman_liau(letter, sentence, word):
    letter_avarage = avarage(letter, word)
    sentence_avarage = avarage(sentence, word)
    return 0.0588 * letter_avarage - 0.296 * sentence_avarage - 15.8


def how_many_word(text):
    pattern = '[a-z]+'
    text = text.replace("'", "")
    text = text.replace("-", "")
    text = re.findall(pattern, text, re.I)
    return len(text)


def avarage(letter_or_sentence, words_number):
    return letter_or_sentence / words_number * 100


def how_many_sentences(text):
    pattern = '[!.?]'
    text = re.findall(pattern, text)
    text = ''.join(text)
    return len(text)


def how_many_letters(text):
    pattern = '[a-z]+'
    text = re.findall(pattern, text, re.I)
    text = ''.join(text)
    return len(text)


def get_text():
    text = get_string("Text: ")
    return text


main()
