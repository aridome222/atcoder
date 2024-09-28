#!/bin/bash

# ABCで始まるフォルダをリストアップ
folders=$(ls -d ABC[0-9][0-9][0-9] 2>/dev/null)

# フォルダがない場合、最初のフォルダを作成
if [ -z "$folders" ]; then
  next_num=1
else
  # 最大の番号を見つける
  max_num=$(echo "$folders" | sed 's/ABC//' | sort -n | tail -n 1)
  # 次の連番を計算
  next_num=$((10#$max_num + 1))
fi

# 次の連番を3桁の形式にする
next_folder=$(printf "ABC%03d" "$next_num")

# 新しいフォルダを作成
mkdir "$next_folder"

# 新しいフォルダ作成成功のメッセージ
echo "Created folder: $next_folder"

# テンプレート内容
template='#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)
#define rAll(x) std::rbegin(x), std::rend(x)
#define mPrint(msg) cout << msg << endl;
#define dPrint(msg) cout << "-----\n" \
                         << msg << "\n-----\n";
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

int main()
{


    return 0;
}'

# 作成したフォルダ内に移動
cd "$next_folder" || exit

# ファイル名リスト
files="a b c d"

# 引数のファイル名リストを処理
for filename in $files; do
  # ファイルを作成し、テンプレート内容を書き込む
  echo "$template" > "$filename.cpp"
  # ファイル作成成功のメッセージ
  echo "$filename.cpp has been created."
done
