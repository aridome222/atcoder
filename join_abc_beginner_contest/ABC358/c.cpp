#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main()
{
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    ll diff_x, diff_y;
    diff_x = abs(tx - sx);
    diff_y = abs(ty - sy);
    if (sx % 2 == 1)
    {
        if (sx - tx > 0)
        {
            if ((sx - tx / 2) == 0)
            {
                cout << (sx - tx / 2) << endl;
                return 0;
            }
        }
    }
    if (diff_y > diff_x / 2)
    {
        cout << diff_y << endl;
        return 0;
    }
    else
    {
        cout << diff_x / 2 << endl;
        return 0;
    }
}
// if (sx % 2 == 0)
// {
//     if (sx - tx == 0)
//     {
//         cout << diff_y << endl;
//         return 0;
//     }else if(sx - tx > 0){

//     }
// }

// if (diff_y == 0)
// {
//     cout << diff_x << endl;
//     return 0;
// }
// else if (diff_x == 0)
// {
//     cout << diff_y << endl;
//     return 0;
// }

// if (sx - tx > 0)
// {
//     if (sx % 2 == 0)
//     {
//         if (sx - tx < 6)
//         {
//             cout << diff_y << endl;
//             return 0;
//         }
//         else
//         {
//             cout << diff_y + (abs(tx - sx) - diff_x) / 2 << endl;
//             return 0;
//         }
//     }
// }

// if (sx % 2 == 0)
// {
// }
// else
// {
//     if (sx - tx < 0)
//     {
//     }
//     else
//     {
//     }
// }

// cout << ans << endl;
// }
