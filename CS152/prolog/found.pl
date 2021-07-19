found(X,[X|T]).
found(X,[Y|T]):-found(X,T).

