expression = input("Expression: ")
x , y, z = expression.split(" ")
if y == '+' :
    print(float(x + z))
elif y == '-' :
    print(float(x - z))
elif y == '*' :
    print(float(x * z))
elif y == '/' :
    print(float(x / z))
