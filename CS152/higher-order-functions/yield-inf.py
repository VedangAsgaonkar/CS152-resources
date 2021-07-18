def traditional-counter (x): // random no. generator 
	l = []
	while(True):
		l.append(x)
		x = x +1
	return l #unreachable statement!

def counter (x):  #yielding counter, solves our problem!
	while(True): #infinite loop
		yield (x)
		x = x +1

for e in counter(5):
	print ('received value', e)

#g = counter (5) 
#print (g)  # l is a generator, not unfolded if elements not needed

# ex: write a random no. generator using yield




This will make a generator on the spot after "in" . The internal functioning stops at yield. The yield is carried
out only when the iterator "e" calls for it using "in". Also next time counter() is called its a new generator object.
So if we wish to store the state of a generator, store it in a variable x = counter(5)


