find([A|L],1,A).
find([A|L],K,E):-1<K,M is K-1,find(L,M,E).

