last([X],X).
last([H|T],L):-last(T,L).
