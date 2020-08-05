#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n, p;
    cin >> n >> p;
    int total = 2*n + p;
    vector<pair<int, int>> ans;
    while (total > 0)
    {
        for (int i = 1; i <= n && total > 0; i++)
        {
            for (int j = i+1; j <= n && total > 0; j++) {
                ans.emplace_back(i, j);
                total--;
            }
        }
    }

    for (auto a : ans)
    {
        cout << a.first << " " << a.second << "\n";
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}