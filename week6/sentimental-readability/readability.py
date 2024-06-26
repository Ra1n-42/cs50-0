import math

def count_letters(text):
    letter_count = 0
    for char in text:
        if char.isalpha():
            letter_count += 1
    return letter_count

def count_words(text):
    words_count = text.count(' ') + 1
    return words_count

def count_sentences(text):
    punctuation_count = 0
    for char in text:
        if char in ['.', '!', '?']:
            punctuation_count += 1
    return punctuation_count

def coleman_liau_index(L, S):
    return 0.0588 * L - 0.296 * S - 15.8

def rounding_up(x):
    fractional_part = x - math.floor(x)
    if fractional_part >= 0.5:
        return math.ceil(x)
    else:
        return math.floor(x)

text = input("Text: ")

# Count the number of letters, words, and sentences in the text
letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

# print(f"letters: {letters} words: {words} sentences: {sentences}")

L = (letters / words) * 100
S = (sentences / words) * 100

# Compute the Coleman-Liau index
index = coleman_liau_index(L, S)
# print(f"L: {L} S: {S} Index: {index}")
# Rounding
grade = rounding_up(index)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade", int(grade))
