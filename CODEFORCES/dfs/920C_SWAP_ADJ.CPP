// https://codeforces.com/gym/278148/problem/C
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;
 main()
{
    cin >> n;
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    string str;
    cin >> str;

    vector<int> sum(n+1);
    sum[1] = str[0] - '0';
    for (int i = 2; i <= n; i++)
    {
        sum[i] = (str[i - 1] - '0') + sum[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == i)
            continue;

        if (abs(sum[arr[i] - 1] - sum[i - 1]) != abs(arr[i] - i))
            return cout << "NO", 0;
    }
    cout << "YES";
    return 0;
}
