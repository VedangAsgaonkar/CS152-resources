def counter (x):
	while(x>0):
		print ('returning a val..will resume later!')
		yield (x)
		print ('resuming...')
		x = x -1

for e in counter(5):
	print ('received value', e)



#g = counter (5) 
#print (g)  # l is a generator, not unfolded if elements not needed


