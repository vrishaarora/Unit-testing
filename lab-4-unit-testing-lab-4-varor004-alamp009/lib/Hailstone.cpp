
#include "../include/Hailstone.h"


using sequence::satisfiesHailstone;


bool
sequence::satisfiesHailstone(uint64_t number) {
  if (0 == number) {
    return false;
  }

  while (true) {
    if (1 == number) {
      return true;
    } else if (0 == number%2) {
      number = number / 2;
    } else {
      number = 3 * number + 1;
    }
  }
}

