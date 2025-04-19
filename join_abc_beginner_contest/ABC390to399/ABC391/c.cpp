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

    unordered_set<int> st(n);
    vector<int> group(n, 1); // i番目の箱に何匹いるか
    // vector<int> db(n, 0);
    // vector<vector<int>> gp(n);
    unordered_map<int, int> mp(n);
    rep(i, n)
    {
        mp[i] = i; // 鳩をキーに鳩の場所が入ってる
    }
    rep(i, q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p, h;
            cin >> p >> h;
            p--;
            h--;
            // dump("--");
            // dump(p);
            // dump(h);
            // int tmp = mp[p]; // 移動前の鳩の場所
            int tmp = group[mp[p]];
            group[mp[p]]--; // 移動前の鳩の場所の鳩の数を減らす
            if (tmp == 2 && group[mp[p]] == 1)
            {
                st.erase(mp[p]);
            }
            mp[p] = h;      // 移動後の鳩の場所
            group[mp[p]]++; // 移動後の鳩の場所の鳩の数を増やす
            // st.insert();
            if (group[mp[p]] == 2)
            {
                st.insert(mp[p]);
            }

            // int pnum = group[p];
            // int hnum = group[h];
            // pnum--;
            // if (pnum >= 0)
            // {
            //     hnum++;
            // }
            // group[p] = max(0, pnum);
            // group[h] = hnum;
            // dump(group[p]);
            // dump(group[h]);
            // if (group[p] <= 1)
            // {
            //     st.erase(p);
            // }
            // if (group[h] == 2)
            // {
            //     st.insert(h);
            // }
            // dump("--");
        }
        else
        {
            // dump("--");
            int size = st.size();
            mPrint(size);
            // dump("--");
        }
    }

    return 0;
}
