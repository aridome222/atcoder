#include <bits/stdc++.h>
#include <../cpp-dump/dump.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> parentheses(1 << n, "");
    cpp_dump(parentheses);
    rep(i, 1 << n)
    {
        int cnt = 0;
        rep(j, n)
        {
            if (i & (1 << j))
            {
                parentheses[i] += "(";
                cnt++;
            }
            else
            {
                parentheses[i] += ")";
                cnt--;
            }
            if (cnt < 0)
            {
                break;
            }
        }
        if (cnt == 0)
        {
            cout << parentheses[i] << endl;
        }
    }

    return 0;
}