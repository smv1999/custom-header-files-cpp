#include<math.h>
typedef long long int LLI;
LLI reverse(LLI num);
int sumOfDigits(LLI num);
bool isPrime(LLI num);
int gcd(LLI num1, LLI num2);
int lcm(LLI num1, LLI num2);


/*
Reverse the digits of the number
*/
LLI reverse(LLI num)
{
    LLI rev = 0;
    while(num>0)
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
    int sum=0;
    while(num>0)
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
    for(processNum = 2; processNum<=sqrt(num); processNum++)
    {
        if(num % processNum == 0)
            return false;
    }
    return true;
}

int gcd(LLI num1, LLI num2)
{
    if(num2==0)
        return num1;
    else gcd(num2, num1%num2);
}
int lcm(LLI num1, LLI num2)
{
    return (num1 * num2) / gcd(num1, num2);
}


