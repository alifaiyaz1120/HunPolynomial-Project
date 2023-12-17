# HunPolynomial Project

The `HunPolynomial` class represents polynomials with integer coefficients and a single variable x, following specific formatting rules. It facilitates polynomial operations such as addition, subtraction, multiplication, and evaluation at a specific point.

## Overview

This C++ class is designed to handle polynomials in a format where coefficients are represented in a vector of integers. The class follows specific rules for polynomial representation and printing.


## File Structure

- `HunPolynomial.h`: Header file containing the class declaration.
- `HunPolynomial.cpp`: Implementation file containing the class methods.
- `TestPolynomial.cpp`: A test file demonstrating the usage of the `HunPolynomial` class.

## Compilation

Compile the program using the following command:

```bash
g++ -std=c++17 TestPolynomial.cpp HunPolynomial.cpp -o prog
```
## Class Methods
### Constructors
  - Default constructor: Constructs an empty polynomial.
  - Parametrized constructor: Takes a vector of integers and initializes the polynomial according to specified rules.

### Set Method
  - Set: Takes a vector of integers representing a polynomial and sets the polynomial to that value.
    
### Operators
 - +: Addition using standard polynomial addition rules.
 - -: Subtraction using standard polynomial subtraction rules.
 - *: Multiplication using standard polynomial multiplication rules.
 - <<: Non-member function for printing according to specific formatting rules.
 - (): Evaluation method, takes a float x0 and returns the polynomial value at that point.

### Example Usage
```bash
#include "HunPolynomial.h"
#include <iostream>

int main() {
    // Example 1
    std::vector<int> coeffs1{5, 0, -12, -1};
    HunPolynomial poly1(coeffs1);

    // Example 2
    std::vector<int> coeffs2{-34, 1, 0};
    HunPolynomial poly2(coeffs2);

    // Addition
    HunPolynomial resultAdd = poly1 + poly2;

    // Output
    std::cout << "Polynomial 1: " << poly1 << std::endl;
    std::cout << "Polynomial 2: " << poly2 << std::endl;
    std::cout << "Result (Addition): " << resultAdd << std::endl;

    return 0;
}
```
