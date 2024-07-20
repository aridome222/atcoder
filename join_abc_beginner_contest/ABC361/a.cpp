#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)

int main()
{
    int r = 0;
    int g = 0;
    int b = 0;
    cin >> r >> g >> b;
    string c;
    cin >> c;
    int ans = 0;

    if (c == "Red")
    {
        if (g < b)
        {
            cout << g << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
    else if (c == "Green")
    {
        if (r < b)
        {
            cout << r << endl;
        }
        else
        {
            cout << b << endl;
        }
    }
    else if (c == "Blue")
    {
        if (r < g)
        {
            cout << r << endl;
        }
        else
        {
            cout << g << endl;
        }
    }

    return 0;
}
