#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();

    // w文字ごとに区切る
    for (int w = 1; w < n; w++)
    {
        // c列目を連結させた文字列を作る
        for (int c = 0; c < w; c++)
        {
            string ans = "";
            for (int i = c; i < n; i += w)
            {
                ans += s[i];
            }

            if (t == ans)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}