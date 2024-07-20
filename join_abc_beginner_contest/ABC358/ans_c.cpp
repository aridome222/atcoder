#include <bits/stdc++.h>
using namespace std;

// カーペットの中心部分をクリアする再帰的関数
void clearCenter(int x, int y, int currentSize, vector<vector<string>> &ans)
{
    if (currentSize == 1)
        return;

    int nextSize = currentSize / 3;
    int startX = x + nextSize;
    int startY = y + nextSize;

    // 中央のブロックをクリア
    for (int i = startX; i < startX + nextSize; ++i)
    {
        for (int j = startY; j < startY + nextSize; ++j)
        {
            ans[i][j] = ".";
        }
    }

    // 次のレベルのカーペットのための再帰呼び出し
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (!(i == 1 && j == 1))
            { // 中心ブロックを除外
                clearCenter(x + i * nextSize, y + j * nextSize, nextSize, ans);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int size = pow(3, n);
    vector<vector<string>> ans(size, vector<string>(size, "#"));

    clearCenter(0, 0, size, ans);

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
