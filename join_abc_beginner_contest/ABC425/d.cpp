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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    // 現在の状態をコピー
    vector<string> current = S;

    // 4方向の移動
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // 十分な回数（最大でもH+W回程度で収束）シミュレーション
    rep(step, H + W + 10)
    {
        vector<pair<int, int>> to_paint; // 今回黒く塗るマス

        rep(i, H) rep(j, W)
        {
            if (current[i][j] == '.')
            { // 白マスの場合
                int black_count = 0;

                // 隣接する4方向をチェック
                rep(d, 4)
                {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if (0 <= nx && nx < H && 0 <= ny && ny < W && current[nx][ny] == '#')
                    {
                        black_count++;
                    }
                }

                // 隣接する黒マスがちょうど1つなら塗る対象
                if (black_count == 1)
                {
                    to_paint.push_back({i, j});
                }
            }
        }

        // 変化がなければ終了
        if (to_paint.empty())
            break;

        // 一斉に黒く塗る
        for (auto [x, y] : to_paint)
        {
            current[x][y] = '#';
        }
    }

    // 黒マスの個数を数える
    ll ans = 0;
    rep(i, H) rep(j, W)
    {
        if (current[i][j] == '#')
        {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
