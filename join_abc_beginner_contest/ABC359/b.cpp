#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> a(2 * n, 0);
    rep(i, 2 * n)
    {
        cin >> a[i];
    }

    rep(i, 2 * n - 2)
    {
        cnt += a[i] == a[i + 2];
    }
    cout << cnt << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < (n); i++)

// int main()
// {
//     int n, cnt = 0;
//     cin >> n;
//     vector<int> a(2 * n, 0);
//     rep(i, 2 * n)
//     {
//         cin >> a[i];
//     }

//     rep(i, 2 * n - 2)
//     {
//         // pre = a[i];
//         if (a[i] == a[i + 2])
//         {
//             cnt++;
//         }
//     }
//     cout << cnt << "\n";

//     return 0;
// }
