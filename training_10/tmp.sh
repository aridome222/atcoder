#!/bin/bash

# ファイル名を引数として受け取る
filename=$1

# ファイル名が指定されていない場合、エラーメッセージを表示して終了
if [ -z "$filename" ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

# 拡張子が含まれていない場合、.cpp を追加
if [[ ! "$filename" =~ \.cpp$ ]]; then
  filename="${filename}.cpp"
fi

# テンプレート内容
template='#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define repR(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define rep3R(i, m, n) for (int i = (int)(n) - 1; i >= (int)(m); --i)
#define all(x) std::begin(x), std::end(x)

int main()
{


    return 0;
}'

# ファイルを作成し、テンプレート内容を書き込む
echo "$template" > "$filename"

# ファイル作成成功のメッセージ
echo "$filename has been created."
