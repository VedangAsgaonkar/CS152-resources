#include<iostream>
using namespace std;
class A {
  public:
	virtual void f() {cout<<"A::f\n";}
	virtual void g() { cout << "A::g\n"; A::f() ;} 
	virtual void h() {cout << "A::h\n" ; f() ;}
};

class C : public A {
 public:
	virtual void f(){cout << "C::f\n";}
         virtual void k() {cout << "C::k\n"; g(); h() ;}
};
int main (int argc, char *argv[]) {
 A *ap;  
 C *cp;
 
   ap = new A();
   ap->f(); ap->g();
   delete ap;
   cp = new C();
   cp->f(); cp->g(); cp->h(); cp->k();
   ap = cp;
   ap->f(); ap->g(); ap->h();
   
}


