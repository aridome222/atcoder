#!/bin/bash

# テンプレート内容
template='#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
#define contain(str, ch) (str.find(ch) != string::npos)
#define mPrint(msg) cout << msg << endl;
#define arrPrint(arr)                \
    {                                \
        bool first = true;           \
        for (const auto &elem : arr) \
        {                            \
            if (!first)              \
                cout << " ";         \
            cout << elem;            \
            first = false;           \
        }                            \
        cout << endl;                \
    }
#define dump(x)  cout << #x << " = " << (x) << endl;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
// 二分探索
/*
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}
int binary_search(int key) {
    long long left = -1;
    long long right = (int)a.size();

    while (right - left > 1) {
        long long mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    return right;
}
*/

int main()
{


    return 0;
}'

# アルファベットを使用してファイル名生成
for char in {a..z}; do
    filename="${char}.cpp"
    # ファイルが存在しない場合のみ作成
    if [ ! -e "$filename" ]; then
        # ファイルを作成し、テンプレート内容を書き込む
        echo "$template" > "$filename"
        # 作成成功のメッセージ
        echo "$filename has been created."
    else
        echo "$filename already exists. Skipping."
    fi
done
