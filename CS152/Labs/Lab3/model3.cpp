#include<iostream>
#include<cmath>
using namespace std ;

//using struct

struct Stack{
    double* ptr ;
    int length ;
    int occ ;
    double ERR;
    Stack(){
            ptr = NULL ;
            length = 0 ;
            occ = 0 ;
        }
        Stack(int l){
            length = l ;
            ptr = new double[length];
            occ = 0 ;
            ERR = -1e6;
        }
        //Setter methods
        bool push(double d){
            if(occ<length){
                ptr[occ]=d;
                occ++;
                return true;
            }
            else{
                return false ;
            }
        }
        bool pop(){
            if(occ>0){
                ptr[occ-1] = 0;
                occ--;
                return true;
            }
            else{
                return false;
            }
        }
        double top(){
            if(occ>0){
                return ptr[occ-1];
            }
            else{
                return ERR;
            }
        }
        ~Stack(){
            delete[] ptr;
        }
};

int main(){
    Stack s(3);
    s.push(10);
    s.push(11);
    s.pop();
    cout << s.top() ;

}
