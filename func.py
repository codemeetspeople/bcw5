def fabric_function(coffee_type):
    def target_function():
        print(f'This machine makes {coffee_type}')

    return target_function

espresso_maker = fabric_function('espresso')
americano_maker = fabric_function('americano')
late_maker = fabric_function('late')

espresso_maker()
americano_maker()
late_maker()