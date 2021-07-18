#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std ;

class Dice{

    public : int toss(int seed){
        srand(seed) ;
        return rand() ;
    }
};

int main(int argc , char *argv[]){
    int N = 0 ;
    int f = 10 ;
    for(int i = 0 ; argv[1][i] != '\0' ; i++){
        N = N*f + argv[1][i] - '0' ;
    }

    int outputs[6] ;
    for(int i = 0 ; i< 6 ; i++){
        outputs[i] = 0 ;
    }
    int temp ;
    Dice d  ;
    for(int i= 0 ; i < N ; i++){
        temp = (d.toss(i)) ;
        outputs[temp%6] ++ ;

    }
    for(int i = 0 ; i< 6 ; i++){
        cout << i+1 << " : " << outputs[i] << endl ;
    }

}
