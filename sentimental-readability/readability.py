def count_letters(text):
    countl = 0
    for char in text:
        if char.isalpha():
            countl += 1
    return countl


def count_words(text):
    

