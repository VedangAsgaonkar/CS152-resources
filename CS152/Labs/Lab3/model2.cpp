#include<iostream>
#include<cmath>
using namespace std ;

//passing Stack to functions

void push(double* Stack , int x , int& occ , int& len){
    if(occ < len){
        Stack[occ] = x;
        occ++;
    }
}

void pop(double* Stack , int& occ ){
    if(occ>0){
        Stack[occ-1]=0;
        occ--;
    }
}

double top(double* Stack, int& occ){
    return Stack[occ-1];
}

int main(){
    double Stack[3];
    double anotherStack[4];
    int occ = 0 ;
    int len=3;
    int anotherocc = 0;
    int anotherlen = 4 ;
    push(Stack,10,occ,len);
    push(Stack,11,occ,len);
    pop(Stack,occ);
    cout << top(Stack,occ);
    push(anotherStack,20,anotherocc,anotherlen);
    cout << top(anotherStack,anotherocc);
}
