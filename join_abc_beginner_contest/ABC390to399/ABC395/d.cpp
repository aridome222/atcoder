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
    int n, q;
    cin >> n >> q;

    vector<int> pos_of_bard(n + 1);  // 鳩iがいる巣の場所
    vector<vector<int>> nest(n + 1); // 巣iにいる鳩を格納

    // 初期化(巣iに鳩iがいる)
    rep3(i, 1, n + 1)
    {
        pos_of_bard[i] = i;
        nest[i].push_back(i);
    }

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b;
            cin >> a >> b;
            /* 鳩の場所と巣にいる鳩の情報をそれぞれ更新 */
            // 鳩aが移動する前の巣の場所を保存
            int pre_pos_of_bard = pos_of_bard[a];
            // 前の巣の場所から鳩aを削除
            nest[pre_pos_of_bard].erase(remove(all(nest[pre_pos_of_bard]), a), nest[pre_pos_of_bard].end());
            // 鳩aを移動先の巣bに移動
            pos_of_bard[a] = b;
            // 巣bに鳩aを追加
            nest[b].push_back(a);
        }
        else if (t == 2)
        {
            int a, b;
            cin >> a >> b;
            // 入れ替え
            swap(nest[a], nest[b]); // 鳩の位置情報も更新
            for (int i : nest[a])
                pos_of_bard[i] = a;
            for (int i : nest[b])
                pos_of_bard[i] = b;
        }
        else
        {
            int i;
            cin >> i;
            cout << pos_of_bard[i] << endl;
        }
    }

    return 0;
}
