len([],0).
len([H|T],N):-len(T,M), N is 1+M.
