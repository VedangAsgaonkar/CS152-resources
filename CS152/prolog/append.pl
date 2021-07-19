%append
app(X,[],[X]).
app(X,[H|T],[H|L]):-app(X,T,L).
