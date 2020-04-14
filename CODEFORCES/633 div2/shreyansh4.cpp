#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v[100005];
vector<int> u[100005];
vector<int> v1;
bool temp[100005];
int f[100005];
int level[100005];
int n, val;
#define mod 1000000007
void find(int *root)
{
    for (int i = 1; i <= n; i++)
    {
        if (f[i] > 1)
        {
            *root = i;
            return;
        }
        else
            ;
    }
}
void dfs(int i, int p)
{
    for (auto it : v[i])
    {
        if (it != p)
        {
            level[it] = level[i] + 1;
            dfs(it, i);
        }
        else
            ;
    }
}
void func()
{
    int i;
    for (i = 1; i <= n; i++)
    {
        int p = f[i];
        if (p == 1)
        {
            v1.push_back(i);
            temp[i] = 1;
        }
        else
            ;
    }
}
void func2(int i, int p)
{
    int gg = 0;
    for (auto it : v[i])
    {
        if (it != p)
        {
            if (temp[it])
                gg++;
        }
        else
        {
            ;
        }
    }
    if (gg > 0)
        val += gg - 1;
    for (auto it : v[i])
    {
        if (it != p)
            func2(it, i);
        else
            ;
    }
}
int main()
{
    //int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        f[x]++;
        f[y]++;
    }
    int root = 1;
    find(&root);
    level[root] = 1;
    dfs(root, -1);
    func();
    for (int i = 1; i <= n; i++)
    {
        level[i] = level[i];
    }
    for (auto it : v1)
    {
        ;
    }
    int p1 = 0, p2 = 0;
    for (auto it : v1)
    {
        int p = level[it];
        if (p % 2 == 0)
            p1++;
        else
            p2++;
    }
    int tmp;
    tmp = p1;
    p1 = p2;
    p2 = tmp;
    int ans1;
    if (p1 > 0 && p2 > 0)
        ans1 = 3;
    else
        ans1 = 1;
    int ans2;
    ans2 = n - 1;
    val = 0;
    func2(root, -1);
    ans2 = ans2 - val;
    cout << ans1 << " " << ans2;
    return 0;
}