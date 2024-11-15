import math

class Point:
    # __slots__ = ('x', 'y')

    def __init__(self, x=0.0, y=0.0):
        # if not isinstance(x, (int, float)):
        #     message = (
        #         f'Wrong argument type. Expected int or float, '
        #         f'got {type(x)} instead.'
        #     )
        #     raise TypeError(message)
        
        self._x = float(x)
        self._y = float(y)

    @property
    def x(self):
        return self._x

    @x.setter
    def x(self, value):
        self._x = float(value)

    @property
    def y(self):
        return self._y

    @y.setter
    def y(self, value):
        self._y = float(value)

    def __str__(self):
        return f'({self.x}, {self.y})'

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return NotImplemented
        return self.x == other.x and self.y == other.y

    def __ne__(self, other):
        if not isinstance(other, self.__class__):
            return NotImplemented
        return not self == other

    def __add__(self, other):
        if not isinstance(other, self.__class__):
            return NotImplemented
        return self.__class__(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        if not isinstance(other, self.__class__):
            return NotImplemented
        return self.__class__(self.x - other.x, self.y - other.y)

    def distance(self, other):
        if not isinstance(other, self.__class__):
            raise ValueError()

        return math.hypot(self.x - other.x, self.y - other.y)


class ColorPoint(Point):
    def __init__(self, x=0.0, y=0.0, color='Black'):
        super().__init__(x, y)
        self._color = str(color)

    @property
    def color(self):
        return self._color

    @color.setter
    def color(self, value):
        self._color = str(value)

    def __str__(self):
        return f'({self.x}, {self.y}, {self.color})'

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return NotImplemented
        return super().__eq__(other) and self.color == other.color



a = ColorPoint()
b = ColorPoint(0.0, 4.0, 'Black')

print(a)

