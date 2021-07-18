import functools

l = [1,2,3,4,5,6,7]


def f (x,y):
	print (x,y)
	return x+y

r = functools.reduce (f,l)

print (l)
print (r)


#try to write the code for reduce function on your own
	

