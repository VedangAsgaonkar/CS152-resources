#include <iostream>
#include<cmath>
using namespace std;

class Gate {

 public:
	bool fire (int i, int j);

};

class AND : public Gate{
    public :
    bool fire (int i , int j){
        return i*j ;
    }
};

class OR : public Gate{
    public :
    bool fire(int i , int j){
        return abs(i)+abs(j) ;
    }
};

int main (int argc, char *argv[]) {
    AND a ;
    cout << a.fire(1,2) << endl ;
    OR o;
    cout << o.fire(1,2) << endl;

}
