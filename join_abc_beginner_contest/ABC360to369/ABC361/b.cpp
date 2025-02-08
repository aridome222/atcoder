#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)

int main()
{
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    if (ax < 0)
    {
    }

    double a, b, c;
    a = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
    b = sqrt(pow(bx - cx, 2) + pow(by - cy, 2));
    c = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));

    if (a == b && b == c && c == a)
    {
        cout << "No" << endl;
        return 0;
    }
    if ((a == b && a == c) || (b == a && b == c) || (c == a && c == b))
    {
        cout << "No" << endl;
        return 0;
    }
    if (a > b && a > c)
    {
        if (a == sqrt(b * b + c * c))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else if (b > a && b > c)
    {
        if (b == sqrt(a * a + c * c))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else if (c > a && c > b)
    {
        if (c == sqrt(a * a + b * b))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}