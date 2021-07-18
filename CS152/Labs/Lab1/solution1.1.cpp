// Program written by: Prof. RKJ, CSE, IIT Bombay
// Program part of: CS 152/CS154 2021 batch
// Program for: problem 1.1.2 (assignment 1, part 1, program 2) = prog1.cpp 

#include <iostream>
#include <cstdlib>
using namespace std;


class Dice { //Dice with memory
 private:
  int face_count[6];
  int tosses;
  float face_count_empirical_prob [6];
 public:
    Dice();
    void toss();
    void compute_empirical_prob(); 
    void print_empirical_prob();
};

Dice::Dice() {

  for (int i=0; i<6; i++) 
	face_count[i]=0;
  tosses=0;
  srand(time(0));
};

void Dice::toss() {
  int r;
      r = rand()%6;
      face_count[r]++;
      tosses++;  // reduce this computation by one time summation at the time of need
};


void Dice::compute_empirical_prob() {
  for (int i=0; i<6; i++) 
	face_count_empirical_prob [i] = (float)face_count[i]/tosses;
};

void Dice::print_empirical_prob() {

  for (int i=0; i<6; i++) 
	 cout << face_count_empirical_prob [i] << " ";
  cout << endl;

}


int main (int argc, char *argv[]) {

  Dice dice;
  int N;

  if (argc < 2) {
	cout << "usage: no_of_tries\n";
	exit(1);
  };

  N = atoi (argv[1]);

  cout << "counting over " << N << " tosses\n";
  

  for (int i=0; i<N; i++) 
    dice.toss();

  dice.compute_empirical_prob();
  dice.print_empirical_prob();

 

}
