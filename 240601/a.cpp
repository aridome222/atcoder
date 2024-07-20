#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, l, r;

    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }

    l -= 1;
    r -= 1;

    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        a[i] = r - cnt + 1;
        cnt++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
