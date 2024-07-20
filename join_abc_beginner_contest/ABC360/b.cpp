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

int main()
{
    Point l1 = input();
    Point r1 = input();
    Point l2 = input();
    Point r2 = input();

    if (((l1.x <= l2.x && l2.x < r1.x) && (l1.y <= l2.y && l2.y < r1.y) && (l1.z <= l2.z && l2.z < r1.z)) ||
        ((l1.x < r2.x && r2.x <= r1.x) && (l1.y < r2.y && r2.y <= r1.y) && (l1.z < r2.z && r2.z <= r1.z)))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}