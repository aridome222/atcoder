#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string decimalToBinary(unsigned long long n)
{
    if (n == 0)
    {
        return "0";
    }

    string binary = "";
    while (n > 0)
    {
        int remainder = n % 2;
        binary = to_string(remainder) + binary;
        n = n / 2;
    }
    return binary;
}

int main()
{
    unsigned long long n, m;
    cin >> n >> m;

    string nStr = decimalToBinary(n);
    string mStr = decimalToBinary(m);

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
