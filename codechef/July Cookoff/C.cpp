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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
const int N = 101;
vector<int> g[102];
bool prime[N + 1];
LL x, y;
void sieve()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p < N; p++)
    {
        if (prime[p] == 1)
        {
            for (int i = p * p; i <= n; i++)
            {
                prime[i] = 0;
            }
        }
    }
    bool flag = 1;
    for (int i = 2; i <= 100; i++)
    {
        if (prime[i])
        {
            if (flag)
                x *= i;
            else
                y *= i;

            flag = !flag;
        }
    }
}
int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    sieve();
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        for (int i = 0; i < n - 1; i++)
        {
            int src, dest;
            cin >> src >> dest;
            g[src].PB(dest);
            g[dest].PB(src);
        }

        vector<int> ans(n);

        BFS();
    }

    return 0;
}
