#We may specialize a function by using partial evaluation or returning lambda
#
#
#
#
#Partial evaluation
#
from functools import partial

def f(y,x):
    return x**y 
  
square = partial(f,2)
cube = partial(f,3)

print(square(4))
#prints 16

print(cube(11))
#prints 1331

print(type(square))
#<class 'functools.partial'>

def g(x,y):
    print(x+y)
    
func = partial(g,2)

func(11)
#print happens here. Control doesn't enter body during partial evaluation
#
#
#
#
#Also note that the following:

def h(x):
    return x+x

q = partial(h,10)
print(q)
#prints <functools partial ... >
print(q())
#prints 20

#Currying in python has to be done using partial
#
#
#
#The specialization can also be done using lambda
#
def h(x):
    return lambda y : y**x
    
square1 = h(2)
cube1 = h(3)

print(square1(4))
#prints 16

print(cube1(11))
#prints 1331

print(type(square))
#<class 'function'>


