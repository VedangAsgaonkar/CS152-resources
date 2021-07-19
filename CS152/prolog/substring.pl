%is substring
substring([],X).
substring([H|T],[H|U]):-substring(T,U).
substring([H|T],[I|U]):-substring([H|T],U), H=\=I.
