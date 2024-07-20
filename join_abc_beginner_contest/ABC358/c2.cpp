#include <bits/stdc++.h>
using namespace std;

void creategrid(int size, vector<vector<string>> &ans)
{

    for (int i = size / 3; i < 2 * (size / 3); ++i)
    {
        for (int j = size / 3; j < 2 * (size / 3); ++j)
        {
            ans[i][j] = ".";
        }
    }
    return;
}

void fixgrid(int &size, vector<vector<string>> &ans)
{
    int size2 = size / 3;
    vector<vector<vector<string>>> block(size, vector<vector<string>>(size2, vector<string>(size2, "#")));

    for (int i = 0; i < size; ++i)
    {
        int rowBlock = i / size2;
        int colBlock = i % size2;
        for (int j = 0; j < size2; ++j)
        {
            for (int k = 0; k < size2; ++k)
            {
                int row = rowBlock * size2 + j;
                int col = colBlock * size2 + k;
                block[i][j][k] = ans[row][col];
            }
        }
    }

    int size3 = size2 / 3;
    for (int i = 0; i < size; ++i)
    {
        if (i != 4)
        {
            for (int j = size3; j < 2 * size3; ++j)
            {
                for (int k = size3; k < 2 * size3; ++k)
                {
                    block[i][j][k] = ".";
                }
            }
        }
    }

    // for (int i = 0; i < size; ++i)
    // {

    //     for (int j = 0; j < size2; ++j)
    //     {
    //         for (int k = 0; k < size2; ++k)
    //         {
    //             cout << block[i][j][k];
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < size; ++i)
    {
        int rowBlock = i / size2;
        int colBlock = i % size2;
        for (int j = 0; j < size2; ++j)
        {
            for (int k = 0; k < size2; ++k)
            {
                int row = rowBlock * size2 + j;
                int col = colBlock * size2 + k;
                ans[row][col] = block[i][j][k];
            }
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int size = pow(3, n); // サイズを計算
    vector<vector<string>> ans(size, vector<string>(size, "#"));
    creategrid(size, ans);

    while (n > 1)
    {
        fixgrid(size, ans);
        n--;
    }
    // for (int i = 0; i < size; ++i)
    // {
    //     for (int j = 0; j < size; ++j)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // if (n == 0)
    // {
    //     cout << "#" << endl;
    // }

    // for (int i = 0; i < m; i++)
    // {
    // }

    // // n > 0の時、nが0になるまで繰り返す
    // // n=1の時、二次元配列block1 = レベル1のカーペット
    // // n == 1であれば終了
    // // n=2の時、二次元配列block2 = レベル1のカーペットが最初に３つ、レベル1+レベル2+レベル1、レベル1のカーペットが最初に３つ、
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