#include <bits/stdc++.h>
using namespace std;
int n, m, i, x, y, parent[1001] = {-1};
int find(int u)
{
    return parent[u] ? parent[u] = find(parent[u]) : u;
}
int main()
{
    cin >> n >> m;
    if (m != n - 1)
    {
        cout << "no";
        return 0;
    }
    for (i = 1; i < n; i++)
    {
        cin >> x >> y;
        if (find(x) == find(y))
        {
            cout << "no";
            return 0;
        }

        parent[find(x)] = find(y);
    }
    cout << "yes";
    return 0;
}