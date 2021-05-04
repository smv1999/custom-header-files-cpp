#include <iostream>
#include <string>
#include <map>
#include <cctype>

// Tasks - https://www.w3schools.com/python/python_ref_string.asp

using namespace std;

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
        string temp = "";
        for (int index = start; index < end; index++)
            temp += s1[index];
        return contains(temp, s2);
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
        string temp = "";
        for (int index = start; index < end; index++)
            temp += s1[index];
        return startswith(temp, s2, temp.length() - s2.length(), s1.length() - 1);
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
Searches (first occurrence) the string for a specified value and returns the position of where it was found.
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