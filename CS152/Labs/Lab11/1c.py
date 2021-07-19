cnt={}

def ack(m,n):
	if (m,n) in cnt :
		cnt[(m,n)] +=1
	else:
		cnt[(m,n)] = 1
	
	#ack (0,n)  --> n+1 
	#m>0:    ack (m,0) --> ack(m-1,1)                    
	#m,n>0:  ack (m,n) --> ack(m-1,ack(m,n-1))
	
	
	if(m==0):
		return n+1
	elif(m>0 and n==0):
		return ack(m-1,1)
	elif(m>0 and n>0):
		return ack(m-1,ack(m,n-1))
		
m= int(input("Enter m: "))
n= int(input("Enter n: "))
print(ack(m,n))
print(cnt)

