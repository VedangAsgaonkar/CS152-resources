rep(X,0,[]).
rep(X,N,[X|L]):-0<N,M is N-1,rep(X,M,L).

