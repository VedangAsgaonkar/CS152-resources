sum([],0).
sum([H|T],S):-sum(T,L), S is L+H.
