with open('task.in', 'r') as f:
    data = f.read().strip()

data = map(lambda x: int(x), data.split(' '))

with open('task.out', 'w') as f:
    f.write(str(sum(data)))


