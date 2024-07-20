#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
    int r_cnt = 0;
    int m_cnt = 0;
    string s;
    cin >> s;

    rep(i, s.size())
    {
        if (s[i] == 'R')
            r_cnt++;
        if (s[i] == 'M')
            m_cnt++;

        if (r_cnt == 1 && m_cnt == 0)
        {
            cout << "Yes" << endl;
            break;
        }
        else if (r_cnt == 0 && m_cnt == 1)
        {
            cout << "No" << endl;
            break;
        }
    }

    return 0;
}
