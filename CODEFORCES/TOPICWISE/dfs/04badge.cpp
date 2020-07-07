#include <bits/stdc++.h>
using namespace std;

int a[1234567];

int n;

vector<int> visited;

int dfs(int i)
{
    if (visited[i])
    {
        return i;
    }

    visited[i] = 1;

    return dfs(a[i]);
}

int main()
{
    scanf("%d", &n);
    visited.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dfs(i) << " ";
        std::fill(visited.begin(), visited.end(), 0);
    }

    return 0;
}