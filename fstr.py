username = 'caiman'
age = 37
role = 'admin'

out = '%s is %d y.o. Role: %s' % (username, age, role)
print(out)

out = '{} is {} y.o. Role: {}'.format(username, age, role)
print(out)

out = f'{username} is {age} y.o. Role: {role}'
print(out)

out = username + ' is ' + str(age) + ' y.o. Role: ' + role
print(out)


out = '{0} + {0} = {1}'.format(2, 2+2)
print(out)

out = '{0} is {1} y.o. {0} is {2}'.format(username, age, role)
print(out)
