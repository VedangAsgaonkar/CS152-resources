getone([X],[],X).
getone([H|T],T,H).
getone([H|T],[H|L],X):-getone(T,L,X).
%
time(a,1).
time(b,2).
time(c,5).
time(c,10).
%
app([],X,[X]).
app([H|T],X,[H|L]):-app(T,X,L).
%
max(P,Q,P):-P>=Q.
max(P,Q,Q):-P<Q.
%
state([],R,1,T,X):-17>=T.
state(L,R,1,T,X):-getone(R,S,H),time(H,N),U is N+T,app(X,[[H],r],Y),state([H|L],S,0,U,Y).
state(L,R,0,T,X):-getone(L,M,H),getone(M,N,I),time(H,A),time(I,B),max(A,B,C),U is T+C,app(X,[[H,I],l],Y),state(N,[H,I|R],1,U,Y).
%
crossings(X):-state([a,b,c,d],[],0,0,X).
