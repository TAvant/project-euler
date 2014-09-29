//
// main.cpp
//
// Tommy Avant - August 21, 2013
// Project Euler - Problem 1
//

// header files
// ====== =====
#include <iostream>
#include <cmath>
#include <cstdlib>

// global conctants
// ====== =========

  // TODO

// function specification
// ======== =============

  // TODO

// main program
// ==== =======

int main(int argc, char* argv[]) {

  // initialize main program variables
  int x, y, z;
  int sum = 0;

  // find the sum of all the multiples of x or y below z

    // get the first three commandline parameters
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    z = atoi(argv[3]);

    // loop through all values of z
    for(int i = 1; i < z; ++i) {

      // if current value of i is a multiple of x or y, ad value of i to sum
      if(i % x == 0 || i % y == 0) {
        sum += i;
      }
    }

  // print result to screen
  std::cout << "The sum of all the multiples of " << x << " or " << y
            << " below " << z << ": " << sum << std::endl;

  // end main program
  return 0;
}

// function implementation
// ======== ==============

  // TODO
