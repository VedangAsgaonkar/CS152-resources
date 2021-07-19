edge(delhi,mumbai).
edge(mumbai,chennai).
edge(chennai,kolkata).
edge(A,B):-edge(B,A).

path(A,B):-edge(A,B).
path(A,C):-edge(A,B),path(B,C).
