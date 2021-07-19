def cross(l1,l2):
	
	if(len(l1)==1 and len(l2)==1):
		return [(l1,l2)]
	elif(len(l1)==1):
		return [(l1,[l2[0]])]+cross(l1,l2[1:])	
	else:
		return cross([l1[0]],l2)+cross(l1[1:],l2)
		
print(cross([1,2],[3,4]))
