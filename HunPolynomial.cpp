/*
Name: Ali Faiyaz
Class: CSCI 235 - Project 4
Date: 5/9/22
*/

#include <iostream>
#include "HunPolynomial.h"

HunPolynomial::HunPolynomial() {}
HunPolynomial::HunPolynomial(const std::vector<int>& coefficients) : coefficients_(coefficients) {}
void HunPolynomial::Set(const std::vector <int> & coefficients)
{
    coefficients_ = coefficients;
}
HunPolynomial HunPolynomial :: operator+(const HunPolynomial & other) const
{
    HunPolynomial answer;
    if(coefficients_.size() < other.coefficients_.size())
    {
        std:: vector <int> copy;
        int difference = other.coefficients_.size() - coefficients_.size();
        for (int i = 0; i < difference ; i++)
        {
            copy.push_back(0);
        }
        for (int i = 0; i < coefficients_.size() ; i++)
        {
            copy.push_back(coefficients_[i]);
        }
        for (int i = 0; i < copy.size(); i++)
        {
           answer.coefficients_.push_back(copy[i]+ other.coefficients_[i]);
        }
    }
    else if(other.coefficients_.size() < coefficients_.size())
    {
        std:: vector <int> copy;
        int difference = coefficients_.size() - other.coefficients_.size();
        for (int i = 0; i < difference ; i++)
        {
            copy.push_back(0);
        }
        for (int i = 0; i < other.coefficients_.size() ; i++)
        {
            copy.push_back(other.coefficients_[i]);
        }
        for (int i = 0; i < copy.size(); i++)
        {
           answer.coefficients_.push_back(copy[i]+ coefficients_[i]);
        }
    }
    else 
    {
        for (int i = 0; i < coefficients_.size(); i++)
        {
           answer.coefficients_.push_back(other.coefficients_[i]+ coefficients_[i]);
        }
    }

    return answer;
}

HunPolynomial HunPolynomial :: operator-(const HunPolynomial & other) const
{
    HunPolynomial answer;
    if(coefficients_.size() < other.coefficients_.size())
    {
        std:: vector <int> copy;
        int difference = other.coefficients_.size() - coefficients_.size();
        for (int i = 0; i < difference ; i++)
        {
            copy.push_back(0);
        }
        for (int i = 0; i < coefficients_.size() ; i++)
        {
            copy.push_back(coefficients_[i]);
        }
        for (int i = 0; i < copy.size(); i++)
        {
           answer.coefficients_.push_back(copy[i]- other.coefficients_[i]);
        }
    }
    else if(other.coefficients_.size() < coefficients_.size())
    {
        std:: vector <int> copy;
        int difference = coefficients_.size() - other.coefficients_.size();
        for (int i = 0; i < difference ; i++)
        {
            copy.push_back(0);
        }
        for (int i = 0; i < other.coefficients_.size() ; i++)
        {
            copy.push_back(other.coefficients_[i]);
        }
        for (int i = 0; i < copy.size(); i++)
        {
           answer.coefficients_.push_back(coefficients_[i] - copy[i]);
        }
    }
    else 
    {
        for (int i = 0; i < coefficients_.size(); i++)
        {
           answer.coefficients_.push_back(coefficients_[i] - other.coefficients_[i]);
        }
    }

    return answer;
}
HunPolynomial HunPolynomial::operator*(const HunPolynomial & other) const
{  
    HunPolynomial answer;
    int highest_exponent = (coefficients_.size() - 1) + (other.coefficients_.size()) ;
    for (int i = 0 ; i < highest_exponent; i++)
    {
        answer.coefficients_.push_back(0);
    }
    for (int i = 0; i < coefficients_.size(); i++)
    {
        for (int j = 0; j < other.coefficients_.size(); j++)
        {
            answer.coefficients_[i+j] += coefficients_[i] * other.coefficients_[j];
        }
    }
    return answer;
}

