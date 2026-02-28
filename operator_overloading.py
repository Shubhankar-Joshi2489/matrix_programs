class Number:
    def __init__(self,value):
        self.value=value
    def __repr__(self):  #String representation
        return f"{self.value}"
    def __add__(self,other):#+ overloading
        return Number(self.value+ other.value)
    def __sub__(self,other):# - overloading
        return Number(self.value- other.value)
    def __mul__(self,other):#  * overloading
        return Number(self.value* other.value)
    def __truediv__(self,other):# / overloading
        return Number(self.value// other.value)
a=Number(11)
b=Number(3)
print("a + b =", a + b)
print("a - b =", a - b)
print("a * b =", a * b)
print("a / b =", a / b)