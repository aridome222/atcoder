#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define mprint(msg) cout << msg << endl;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a * b;
    if (c % 2 == 0)
    {
        mprint("Even");
    }
    else
    {
        mprint("Odd");
    }
    return 0;
}
