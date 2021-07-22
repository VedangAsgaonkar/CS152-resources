s1 = {'abc',2,3}
s2 = {3,4,5}
s3 = s1|s2  #union operation
s4 = s1 & s2     #intersection
s5 = s1-s2         #difference
s6 = s1^s2       #symmetric difference: either in s1 or s2, but not in both

print (s1,s2)
print ('union',s3)
print ('intersection',s4)
print ('difference s1-s2',s5)
print ('difference s2-s1',s2-s1)
print ('symmetric difference',s6)
