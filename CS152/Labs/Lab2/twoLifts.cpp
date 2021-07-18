#include<iostream>
#include<cmath>
using namespace std ;

class Floor{
    private :
        bool up1;
        bool down1;

    public :
        Floor(){
            up1 = false ;
            down1 = false ;
        }

        void up(){
            up1 = true ;
        }

        void down(){
            down1 = true ;
        }

        void notUp(){
            up1 = false ;
        }

        void notDown(){
            down1 = false ;
        }
};

class Lift{
    private :
        int currentFloor;
    public :
        void initialize(int floor){
            currentFloor = floor;
        }
        void goTo(int floor){
            currentFloor = floor ;
        }

};

int main(){
    Floor floor[7] ;
    Lift lift[2] ;

    lift[0].initialize(0);
    lift[1].initialize(6);

    floor[2].up();
    floor[4].down();

    lift[0].goTo(2) ;
    cout << "LIFT 1 REACHED FLOOR 2" <<  endl ;
    floor[2].notUp() ;
    cout << "2 PASSENGERS ENTERED LIFT 1" << endl ;
    cout << "PASSENGERS CLICK FLOORS 1 AND 3" << endl;

    lift[1].goTo(4);
    cout << "LIFT 2 REACHED FLOOR 4" << endl ;
    floor[4].notDown() ;
    cout << "1 PASSENGER ENTERED LIFT 2" << endl ;
    cout << "PASSENGER CLICKED FLOOR 0" << endl ;

    lift[0].goTo(3) ;
    cout << "LIFT 1 REACHED FLOOR 3" << endl ;
    cout << "1 PASSENGER EXITED" << endl ;

    lift[1].goTo(0) ;
    cout << "LIFT 2 REACHED FLOOR 0" << endl ;
    cout << "1 PASSENGER EXITED" << endl;

    lift[0].goTo(1) ;
    cout << "LIFT 1 REACHED FLOOR 1" << endl ;
    cout << "1 PASSENGER EXITED" << endl ;


}
