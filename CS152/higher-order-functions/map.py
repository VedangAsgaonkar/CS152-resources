
l = [1,2,3,4,5,6,7]

def f (x):
	return x*x

s = {1,3,4}

r = map (f,s)
print (list(r))

print (set(l))

r = map (f,l)
print (set (r))

#exercise 1:  try to write map function on your own-- call it mymap
#ex 2: correct wrong capitalization, 3) autospell corrector for words in a list
#hEllo  is not accepted gets corrected to hello
#ex 4: data cleanup -- will remove all punctuation marks to extract words
# nice! --> nice
#why?  ---> why


#higher order function is making it possible to express higher control
#abstractions in compact form, by eliminating variables, assignments,
#increments, termination condition etc... which is done internally.
#no variables!



 
