/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 4
Date: 5/9/22
*/

#ifndef HUNPOLYNOMIAL
#define HUNPOLYNOMIAL

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

class HunPolynomial 
{
    public:
        HunPolynomial();
        HunPolynomial(const std::vector <int> & coefficients);
        void Set(const std::vector <int> & coefficients);
        HunPolynomial operator+(const HunPolynomial & other) const;
        HunPolynomial operator-(const HunPolynomial & other) const;
        HunPolynomial operator*(const HunPolynomial & other) const;
        friend std::ostream & operator<<(std::ostream & output, const HunPolynomial & polynomial);
        float operator()(const float& x) const;

    private:
        std::vector <int> coefficients_;
};

#endif


// command to run the program:
// g++  -std=c++17  TestPolynomial.cpp  HunPolynomial.cpp  -o prog
// ./prog