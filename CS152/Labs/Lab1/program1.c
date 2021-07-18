#include<stdlib.h>
#include<stdio.h>

int main(int argc , char* argv[]){
    int i = 0;
    char strng[256] ;
    for( i = 0 ; argv[0][i] != '\0' ; i++){
        strng[i]= argv[0][i] ;           
    }
    strng[i] = '\0' ;
    char fl[256] ; 
    FILE *fptr ;
    fptr = fopen(strng , "r");
    fscanf(fptr, "%s" , fl ) ;
    int alphabets[26];
    for(int i = 0 ; i < 26 ; i++){
        alphabets[i] = 0 ;
    }
    for(int i = 0 ; fl[i] != '\0' ; i++){
        alphabets[fl[i]-'a'] ++ ;
    }
    for(int i = 0 ; i < 26 ; i++){
        printf("%c : %d \n", i+'a' , alphabets[i]);
    }
}