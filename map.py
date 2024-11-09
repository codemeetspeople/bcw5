# def increment(elem):
#     return elem + 1

# def sqrt(elem):
#     return elem ** 2

# def wrapper(function, array):
#     result = []

#     for elem in array:
#         result.append(function(elem))

#     return result

array = [1, 2, 3, 4, 5]

incremented_array = map(lambda x: x + 1, array)
squared_array = map(lambda x: x ** 2, array)

print(array)
print(list(incremented_array))
print(list(squared_array))
