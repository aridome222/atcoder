#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
using namespace std;

struct Point
{
    int x;
    int y;
    int z;
};

Point input()
{
    Point p;
    cin >> p.x >> p.y >> p.z;
    return p;
}

bool solve()
{
    Point l1 = input();
    Point r1 = input();
    Point l2 = input();
    Point r2 = input();

    bool flag = true;

    if (r1.x <= l2.x)
        return false;
    if (r1.y <= l2.y)
        return false;
    if (r1.z <= l2.z)
        return false;
    if (r2.x <= l1.x)
        return false;
    if (r2.y <= l1.y)
        return false;
    if (r2.z <= l1.z)
        return false;

    return true;
}

int main()
{
    if (solve())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}