def perm(l, ind=0):
	if(ind==len(l)-1):
		print(l)
	else:
		for i in range(ind,len(l)):
			l[ind],l[i] = l[i],l[ind]
			perm(l,ind+1)
			l[ind],l[i] = l[i],l[ind]
		
perm([1,2,3,4])
