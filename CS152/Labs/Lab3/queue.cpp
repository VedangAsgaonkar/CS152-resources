#include<iostream>
#include<cmath>
using namespace std;

class Queue{ //creates a queue of integers
    private : int length; //length of queue
    private : double* q; //pointer to the array of elements storing the queue
    private : int occ; //number of places occupied
    private : double ERR = -1e5 ;

    public : Queue(int l){ //constructor
        length = l ;
        q = new double[l] ; //queue is stored in heap
        occ = 0;
    }

    public : Queue(int l , double* arr){ //constructor
        length = l ;
        q = new double[l] ;
        for(int i = 0 ; i<l ; i++){
            q[i] = arr[i] ;
        }
        occ = l;
    }

    public : void append(double d){ //append to the queue
        if(occ<length){
            q[occ]=d;
            occ++;
        }

    }

    public : double exit(){ //first element leaves
        if(occ>0){
            double d = q[0] ;
            for(int i=0 ; i<occ-1 ; i++ ){
                q[i] = q[i+1] ;
            }
            occ-- ;
            return d ;
        }
        else{
            return ERR;
        }
    }

    public : ~Queue(){
        delete[] q;
    }
};


int main(){
    Queue a(2) ;
    double arr[] = {1,2};
    Queue b(2,arr);

    cout << b.exit() ;
}

