def count_letters(text):
    countl = 0
    for char in text:
        if char.isalpha():
            countl += 1
    return countl


def count_words(text):
    countw = 1
    for char in text:
        if char.isspace():
            countw += 1
    return countw

def count_sentences(text):
    counts = 0
    for char in text:
        if char == '.':
            counts += 1
        if char == '!':
            counts += 1
        if char == '?':
            counts += 1
    return counts

def main():
    text = input("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = (letters / words) * 100
    S = (sentences / words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index >= 16:
        print("Grade 16+")

    elif index < 1:
        print("Before Grade 1")

    else:
        print("Grade", index)
