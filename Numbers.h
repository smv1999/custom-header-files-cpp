#include <math.h>
#include <string>
#include <type_traits>
typedef long long int LLI;

LLI reverse(LLI num);
int sumOfDigits(LLI num);
bool isPrime(LLI num);
int gcd(LLI num1, LLI num2);
int lcm(LLI num1, LLI num2);
int max(int num1, int num2);
int min(int num1, int num2);
template <typename T>
std::string type(T ele);
/*
Reverse the digits of the number
*/
LLI reverse(LLI num)
{
    LLI rev = 0;
    while (num > 0)
    {
        rev = (rev * 10) + (num % 10);
        num /= 10;
    }
    return rev;
}

/*
Sum of the digits of the number
*/
int sumOfDigits(LLI num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}

/*
Checking if the given number is prime or not
*/
bool isPrime(LLI num)
{
    int processNum;
    for (processNum = 2; processNum <= sqrt(num); processNum++)
    {
        if (num % processNum == 0)
            return false;
    }
    return true;
}

/*
Returns the Greatest Common Divisor of the given number
*/
int gcd(LLI num1, LLI num2)
{
    if (num2 == 0)
        return num1;
    else
        gcd(num2, num1 % num2);
}

/*
Returns the Least Common Multiple of a given number
*/
int lcm(LLI num1, LLI num2)
{
    return (num1 * num2) / gcd(num1, num2);
}

/*
Returns the max element among the two
*/
int max(int num1, int num2)
{
    return ((num1>num2)?(num1):(num2));
}

/*
Returns the min element among the two
*/
int min(int num1, int num2)
{
    return ((num1<num2)?(num1):(num2));
}

/*
Returns the type of the element given as parameter
*/
template <typename T>
std::string type(T ele)
{

    if(std::is_integral<T>::value)
        return "int";
    else if(std::is_floating_point<T>::value)
        return "float";
    else if(std::is_array<T>::value)
        return "array";
    else if(std::is_class<T>::value)
        return "class";
    else if(std::is_function<T>::value)
        return "function";
    else if(std::is_pointer<T>::value)
        return "pointer";
}

