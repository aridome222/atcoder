#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int main()
{
    // 各行・各列にコマがあるか
    // はじめはすべて false にしておく
    array<bool, 8> row{}, column{};

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            char c;
            cin >> c;
            // コマが置かれていたら
            if (c == '#')
            {
                // 対応する行と列を true に
                row[i] = true;
                column[j] = true;
            }
        }
    }

    // false の行数 × false の列数 が答え
    cout << count(row.begin(), row.end(), false) * count(column.begin(), column.end(), false) << endl;

    return 0;
}
