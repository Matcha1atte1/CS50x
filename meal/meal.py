def main():

time = input("What time is it?")
hours = convert(time)
if 7 <= hours < 8:
    print("breakfast time")
elif 12 <= hours < 13:
    print("lunch time")
elif 18 <= hours < 19:
    print("dinner time")
else:
    print("not meal time")



def convert(time):
    hours, minutes = time.split(":")
    hours = float(hours)
    minutes = float(minutes)
    return hours + (minutes/60)

if __name__ == "__main__":
    main()
``
