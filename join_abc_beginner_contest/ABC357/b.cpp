#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> x(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x[i][j];
        }
    }

    vector<int> sum(m, 0);
    bool flag = true;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[j] += x[i][j];
        }
        if (sum[j] < a[j])
        {
            flag = false;
        }
    }

    if (flag)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
