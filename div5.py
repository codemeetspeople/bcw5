minimum = int(input())
maximum = int(input())
divisor = 5

multiple = minimum - minimum % divisor
if multiple < minimum:
    multiple += divisor

while multiple <= maximum:
    print(multiple)
    multiple += divisor
