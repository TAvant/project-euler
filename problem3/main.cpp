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
const int SMALLEST_PRIME_NUM = 2;
const long long int X = 600851475143LL; 

// global variables
// ====== =========


// function specification
// ======== =============
bool isPrime(long long int);

// main program
// ==== =======
int main(int argc, char* argv[]) {

  /*
    The prime factors of 13195 are 5, 7, 13 and 29.

    What is the largest prime factor of the number 600851475143 ?
  */

  // initialize main program variables
  bool haveLargest = false;
  long long int num = X - 2;
  long long int greatestPrime;

  // loop while we don't have largest prime factor
  while(!haveLargest) {

    // check if current number is a factor of X
    if((X % num) == 0) {

      // check if number is prime
      if(isPrime(num)) {

        // assign number as greatest prime and set flag to true
        greatestPrime = num;
        haveLargest = true;
      }
    }

    // decrement the number twice
    --num;
    --num;
  }

  // print greatest prime number to screen
  std::cout << "The largest prime factor of " << X << " is: " << greatestPrime
            << std::endl;

  // end main program
  return 0;
}

// function implimentation
// ======== ==============
bool isPrime(long long int number) {

  // initialize function variables
  bool isPrime;

  // assume number is prime
  isPrime = true;

  // check if number is prime
  for(long long int i = number - 1; i >= SMALLEST_PRIME_NUM; --i)
    if(number % i == 0)
      isPrime = false;

  // return the current prime number
  return isPrime;
}
