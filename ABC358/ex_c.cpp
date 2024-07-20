#include <bits/stdc++.h>
using namespace std;

// カーペットを生成する再帰的関数
void generateCarpet(int n, vector<vector<string>> &carpet)
{
    if (n == 0)
    {
        // 基底ケース: 最小サイズのカーペット
        carpet = {{"#"}};
        return;
    }

    // 前のサイズのカーペットを生成
    vector<vector<string>> smallerCarpet;
    generateCarpet(n - 1, smallerCarpet);
    int smallerSize = smallerCarpet.size();
    int newSize = 3 * smallerSize;

    // 新しいサイズのカーペットを準備
    carpet.resize(newSize, vector<string>(newSize, "#"));

    // 中心に前のカーペットを配置
    for (int i = 0; i < smallerSize; ++i)
    {
        for (int j = 0; j < smallerSize; ++j)
        {
            carpet[smallerSize + i][smallerSize + j] = ".";
        }
    }

    // 新しいレベルのカーペットの周囲に前のカーペットを配置
    for (int dy = 0; dy < 3; ++dy)
    {
        for (int dx = 0; dx < 3; ++dx)
        {
            if (dy == 1 && dx == 1)
                continue; // 中心はすでに配置済み

            for (int i = 0; i < smallerSize; ++i)
            {
                for (int j = 0; j < smallerSize; ++j)
                {
                    carpet[dy * smallerSize + i][dx * smallerSize + j] = smallerCarpet[i][j];
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> carpet;
    generateCarpet(n, carpet);
    int size = carpet.size();

    // カーペットの内容を表示
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << carpet[i][j];
        }
        cout << endl;
    }

    return 0;
}
