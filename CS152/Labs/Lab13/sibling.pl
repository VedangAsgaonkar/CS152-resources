parent(harry,tom).
parent(sally,tom).
parent(harry,june).
parent(sally,june).
parent(harry,john).
parent(jenny,john).
sibling(X,Y):-parent(X,Z),parent(Y,Z),!.
