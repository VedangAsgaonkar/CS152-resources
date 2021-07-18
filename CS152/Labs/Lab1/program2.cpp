#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
using namespace std ;

class fileName{
    private :
        string name ;
    public :
        fileName(string arr){
            name = arr ;
        }

        string getName(){
            return name ;
        }

};

int main(int argc , char *argv[]){
    fileName FN(argv[1]) ;

    int alphabets[26] ;
    char c ;
    fstream in_file    ;
    in_file.open( "test.txt" , ios::in  );

    for(int i = 0 ; i < 26 ; i++){
        alphabets[i] = 0 ;
    }

    while(true){
        in_file >> c  ;
        alphabets[c-'a'] ++ ;
        if(in_file.eof()){
            break ;
        }
    }

    alphabets[c-'a'] -- ;

    for(int i = 0 ; i<26 ; i++){
        c = 'a' + i ;
        cout << c << " : "  << alphabets[i] << endl ;
    }

}
