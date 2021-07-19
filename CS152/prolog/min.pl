min2(P,Q,P):-P<Q.
min2(P,Q,Q):-P>=Q.
min([X],X).
min([H|T],X):-min(T,S),min2(H,S,X).

