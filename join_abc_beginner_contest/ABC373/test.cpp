#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // 入力を読み込む
    int N, M;
    cout << "頂点数 N と 辺の数 M を入力してください: ";
    cin >> N >> M; // N: 頂点数, M: 辺の数

    vector<vector<pair<int, int>>> G(N); // グラフの隣接リスト (頂点, 重み)
    cout << "辺の情報を入力してください (頂点 u, v, 重み w):\n";
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;       // 辺の情報を読み込む
        u--;                      // 0-indexed に変換
        v--;                      // 0-indexed に変換
        G[u].emplace_back(v, w);  // u から v への辺
        G[v].emplace_back(u, -w); // v から u への辺（重みを負に）
    }

    // グラフの構造を確認
    cout << "隣接リスト形式のグラフ:\n";
    for (int i = 0; i < N; ++i)
    {
        cout << "頂点 " << i + 1 << ": ";
        for (const auto &edge : G[i])
        {
            cout << "(隣接: " << edge.first + 1 << ", 重み: " << edge.second << ") ";
        }
        cout << endl;
    }

    vector<bool> visited(N, false); // 値が確定しているかどうか
    vector<int> ans(N, 0);          // 書き込む値

    // 各頂点について探索を開始
    for (int i = 0; i < N; ++i)
    {
        // すでに値が確定しているならばスキップ
        if (visited[i])
        {
            continue;
        }
        // 頂点 i の値を 0 に確定し，探索を始める
        cout << "頂点 " << i + 1 << " の値を 0 に確定し、探索を開始します。\n";
        stack<int> st;
        st.push(i);
        visited[i] = true;

        // スタックを用いた深さ優先探索
        while (!st.empty())
        {
            // いま頂点 u にいる
            int u = st.top();
            st.pop();
            cout << "頂点 " << u + 1 << " から隣接する頂点を探索します。\n";

            // 頂点 u に隣接する頂点 v を調べる
            for (const auto &edge : G[u])
            {
                int v = edge.first;  // 隣接頂点
                int w = edge.second; // 重み
                if (!visited[v])
                {
                    // まだ頂点 v の値が確定していないならば
                    visited[v] = true;
                    ans[v] = ans[u] + w; // 頂点 v の値を確定
                    st.push(v);          // 次の探索のためにスタックに追加
                    cout << "頂点 " << v + 1 << " の値を " << ans[v] << " に確定しました。\n";
                }
                else
                {
                    cout << "頂点 " << v + 1 << " は既に訪問済みです。\n";
                }
            }
        }
    }

    // 結果を出力
    cout << "各頂点の最終的な値: ";
    for (const int &value : ans)
    {
        cout << value << " "; // 値を出力
    }
    cout << endl;

    return 0;
}
