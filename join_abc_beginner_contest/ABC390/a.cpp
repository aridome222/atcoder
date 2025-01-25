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

int cntSwapsToSort(vector<int> &arr)
{
    int count = 0;
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
                count++;
            }
        }
    } while (swapped);
    return count;
}

int main()
{
    vector<int> a;
    rep(i, 5)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    if (cntSwapsToSort(a) == 1)
    {
        mPrint("Yes");
    }
    else
    {
        mPrint("No");
    }

    return 0;
}

// 解答
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int> a(5);
//     for (int &i : a)
//         cin >> i;
//     vector<int> ans = {1, 2, 3, 4, 5};
//     for (int i = 0; i < 4; i++)
//     {
//         vector<int> b = a;
//         swap(b[i], b[i + 1]);
//         if (b == ans)
//         {
//             cout << "Yes" << endl;
//             return 0;
//         }
//     }
//     cout << "No" << endl;
//     return 0;
// }