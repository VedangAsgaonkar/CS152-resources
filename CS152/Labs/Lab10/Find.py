f_name = input("Enter file name : ")
vocab = {} 
words=[]

f = open(f_name)

for line in f:
	words = words +  line.split()

for word in words:
	if word in vocab:
		vocab[word] += 1 
	else:
		vocab[word]=1
		
print(vocab)
	
