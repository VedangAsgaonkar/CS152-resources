%append
app(X,[],[X]).
app(X,[H|T],[H|L]):-app(X,T,L).

%reverse
rev([X],[X]).
rev([H|T],L):-rev(T,S), app(H,S,L).

%palindrome check
ispalindrome(X):-rev(X,X).
