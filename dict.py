array = {}

array['username'] = 'caiman'
array['age'] = 37
array['role'] = 'admin'
array['license'] = 'category A,B,C'
array['nationality'] = 'Ukraine'

out = '%(username)s is %(age)d y.o. Role: %(role)s' % array
print(out)
out = 'Nationality: %(nationality)s. Driver license: %(license)s' % array
print(out)

out = '{username} is {age} y.o. Role: {role}'.format(**array)
print(out)
out = 'Nationality: {nationality}. Driver license: {license}'.format(**array)
print(out)