def sub(l1,l2):
	if(len(l1)==0):
		return True
	elif(len(l2)==0):
		return False
	else:
		if(l1==l2[0:len(l1)]):
			return True
		else:
			return sub(l1,l2[1:])

print(sub([4],[2,34,5,1]))
			
