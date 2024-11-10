def custom_range(start, stop=None, step=1):
    if stop is None:
        stop = start
        start = 0

    if stop < start:
        raise ValueError('stop should be greater than start')

    if step <= 0:
        raise ValueError('step should be greater than 0')

    while start < stop:
        yield start
        start += step


def power_generator(base, limit):
    start = 0

    while start < limit:
        yield base ** start
        start += 1


for elem in power_generator(3, 20):
    print(elem)
