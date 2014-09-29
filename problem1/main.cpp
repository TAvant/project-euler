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
int SumNatNum(int);

int greatestMultiple(int, int);

// main program
// ==== =======

int main(int argc, char* argv[]) {

  // initialize main program variables
  int x, y, z, xy;
  int gm_x, gm_y, gm_xy;
  int sum_gm_x, sum_gm_y, sum_gm_xy;
  int new_x, new_y, new_xy;
  int result;

  // get the first three command line arguments
  x = atoi(argv[1]);
  y = atoi(argv[2]);
  z = atoi(argv[3]);

  // find the sum of all the multiples of x or y below z
  /*
    In this version, instead of using an iteritive loop I used the fact that
    the greatest number below z will be a multiple of x or y. 

      GCF = z/x and z/y

    When finding the sum of all the multiples of x and y below z and you 
    factor an x and a y we end up with: 

      x(1, 2, 3, ... , GCF < z) and y(1, 2, 3, ... , GCF < z)

    So we can use the formula to add a range of natural numbers and multiply
    the sum of the range by the value we factored. 
    If GCF_x = nx and GCF_y = ny:

      x * [(nx (nx+1)) / 2]  and y * [(ny (ny+1)) / 2]

    Now we just add the values we found above.

    The last problem we need to solve is the problem that there are common
    factors and we cannot count them twice. In order to find the GCM we simply
    multiply x and y.

      GCM = X * Y

    Now we follow the same procedure we followed above in order to to find 
    the sum of all multiples of x and y below z; though, we do it for the 
    GCM of x and y.

    Our last step is is to reduce the sum of all multiples of x and y
    below z, by the sum of all multiples of x * y.
  */

    // based on z, get the greatest multiple for x and y
      // function: gratestMultiple
    gm_x = greatestMultiple(x, z);
    gm_y = greatestMultiple(y, z);

    // find the sum of all the numbers numbers up to gm_x and gm_y
      // function: SumNatNum
    sum_gm_x = SumNatNum(gm_x);
    sum_gm_y = SumNatNum(gm_y);

    // multiply the sums of the greatest multiple by their factor
    new_x = x * sum_gm_x;
    new_y = y * sum_gm_y;

    // combine the two sums
    result = new_x + new_y;

    // find the sum of all the common multiples of x and y below z

      // common multiple of x and y is x*y
      xy = x * y;

      // based on z, get the greatest multiple of the common multiple
      gm_xy = greatestMultiple(xy, z);

      // multiply the sums of the greatest multiple by their factor
      sum_gm_xy = SumNatNum(gm_xy);

      // multiply the sum of the greatest common multiple by its factor
      new_xy = xy * sum_gm_xy;

    // subtract commom multiple from sum of all the multiples of x or y below z
    result -= new_xy;

  // print result to screen
  std::cout << "sum of all the multiples of " << x << " or " << y << " below " << z << " : " << result << std::endl;

  // end main program
  return 0;
}

// function implementation
// ======== ==============
int SumNatNum(int natNum) {

  // initialize function variables
  int n = natNum;

  // the sum from 1 to n: (n*(n+1))/2

    // increment the total natural number by one
    ++n;

    // multiply the inrcemented value by the natural number
    n *= natNum;

    // divide the new number by two
    n /= 2;

  // return the value
  return n;
}

int greatestMultiple(int denominator, int numerator) {

  // decrement the numerator
  --numerator;

  // return result of the numerator and denominator
  return (numerator/denominator);
}
