// Program written by: Prof. RKJ, CSE, IIT Bombay
// Program part of: CS 152/CS154 Laboratory, 2021 batch
// Program for: problem 1.1.1 (assignment 1, part 1, program 1) = prog1.c 


#include <iostream>
#include <cstdlib>
using namespace std;

int main (int argc, char *argv[]) {

  int face_count[6];
  float face_count_empirical_prob [6];
  int N, r;

  if (argc < 2) {
	cout << "usage: no_of_tries\n";
	exit(1);
  };

  N = atoi (argv[1]);

  cout << "counting over " << N << " throws\n";
  
  for (int i=0; i<6; i++) 
	face_count[i]=0;

  srand(time(0));
  for (int i=0; i<N; i++) {

      r = rand()%6;

    cout << r << " ";

      face_count[r]++;
  }

 cout << endl;

  for (int i=0; i<6; i++) 
	face_count_empirical_prob [i] = (float)face_count[i]/N;
 
  for (int i=0; i<6; i++) 
	 cout << face_count_empirical_prob [i] << " ";
  cout << endl;

}
