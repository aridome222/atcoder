#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // 入力を読み込む
    int N, M;
    cin >> N >> M; // N: 頂点数, M: 辺の数

    vector<vector<pair<int, int>>> G(N); // グラフの隣接リスト (頂点, 重み)
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;       // 辺の情報を読み込む
        u--;                      // 0-indexed に変換
        v--;                      // 0-indexed に変換
        G[u].emplace_back(v, w);  // u から v への辺
        G[v].emplace_back(u, -w); // v から u への辺（重みを負に）
    }

    vector<bool> visited(N, false); // 値が確定しているかどうか
    vector<int> ans(N, 0);          // 書き込む値

    for (int i = 0; i < N; ++i)
    {
        // すでに値が確定しているならばスキップ
        if (visited[i])
        {
            continue;
        }
        // 頂点 i の値を 0 に確定し，探索を始める
        stack<int> st;
        st.push(i);
        visited[i] = true;

        while (!st.empty())
        {
            // いま頂点 u にいる
            int u = st.top();
            st.pop();
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
                }
            }
        }
    }

    // 結果を出力
    for (const int &value : ans)
    {
        cout << value << " "; // 値を出力
    }
    cout << endl;

    return 0;
}
