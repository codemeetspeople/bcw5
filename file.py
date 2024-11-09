f = open('task.in', 'r')
data = f.read()
f.close()

data = data.strip()
data = data.split(' ')
data = [int(elem) for elem in data]

f = open('task.out', 'w')
f.write(str(sum(data)))
f.close()

