def main():
    line = input("input: ")
    new_line = convert(line)
    print(new_line)



def convert(text):
    text = text.replace(":)", "🙂").replace(":(", "🙁")
    return text

main()