std::ostream& operator<<(std::ostream& output, const HunPolynomial& polynomial)
{ 
    int power = polynomial.coefficients_.size() - 1;
    int zero_count = 0;
    for(int i = 0; i < polynomial.coefficients_.size(); i++)
    {   
        if(polynomial.coefficients_[i] == 0)
        {
            zero_count++;
        }
    }
    if (zero_count == polynomial.coefficients_.size()) // if its all zeroes print empty return
    {
        output << "";
        return output;
    }
    else if(zero_count == polynomial.coefficients_.size() - 1) // if its one number only print the number and return 
    {
        for(int i = 0; i < polynomial.coefficients_.size(); i++)
        {
            if(polynomial.coefficients_[i] == 0)
            {
                power--;
                continue;
            }
            if(power == 1)
            {
                if(polynomial.coefficients_[i] == 1)
                {
                    output << "x";
                }
                else if(polynomial.coefficients_[i] == -1)
                {
                    output << "-x";
                }
                else
                {
                    output << polynomial.coefficients_[i] << "x";
                }
                break;
            }
            else if(power == 0)
            {
                output << polynomial.coefficients_[i];
                break;
            }
            else
            {
                if (polynomial.coefficients_[i] == 1)
                {
                    output << "x^" << power;
                }
                else 
                {
                    output << polynomial.coefficients_[i] << "x^" << power;
                }
                break;
            }
        }
        return output;  
    }
    int first_token_index = 0;
    for(int i = 0; i < polynomial.coefficients_.size(); i++) // deals with leading zeroes
    {
        if(polynomial.coefficients_[i] == 0)
        {
            power--;
            continue;
        }
        else
        {
            first_token_index = i;
            break;
        }
    }
    if(polynomial.coefficients_[first_token_index] == 1 && power != 1) // deals with first token
    {
        output << "x^" << power;
    }
    else if(polynomial.coefficients_[first_token_index] == 1 && power == 1)
    {
        output << "x";
    }
    else if(polynomial.coefficients_[first_token_index] == -1 && power != 1)
    {
        output << "- x^" << power;
    }
    else if (polynomial.coefficients_[first_token_index] == -1 && power == 1)
    {
        output << "- x";
    }
    else if (power == 1)
    {
        output << polynomial.coefficients_[first_token_index] << "x";
    }
    else
    {
        if (polynomial.coefficients_[first_token_index] < 0)
        {
            std::string holders = std::to_string(polynomial.coefficients_[first_token_index]);
            std::string answer = "";
            answer+= "- " + holders.substr(1);
            output << answer << "*x^" << power;
        }
        else 
        {
            output << polynomial.coefficients_[first_token_index] << "*x^" << power;
        }
    }
    power--;
    for(int i = first_token_index + 1; i < polynomial.coefficients_.size(); i++) // rest of tokens
    {
        if(polynomial.coefficients_[i] == 0) // if the coefficient is 0 go to the next term 
        {
            power--;
            continue;
        }
        
        if(polynomial.coefficients_[i] < 0) // if its a negative coefficient dont add a operator 
        {
            output << " - ";
        }
        else
        {
            output << " + "; // if its a plus add a plus sign
        }

        if(power == 0)
        {
            if(polynomial.coefficients_[i] < 0)
            {
                output << std::to_string(polynomial.coefficients_[i]).substr(1);
            }
            else 
            {
                output << polynomial.coefficients_[i];
            }
            break;
        }

        if(polynomial.coefficients_[i] == 1 && power != 1) // if power is 1 just print out the x
        {
            output << "x^" << power;
        }
        else if(polynomial.coefficients_[i] == 1 && power == 1)
        {
            output << "x";
        }
        else if (polynomial.coefficients_[i] == -1 && power != 1)
        {
           output << "x^" << power;
        }
        else if(polynomial.coefficients_[i] == -1 && power == 1)
        {
            output << "x";
        }
        else if (polynomial.coefficients_[i] < 0 && power == 1)
        {
            output << std::to_string(polynomial.coefficients_[i]).substr(1) << "*x";
        }
        else if (polynomial.coefficients_[i] > 0 && power == 1)
        {
            output << polynomial.coefficients_[i] << "*x";
        }
        else
        {
            if(polynomial.coefficients_[i] < 0)
            {
                output << std::to_string(polynomial.coefficients_[i]).substr(1) << "*x^" << power;
            }
            else 
            {
                output << polynomial.coefficients_[i] << "*x^" << power;
            }
        }
        power--;
    }
    return output;
}

float HunPolynomial::operator()(const float& x) const
{
    float total = 0;

    for (int i = 0; i < coefficients_.size(); i++)
    {
        total += coefficients_[i] * pow(x, coefficients_.size() - 1 - i);
    }
    return total;
}
