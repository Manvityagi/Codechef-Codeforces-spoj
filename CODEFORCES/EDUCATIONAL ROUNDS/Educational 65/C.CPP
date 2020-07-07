#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
const int MAX_N = 5e5 + 5;
bool visited[MAX_N];
vector<int> group[MAX_N];
vector<int> his_groups[MAX_N];
bool done[MAX_N];
int answer[MAX_N];
vector<int> gather;

void dfs(int a)
{
    assert(!visited[a]);
    gather.PB(a);
    visited[a] = true;
    for (int g : his_groups[a])
    {
        if (!done[g])
        {
            done[g] = true;

            for (int b : group[g])
            {
                if (!visited[b])
                    dfs(b);
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);

        for (int j = 0; j < k; j++)
        {
            int x;
            scanf("%d", &x);
            group[i].PB(x);
            his_groups[x].PB(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);

            for(int x : gather)
            {
                answer[x] = gather.size();
            }

            gather.clear();
        }
    }

    for(int i = 1; i <= n; i++)
    {
        printf("%d ",answer[i]);
    }
    puts("");
    return 0;
}