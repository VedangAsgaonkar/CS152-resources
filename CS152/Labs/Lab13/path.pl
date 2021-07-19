edge(delhi,mumbai).
edge(mumbai,chennai).
edge(chennai,kolkata).
edge(kolkata,guwahati).

path(A,B):-edge(A,B).
path(A,C):-edge(A,B),path(B,C).
