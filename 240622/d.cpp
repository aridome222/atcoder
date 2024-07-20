#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long Sx, Sy, Tx, Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    // タイルの左側に寄せておく
    if ((Sx + Sy) % 2 == 1)
    {
        --Sx;
    }
    if ((Tx + Ty) % 2 == 1)
    {
        --Tx;
    }

    // 答えは (|Sy - Ty| + max(|Sx - Tx|, |Sy - Ty|)) / 2
    long Dx = abs(Sx - Tx);
    long Dy = abs(Sy - Ty);
    cout << Dx << Dy << endl;

    cout << (Dy + max(Dx, Dy)) / 2 << endl;
    return 0;
}
