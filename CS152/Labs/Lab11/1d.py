cnt=0
lookup=0

lookup_table = {}
# a dictionary

def ack(m,n):
	global cnt
	global lookup
	
	if (m,n) in lookup_table:
		lookup+=1
		return lookup_table[(m,n)]
	else:
		cnt += 1
		x=0
		if(m==0):
			x = n+1
		elif(m>0 and n==0):
			x = ack(m-1,1)
		elif(m>0 and n>0):
			x = ack(m-1,ack(m,n-1))
		lookup_table[(m,n)]=(x)
		return x 
		
m= int(input("Enter m: "))
n= int(input("Enter n: "))
print(ack(m,n))
print(cnt, " function calls")	
print(lookup, " table lookups")	


		
