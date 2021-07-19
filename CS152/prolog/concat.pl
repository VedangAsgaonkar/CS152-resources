concat([],L,L).
concat([H|T],L,[H|U]):-concat(T,L,U).
