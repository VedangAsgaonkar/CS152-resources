#include<iostream>
#include<FL/Fl.H>
#include<FL/Fl_Window.H>
#include<FL/Fl_Button.H>


class myButton : public Fl_Button{
	public:
		myButton* rn ;
		myButton* ln;
		myButton* bn;
		myButton* tn;
		bool isBlank ;
		
		myButton( int x , int y , int h , int w , char* lbl ) : Fl_Button(x,y,h,w,lbl){
			
			isBlank = false ;
		}
		
		int handle(int e){
			if(e == FL_PUSH ){
				if( rn!=NULL && rn->isBlank ){
					rn->label(this->label());
					this->label("");
					rn->isBlank = false ;
					isBlank = true ;	
				}
				else if( ln!=NULL && ln->isBlank ){
					ln->label(this->label());
					this->label("");
					ln->isBlank = false ;
					isBlank = true ;	
				}
				else if( tn!=NULL && tn->isBlank ){
					tn->label(this->label());
					this->label("");
					tn->isBlank = false ;
					isBlank = true ;	
				}
				else if( bn!=NULL && bn->isBlank ){
					bn->label(this->label());
					this->label("");
					bn->isBlank = false ;
					isBlank = true ;	
				}
			}
			return 1 ;
		}
		
};

char* intToChar(int n){
	char* ch = new char[sizeof(int)];
	sprintf(ch , "%d" , n);
	return ch ;

}


int main(){

	Fl_Window* window ;
	window = new Fl_Window(600,600,"demo");
	myButton* buttons[4][4] ;
	int x ;
	
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j<4 ; j++){
		
			
			
				int n = 4*j + i +1 ;
				if(n==16){	
					char ch[1] = {'\0'} ;
					buttons[i][j]= new myButton( 100*i + 100 , 100*j +100 , 100 , 100 , ch);
				}
				else{
					char* ch = intToChar(n);
					buttons[i][j]= new myButton( 100*i + 100 , 100*j +100 , 100 , 100 , ch);
				}		
			
			
		}
	}
	buttons[3][3]->isBlank = true ;
	
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j<4 ; j++){
			if(i==0){
				buttons[i][j]->ln = NULL;
			}
			else{
				buttons[i][j]->ln = buttons[i-1][j];
			}
			
			if(i==3){
				buttons[i][j]->rn = NULL;
			}
			else{
				buttons[i][j]->rn = buttons[i+1][j];
			}
			
			if(j==0){
				buttons[i][j]->tn = NULL;
			}
			else{
				buttons[i][j]->tn = buttons[i][j-1];
			}
			
			if(j==3){
				buttons[i][j]->bn = NULL;
			}
			else{
				buttons[i][j]->bn = buttons[i][j+1];
			}
			
		}
	}
	
	
	window->end();
	window->show();
	return(Fl::run());
	
	
	
	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

