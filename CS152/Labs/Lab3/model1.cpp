#include<iostream>
#include<cmath>
using namespace std ;

//Use of Global Variables

double Stack[3];
int occ = 0 ;
int len=3;

void push(double x){
    if(occ < len){
        Stack[occ] = x;
        occ++;
    }
}

void pop(){
    if(occ>0){
        Stack[occ-1]=0;
        occ--;
    }
}

double top(){
    return Stack[occ-1];
}

int main(){

    push(10);
    push(11);
    pop();
    cout << top() ;
}
