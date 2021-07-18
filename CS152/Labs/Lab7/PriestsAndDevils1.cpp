#include <FL/Fl.H> 
#include <FL/Fl_Window.H> 
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Button.H>
#include<iostream>
using namespace std ;



class Shape : public Fl_Widget  {
  	protected:
	int x, y, w, h;
	public:
		Shape (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
			this->x=x; this->y=y;
			this->w=w; this->h=h;
		}
		virtual void wipe()=0;
		virtual void refresh(int dx, int dy)=0;
			
		
};

class MyRectangle : public Shape {
 public:
   int c ;
   MyRectangle (int x,int y,int w, int h, int cl) : Shape (x,y,w,h) { c = cl ;}
   virtual void draw() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,c);
   }

   virtual void wipe() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_GRAY);
   }

   virtual void refresh(int dx, int dy) {
	wipe();
	x=x+dx;y=y+dy;
	resize(x,y,w,h);
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,c);
	
   }
   
   virtual void moveTo(int x1 , int y1 ){
   wipe();
	x=x1;y=y1;
	resize(x,y,w,h);
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,c);
   };

};

class being : public MyRectangle{ 

private: //changed access specifier
	
	int* boatLoc ;
	bool* s1 ;
	bool* s2 ;
public:
	int c ;
	bool in ;
	being (int x,int y,int w, int h, int cl) : MyRectangle ( x, y, w,  h,  cl) {c = 0 ; in=false ;}
	
	void getParams( int* bl , bool* S1 , bool* S2 ){
		boatLoc = bl ;
		s1 = S1 ;
		s2 = S2 ;	
	}
	
	
	virtual int handle(int e) { //boatLoc , s1 , s2
			if (e==FL_PUSH) {
				if(c==*boatLoc){
					if(!(*s1)){
						if(c==0){
							moveTo( 220 , 750 );	
						}
						else{
							moveTo( 1120 , 750 );
						}
						*s1=true ;	
						in=true;
					}
					else if(!(*s2)){
						if(c==0){
							moveTo( 280 , 750 );	
						}
						else{
							moveTo( 1180 , 750 );
						}
						*s2=true ;	
						in = true;
					}
				}
			}
		return 1 ;
	}
};






class myButton : public Fl_Button{
	private: //changed access specifier
		
		MyRectangle* boat ;
		int* boatLoc ;
		bool* s1 ;
		bool* s2 ;
		int* lp ;
		int* ld ;
		int* rp ;
		int* rd ;
		being** p ;
		being** d ;
		Fl_Window** win ;
		
	public:
		myButton( int x , int y  , int w , int h , char* lbl) : Fl_Button(x,y,w,h,lbl){
			
		}
		
		void getParams( MyRectangle* boat1 , int* bl , bool* S1, bool* S2, int* lp1 , int* ld1 , int* rp1 , int* rd1, being** p1 , being** d1 , Fl_Window** win1){
			boat = boat1 ;
			boatLoc = bl ;
			s1 = S1 ;
			s2 = S2 ;
			lp = lp1 ;
			ld = ld1 ;
			rp = rp1 ;
			rd = rd1 ;	
			p = p1 ;
			d = d1 ;	
			win = win1 ;
		}
		
		virtual int handle(int e){ //boatLoc , s1 , s2 , lp , ld , rp , rd , p , d
			
			if( e == FL_PUSH){
			
				if( *s1 || *s2 ){
			
					if(	*boatLoc == 0 ){					
						*boatLoc= 1;
						boat->refresh(900,0);
						
						
						for(int i = 0 ; i < 3 ; i++){
							if(p[i]->in){
								p[i]->moveTo(1200+10+20*i, 750);
								p[i]->in = false ;	
								p[i]->c = 1 ;
								(*lp)--;
								(*rp)++;
							}
							if(d[i]->in){
								d[i]->moveTo(1200+100+20*i, 750);
								d[i]->in = false ;	
								d[i]->c=1 ;
								(*ld)--;
								(*rd)++;
							}
						}
						*s1=false;
						*s2=false;						
					}
					else if( *boatLoc ==1 ){
						*boatLoc = 0 ;
						boat->refresh(-900,0);
						for(int i = 0 ; i < 3 ; i++){
							if(p[i]->in){
								p[i]->moveTo(10+20*i, 750);
								p[i]->in = false ;	
								p[i]->c = 0 ;
								(*rp)--;
								(*lp)++;
							}
							if(d[i]->in){
								d[i]->moveTo(100+20*i, 750);
								d[i]->in = false ;	
								d[i]->c = 0 ;
								(*rd)--;
								(*ld)++;
							}
						}
						*s1=false;
						*s2=false;
					}
					
					/*if((*rp>0 && *rd>*rp) || (*lp>0 && *ld>*lp)){
						Fl::wait(5);
						throw 0 ;
					}
					else if(*rp==3 && *rd==3){
						Fl::wait(5);
						throw 1;
					}*/
					
					if((*rp>0 && *rd>*rp) || (*lp>0 && *ld>*lp)){
						Fl::wait(1);
						(*win)->hide();
						cout << "You loose. Try again." << endl ;
					}
					else if(*rp==3 && *rd==3){
						Fl::wait(1);
						(*win)->hide();
						cout << "You win" << endl ;
					}
				
				
				
			}
			
			}
			
			return 1;		
		}

};


int main(){
	//try{
	
	int boatLoc = 0 ;
	bool s1 = false ;
	bool s2 = false ;
	int lp = 3 ;
	int ld = 3 ;
	int rp = 0 ;
	int rd = 0 ;

	Fl_Window* window ;
	window =  new Fl_Window(1400,1000,"Priests And Devils");	
	MyRectangle* left = new MyRectangle(0,800,200,200,140);
	MyRectangle* right = new MyRectangle(1200,800,200,200,140);
	MyRectangle* river = new MyRectangle(200,800,1000,200,FL_BLUE);
	
	being* p[3] ;
	being* d[3] ;
	
	for(int i = 0 ; i < 3 ; i++){
		p[i] = new being( 10+20*i , 750 , 10 , 50 , FL_GREEN );
		d[i] = new being( 100+20*i , 750 , 10 , 50 , FL_RED );
		p[i]->getParams(&boatLoc,&s1,&s2) ;
		d[i]->getParams(&boatLoc,&s1,&s2) ;
	}
	
	MyRectangle* boat = new MyRectangle(200,780,100,20,30);
	
	char str[2] = {'G' , 'o' } ;
	
	myButton go(100,100,100,100,str);	
	go.getParams( boat , &boatLoc , &s1 , &s2 , &lp , &ld , &rp , &rd , p , d , &window);	
	
		
	window->end();
	window->show();	
	Fl::run();	
	//}
	/*catch(int x){
		if(x==0){
			cout << "YOU LOOSE. TRY AGAIN." << endl ;
		}
		else{
			cout << "YOU WIN" << endl ;
		}
	
	}*/
	

}
