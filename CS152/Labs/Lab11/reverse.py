def reverse(l):
	if(len(l)==1):
		return l 
	else:
		return reverse(l[1:])+[l[0]]
		
print(reverse([1,2,3,4]))
