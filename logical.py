x = int(input())
y = int(input())

if x > 0 and y > 0:
    print('alpha')
    exit()

if x > 0 or y > 0:
    print('bravo')
    exit()

if x <= 0 and y <= 0:
    print('zulu')
