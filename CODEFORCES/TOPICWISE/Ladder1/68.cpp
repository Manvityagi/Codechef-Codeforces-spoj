#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ppi pair<int, int>
int main()
{
    int n;
    cin >> n;
    vector<int> wt(n);
    ll sum = 0, x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
        if (wt[i] == 100)
            x++;
    }

    if ((n % 2 == 0 && x % 2 == 0) || (n % 2 == 1 && x % 2 == 0 && x >= 2))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}