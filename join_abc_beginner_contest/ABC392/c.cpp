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
    int N;
    cin >> N;

    vector<pair<int, int>> pq(N);
    rep(i, N)
    {
        cin >> pq[i].first;
    }
    rep(i, N)
    {
        cin >> pq[i].second;
    }

    // ゼッケン番号をキーとして、見つめている人を返す
    unordered_map<int, int> zekkenToHuman(N + 1);
    // 人iをキーとして、ゼッケン番号を返す
    unordered_map<int, int> humanToZekken(N + 1);
    rep(i, N)
    {
        zekkenToHuman[pq[i].second] = pq[i].first;
        // dump(pq[i].second);
        // dump(zekkenToHuman[pq[i].second]);
    }
    rep3(i, 1, N + 1)
    {
        humanToZekken[i] = pq[i - 1].second;
        // dump(pq[i - 1].second);
        // dump(humanToZekken[i]);
    }
    // // second（2番目の要素）でソート
    // sort(pq.begin(), pq.end(), [](const pair<int, int> &a, const pair<int, int> &b)
    //      { return a.second < b.second; });

    rep3(i, 1, N + 1)
    {
        cout << humanToZekken[zekkenToHuman[i]] << " ";
    }
    cout << endl;

    return 0;
}
