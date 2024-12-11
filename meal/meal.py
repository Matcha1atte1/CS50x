def main():

time = input("What time is it?")
convert(time)
if


def convert(time):
    hours, minutes = time.split(":")
    return float(hours + (minutes/60))

