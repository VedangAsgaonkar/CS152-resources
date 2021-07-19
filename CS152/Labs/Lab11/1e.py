
cnt=0
lookups = 0

table = {} 


def fibonacci(n):
	global cnt
	global lookups 
	if n in table:
		lookups += 1
		return table[n]
	else:
		x = 0 
		if n==0 :
			x=0
		elif n==1:
			x=1
		else :
			x=fibonacci(n-1)+fibonacci(n-2)
		cnt += 1
		table[n] = x 
		return x
		
n  = int(input("Enter n : "))
print(fibonacci(n))
print(cnt)
print(lookups)
