class Integer:
    def __init__(self, value=0):
        self.value = int(value)

    def __str__(self):
        return str(self.value)

    def __add__(self, other):
        if not isinstance(other, self.__class__):
            return NotImplemented
        return self.__class__(self.value + other.value)


class Float:
    def __init__(self, value=0):
        self.value = float(value)

    def __str__(self):
        return str(self.value)

    def __add__(self, other):
        if not isinstance(other, self.__class__):
            return NotImplemented
        return self.__class__(self.value + other.value)

    def __radd__(self, other):
        if isinstance(other, Integer):
            return self.__class__(self.value + other.value)
        else:
            return NotImplemented



a = Integer(5)
b = Float(10)

print(a + b)
