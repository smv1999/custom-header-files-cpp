#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>

using namespace std;

// Function prototypes
bool contains(string s1, string s2);
bool startswith(string s1, string s2, int start = 0, int end = 0);
bool endswith(string s1, string s2, int start = 0, int end = 0);
void capitalize(string &s);
int count(string s1, string s2);
int find(string s, char val);
int find(string s, string val);
int findLastOccurence(string s, char val);
int findLastOccurence(string s, string val);
bool isalnum(string s);
bool isalpha(string s);
bool isdigit(string s);
bool islower(string s);
bool isupper(string s);
bool istitle(string s);
void lower(string &s);
void upper(string &s);
vector<string> split(string s, char c = ' ');
void swapcase(string &s);
void title(string &s);
void replace(string &s, char c, char k);
void replace(string &s, string c, string k);

/*
Returns true if the string s2 is contained in s1
*/
bool contains(string s1, string s2)
{
    map<char, int> mp1, mp2;
    for (char c : s2)
    {
        mp2[c]++;
    }

    for (char c : s1)
    {
        mp1[c]++;
    }

    for (auto it : mp2)
    {
        if (it.second > mp1[it.first])
        {
            return false;
        }
    }

    return true;
}

/*
end index is not inclusive
*/
bool startswith(string s1, string s2, int start = 0, int end = 0)
{
    if (start != 0)
    {
        string tempStr = "";
        for (int index = start; index < end; index++)
            tempStr += s1[index];
        return contains(tempStr, s2);
    }
    for (int index = 0; index < s2.length(); index++)
    {
        if (s2[index] != s1[index])
        {
            return false;
        }
    }
    return true;
}

/*
end index is not inclusive
*/
bool endswith(string s1, string s2, int start = 0, int end = 0)
{
    if (end != 0)
    {
        string tempStr = "";
        for (int index = start; index < end; index++)
            tempStr += s1[index];
        return startswith(tempStr, s2, tempStr.length() - s2.length(), s1.length() - 1);
    }
    // normal case
    return startswith(s1, s2, s1.length() - s2.length(), s1.length() - 1);
}

/*
Capitalizes the string passed as argument
*/
void capitalize(string &s)
{
    s[0] = toupper(s[0]);
}

/*
Counts the number of times the string s2 occurs in s1
*/
int count(string s1, string s2)
{
    map<char, int> mp1, mp2;
    for (char c : s2)
    {
        mp2[c]++;
    }

    for (char c : s1)
    {
        mp1[c]++;
    }

    for (auto it : mp2)
    {
        if (mp1[it.first] % it.second == 0)
        {
            return mp1[it.first];
        }
    }

    return 0;
}

/*
Searches (first occurrence) the string for a specified value and returns the position of where it was found.
Function Overloading
*/
int find(string s, char val)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (s[index] == val)
        {
            return index;
        }
    }
    return -1;
}

int find(string s, string val)
{
    int searchIndex = 0, valLength = val.length(), firstIndex;
    for (int index = 0; index < s.length(); index++)
    {
        if (s[index] == val[0])
        {
            firstIndex = index;
            break;
        }
    }

    for (int index = firstIndex; index < s.length(); index++)
    {
        if (s[index] == val[searchIndex])
        {
            searchIndex++;
            if (searchIndex == valLength)
                return firstIndex;
        }
    }

    return -1;
}

/*
Searches (last occurrence) the string for a specified value and returns the position of where it was found.
Function Overloading
*/
int findLastOccurence(string s, char val)
{
    int lastIndex = -1;
    for (int index = 0; index < s.length(); index++)
    {
        if (s[index] == val)
        {
            lastIndex = index;
        }
    }
    return lastIndex;
}

int findLastOccurence(string s, string val)
{
    int searchIndex = 0, valLength = val.length(), lastIndex = -1;
    for (int index = 0; index < s.length(); index++)
    {
        if (s[index] == val[0])
        {
            lastIndex = index;
        }
    }

    for (int index = lastIndex; index < s.length(); index++)
    {
        if (s[index] == val[searchIndex])
        {
            searchIndex++;
            if (searchIndex == valLength)
                return lastIndex;
        }
    }

    return lastIndex;
}

/*
Returns true if all the characters in the string are alphanumeric
*/
bool isalnum(string s)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (!isalnum(s[index]))
            return false;
    }
    return true;
}

bool isalpha(string s)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (!isalpha(s[index]))
            return false;
    }
    return true;
}

bool isdigit(string s)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (!isdigit(s[index]))
            return false;
    }
    return true;
}

bool islower(string s)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (!islower(s[index]))
            return false;
    }
    return true;
}

bool isupper(string s)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (!isupper(s[index]))
            return false;
    }
    return true;
}

/*
Returns true if the string follows the rules of a title
*/

bool istitle(string s)
{

    bool followsTitle = false;
    if (isupper(s[0]))
        followsTitle = true;
    for (int index = 1; index < s.length(); index++)
    {
        if (s[index] == ' ')
        {
            if (isupper(s[index + 1]))
                followsTitle = true;
            else
                followsTitle = false;
        }
    }

    return followsTitle;
}

/*
Converts the string passed as input into lowercase
*/

void lower(string &s)
{
    for (int index = 0; index < s.length(); index++)
    {
        s[index] = tolower(s[index]);
    }
}

/*
Converts the string passed as input into uppercase
*/

void upper(string &s)
{
    for (int index = 0; index < s.length(); index++)
    {
        s[index] = toupper(s[index]);
    }
}

/*
Splits the string at the specified separator and returns a vector of strings
*/

vector<string> split(string s, char c = ' ')
{
    vector<string> res;
    string tempStr = "";
    for (int index = 0; index < s.length(); index++)
    {
        if (s[index] != c)
        {
            tempStr += s[index];
        }
        else
        {
            res.push_back(tempStr);
            tempStr = "";
        }
    }
    res.push_back(tempStr);
    return res;
}

/*
Swaps cases in a string, i.e., lowercase becomes uppercase and vice-versa.
*/

void swapcase(string &s)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (islower(s[index]))
            s[index] = toupper(s[index]);
        else
            s[index] = tolower(s[index]);
    }
}

/*
Converts the first character of each word to uppercase
*/

void title(string &s)
{
    s[0] = toupper(s[0]);

    for (int index = 1; index < s.length(); index++)
    {
        if (s[index] == ' ')
        {
            s[index + 1] = toupper(s[index + 1]);
        }
    }
}

/*
Replaces the specified value in the string with the specified value passed as arguement
*/

void replace(string &s, char c, char k)
{
    for (int index = 0; index < s.length(); index++)
    {
        if (s[index] == c)
        {
            s[index] = k;
        }
    }
}

void replace(string &s, string c, string k)
{
    int replacePosition = find(s, c);
    int replacerIndex = 0, index;
    if (c.length() > k.length())
    {
        for (index = replacePosition; index < replacePosition + k.length(); index++)
        {
            s[index] = k[replacerIndex++];
        }
        s.erase(index, c.length() - k.length());
    }
    else
    {
        s.insert(replacePosition, k);

        s.erase(replacePosition + k.length(), c.length());
    }
}