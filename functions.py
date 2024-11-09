def my_sum(*args):
    return sum(args)

print(my_sum(1, 2))         # 3
print(my_sum(1, 2, 3))      # 6
print(my_sum(1, 2, 3, 4))   # 10


parameters = {
    'first_name': 'Oleksandr',
    'last_name': 'Kuznietsov',
    'age': 37,
    'education': 'University',
    'proficiency': 'Upper-intermidiate'
}

def describe_user_info(first_name=None, last_name=None, **kwargs):
    print(f'User: {first_name} {last_name}')

def describe_user_age(age=None, **kwargs):
    print(f'User age: {age}')

def describe_user_education(education=None, **kwargs):
    print(f'User education: {education}')


describe_user_info(**parameters)
describe_user_age(**parameters)
describe_user_education(**parameters)
