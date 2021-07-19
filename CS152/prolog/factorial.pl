factorial(0,1).
factorial(N,F):-M is N-1, M>=0, factorial(M,E), F is N*E, E>=1.
