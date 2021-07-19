%number of occurances
count(X,[],0).
count(X,[X|T],N):-count(X,T,M), N is 1+M.
count(X,[Y|T],N):-count(X,T,N), X=\=Y.
