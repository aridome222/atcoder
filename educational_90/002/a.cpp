#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main()
{
    int n;
    vector<string> parentheses(1 << n, "");
    rep(i, 1 << n)
    {

        rep(j, n)
        {
            if ((i >> j) & 1)
            {
                parentheses[i] = parentheses[i] + "(";
            }
        }
        return 0;
    }
}