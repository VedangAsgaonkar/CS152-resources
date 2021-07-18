#include<iostream>
#include<cmath>
using namespace std ;

class Stack{
    private:
        //member variables
        double* ptr ;
        int length ;
        int occ ;
        double ERR;
    public:
        //Constructor
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
        //Getter methods
        int getLength(){
            return length;
        }
        int getOccupancy(){
            return occ ;
        }
        double getElementAt(int index){
            if(index<occ){
                return ptr[index];
            }
            else{
                return ERR;
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
        //Operators
        Stack operator+(Stack s2){
            int l = length + s2.getLength();
            Stack s(l);
            for(int i = 0 ; i < occ ; i++){
                s.push(ptr[i]);
            }
            for(int i = 0 ; i < s2.getOccupancy() ; i++){
                s.push(s2.getElementAt(i));
            }
            return s;
        }
        int operator[](int ind){
            if(ind<occ){
                return ptr[ind];
            }
            else{
                return ERR;
            }
        }
        Stack& operator=(Stack s2){
            delete[] ptr;
            length = s2.getLength();
            occ = s2.getOccupancy();
            ptr = new double[length];
            for(int i = 0 ; i < occ ; i++){
                ptr[i] = s2.getElementAt(i);
            }
            return *this ;
        }
        //Destructor
        ~Stack(){
            delete[] ptr;
        }
};

int main(int argc , char* argv[]){
    Stack s(3);
    s.push(10);
    s.push(11);
    s.pop();
    Stack g(4);
    g.push(12);
    g.push(19);
    Stack w(10);
    w = s+g ;
    cout << w.top() ;

}
