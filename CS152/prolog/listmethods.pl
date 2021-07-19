%membership
ismember(X,[X|T]).
ismember(X,[Y|T]):-X=\=Y, ismember(X,T).

%number of occurances
count(X,[],0).
count(X,[X|T],N):-count(X,T,M),N is M+1 .
count(X,[Y|T],N):-count(X,T,N), X=\=Y.

%length of list
len([],0).
len([H|T],L):-len(T,M), L is 1+M.

%concatenation
concat([],L,L).
concat([H|T],L,[H|U]):-concat(T,L,U).

%deletion
del(X,[X|T],T).
del(X,[Y|T],[Y|L]):-del(X,T,L).

%append
app(X,[],[X]).
app(X,[H|T],[H|L]):-app(X,T,L).

%reverse
rev([X],[X]).
rev([H|T],L):-rev(T,S), app(H,S,L).

%palindrome check
ispalindrome(X):-rev(X,X).

%insert
insert(X,L,M):-del(X,M,L).

%permutations
permute([X],[X]).
permute([H|T],X):-permute(T,L), del(H,X,L).

%lshift
lshift([X],[X]).
lshift([H|T],L):-app(H,T,L).

%is substring
substring([],X).
substring([H|T],[H|U]):-substring(T,U).
substring([H|T],[I|U]):-substring([H|T],U), H=\=I.

%is subsequence
subsequence([],X).
subsequence([H|T],[H|U]):-subsequence(T,U).
subsequence(L,[H|U]):-subsequence(L,U).









