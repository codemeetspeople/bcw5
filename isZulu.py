x = int(input())
isZulu = True

if x % 2 == 0:
    print('alpha')
    isZulu = False

if x % 3 == 0:
    print('bravo')
    isZulu = False

if x % 5 == 0:
    print('charlie')
    isZulu = False

if isZulu:
    print('isZulu')