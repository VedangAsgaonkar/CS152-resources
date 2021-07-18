from math import sqrt
l = range(3,1000)
p = [2]

def f(n):
	for d in p:
		if d>sqrt(n): 
			p.append(n)
			return True 
		else:
			if (n%d) == 0: 
				return False

filter(f,l)
print (p)
