greeting = input("Greeting: ").lower().strip()
if "hello" in greeting:
    print("$0")
elif "hey" in greeting or "hi" in greeting or "how" in greeting:
    print("$20")
else:
    print("$100")
