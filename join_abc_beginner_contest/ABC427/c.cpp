#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9 + 7;
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
#define dump(x) cout << #x << " = " << (x) << endl;
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
template <class T>
bool isOK(const vector<T> &a, size_t index, T key)
{
    if (a[index] >= key)
        return true;
    else
        return false;
}
template <class T>
int binary_search(const vector<T> &a, T key)
{
    size_t left = 0;
    size_t right = a.size();

    while (right - left > 1)
    {
        size_t mid = left + (right - left) / 2;

        if (isOK(a, mid, key))
            right = mid;
        else
            left = mid;
    }

    return right;
}

// 二部グラフ判定関数（矛盾する辺も返す）
pair<bool, vector<pair<int, int>>> checkBipartite(const vector<vector<int>> &G, int n)
{
    // color[i]：頂点 i の色が黒なら 1, 白なら 0, 未探索なら -1
    vector<int> color(n + 1, -1);
    vector<pair<int, int>> conflictEdges;

    rep3(i, 1, n + 1)
    {
        if (color[i] != -1)
            continue;

        // 頂点 i の色を白と決めうちした上で、幅優先探索
        queue<int> que; // 探索候補の頂点番号を入れるキュー
        color[i] = 0;
        que.push(i);

        // キューに要素が残っている限り
        while (que.size() > 0)
        {
            int qi = que.front();
            que.pop();
            // 頂点 qi に隣接している頂点 ni について、
            for (auto ni : G[qi])
            {
                if (color[ni] != -1)
                {
                    if (color[ni] == color[qi])
                    {
                        conflictEdges.push_back({min(qi, ni), max(qi, ni)});
                    }
                    continue;
                }
                color[ni] = 1 - color[qi];
                que.push(ni);
            }
        }
    }

    return {conflictEdges.empty(), conflictEdges};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        --u; // 0-indexedにする
        --v;
        edges[i] = {u, v};
    }

    int ans = m;
    // 2^n 通りの塗り方を全部探索する
    rep(bit, 1 << n)
    {
        int delete_count = 0;
        // それぞれの辺を見て
        for (const auto &[u, v] : edges)
        {
            // 頂点uの色を取得 (0=白, 1=黒)
            int color_u = (bit >> u) & 1;
            // 頂点vの色を取得 (0=白, 1=黒)
            int color_v = (bit >> v) & 1;

            // 結んでいる頂点が同じ色で塗られていたら
            if (color_u == color_v)
            {
                ++delete_count; // カウントを増やす
            }
        }
        // 全部の塗り方にわたる最小値が答え
        ans = min(ans, delete_count);
    }

    cout << ans << endl;
    return 0;
}
