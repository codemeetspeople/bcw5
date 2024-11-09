array = (1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1)

print(array)

print(max(array))
print(sum(array))

result = (elem + 1 for elem in array if elem % 2 == 0)

print(tuple(result))
