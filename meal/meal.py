def main():

time = input("What time is it?")
hours = convert(time)
if hours in range[7,8]:
    


def convert(time):
    hours, minutes = time.split(":")
    return float(hours + (minutes/60))

