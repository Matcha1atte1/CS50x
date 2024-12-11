expression = input("Expression: ")
x , y, z = expression.split(" ")
x = float(x)
y = float(y)
if y == '+' :
    print(x + z)
elif y == '-' :
    print(x - z)
elif y == '*' :
    print(x * z)
elif y == '/' :
    print(x / z)
