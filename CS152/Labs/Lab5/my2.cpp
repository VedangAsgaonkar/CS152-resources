#include<iostream>

class A{
	public : 
		virtual void f(){
			std::cout << "A::f" << std::endl ;
		}
};

class B : public A{
	public :
		virtual void f(){
			std::cout << "B::f" << std::endl ;
		}	
};

int main( int argc, char* argv[]){
	A myA;
	B myB;
	myA.f();
	myB.f();
	A& Aref1 = myA ;
	A& Aref2 = myB ;
	Aref1.f();
	Aref2.f();

}
