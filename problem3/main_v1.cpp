//
// main.cpp
//
// Tommy Avant - August 24, 2013
// Project Euler - Problem 3
//

// header files
// ====== =====
#include <iostream>
#include <cstdlib>
#include <cmath>

// global constants
// ====== =========
// const long long int X = 600851475143LL; 
const int X = 13195; 

// global variables
// ====== =========


// function specification
// ======== =============
bool isPrime(int);
int nextPrime(int);

// main program
// ==== =======
int main(int argc, char* argv[]) {

  /*
    The prime factors of 13195 are 5, 7, 13 and 29.

    What is the largest prime factor of the number 600851475143 ?
  */

  // initialize main program variables
  int greatestPrime;
  int prime = 2;

  // loop while current prime number is less than number X
  while(prime < X) {

    // check if current prime number is a factor of number X
    if((X % prime) == 0) {

      // assign current prime to greatest prime
      greatestPrime = prime;
    }

    // get next prime number
    prime = nextPrime(prime);

  }

  // print greatest prime number to screen
  std::cout << "The largest prime factor of " << X << " is: " << greatestPrime
            << std::endl;

  // end main program
  return 0;
}

// function implimentation
// ======== ==============
bool isPrime(int number) {

  // initialize function variables
  bool isPrime;

  // assume number is prime
  isPrime = true;

  // check if number is prime
  for(int i = 2; i < number; ++i)
    if(number % i == 0)
      isPrime = false;

  // return the current prime number
  return isPrime;
}

int nextPrime(int number) {

  // initialize function variables
  bool prime = false;

  // loop to find next prime number
  while(!prime) {

    // increment current prime number
    ++number;

    // check if the number is prime
    if(isPrime(number))
      prime = true;
  }

  // return prime number
  return number;
}
