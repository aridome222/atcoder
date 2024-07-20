#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> H(N + 5, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> H[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (M >= H[i])
        {
            M -= H[i];
        }
        else
        {
            break;
        }
        ans++;
    }

    cout << ans << endl;
    return 0;
}