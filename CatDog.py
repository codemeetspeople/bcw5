class Animal:
    def eat(self):
        print(f'{self.__class__.__name__} eats everything...')


class Cat(Animal):
    def eat(self):
        print(f'{self.__class__.__name__} eats fish...')

    def meow(self):
        print(f'{self.__class__.__name__} say meow...')


class Dog(Animal):
    def eat(self):
        print(f'{self.__class__.__name__} eats meat...')

    def bark(self):
        print(f'{self.__class__.__name__} say woof...')


class CatDog(Cat, Dog):
    def eat(self):
        print(f'{self.__class__.__name__} eats meat and fish...')


cd = CatDog()

cd.meow()
cd.bark()
cd.eat()
super(CatDog, cd).eat()
