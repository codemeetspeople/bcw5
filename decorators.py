def add_pargraph_tag(tag):
    def outer_function(func):
        def inner_function(*args, **kwargs):
            content = func(*args, **kwargs)

            return f'<{tag}>{content}</{tag}>'
        return inner_function
    return outer_function


@add_pargraph_tag('p')
def hello(username, language='Python'):
    return f'Hello, {username}! Welcome to your {language} journey!'

@add_pargraph_tag('div')
def welcome():
    return 'Welcome!'


print(hello('caiman', language='Java'))
print(welcome())
