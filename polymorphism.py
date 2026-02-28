class circle:
    def Area(self,r):
        print("Area of circle =",(3.14145*r*r))
class rectangle:
    def Area(self,l,b):
        print("Area of rectangle =",(l*b))      
class triangle:
    def Area(self,b,h):
        print("Area of triangle =",(0.5*b*h))          
def shape_area(shape,*args):
    shape.Area(*args)
circleobj=circle()
rectangleobj=rectangle()
triangleobj=triangle()

shape_area(circleobj,5)
shape_area(triangleobj,2,8)
