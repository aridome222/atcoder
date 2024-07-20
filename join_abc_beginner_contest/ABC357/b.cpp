#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    for (char c : s)
    {
        if (isupper(c))
        {
            uppercaseCount++;
        }
        else if (islower(c))
        {
            lowercaseCount++;
        }
    }
    string s2 = s;
    if (uppercaseCount > lowercaseCount)
    {
        for (int i = 0; i < s.size(); i++)
        {
            s2[i] = toupper(s[i]);
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            s2[i] = tolower(s[i]);
        }
    }

    cout << s2 << endl;
    return 0;
}