// Q125.) Valid Palindrome in leetcode

#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

// will not work in leetcode without making some changes
int main()
{
    string s;
    cout << "Enter a String to check if its a palindrome: " << endl;
    getline(cin, s);

    if (s.empty())
    {
        cout << "Empty string is a palindrome." << endl;
        return 0;
    }

    int start = 0;
    int end = s.size() - 1;

    while (start < end)
    {
        if (!isalnum(s[start]))
        {
            start++;
        }
        else if (!isalnum(s[end]))
        {
            end--;
        }
        else
        {
            if (tolower(s[start]) != tolower(s[end]))
            {
                cout << "Not a palindrome" << endl;
                return 0;
            }

            start++;
            end--;
        }
    }

    cout << "Palindrome" << endl;

    return 0;
}