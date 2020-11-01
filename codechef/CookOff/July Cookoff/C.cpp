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
#define loop(i, a, b) for (LL i = a; i < b; i++)
LL n, m;
const LL N = 101;
vector<LL> g[105];
vector<bool> prime(N + 1, 1);
LL lmt = 2 * 1e18;
vector<LL> nums(1,1);
void sieve()
{
    for (LL p = 2; p * p <= N; p++)
    {
        if (prime[p] == 1)
        {
            for (LL i = p * p; i <= N; i += p)
            {
                prime[i] = 0;
            }
        }
    }
    
    int n;
    int cnt = 0;
    for (LL i = 2; i <= 100; i++)
    {
        if (prime[i])
        {
            n = nums.size();
            LL curr = nums[n-1];
            int idx = n-1;
            if(i < lmt/curr)
            {
                nums[idx] *= i;
            }
            else
            {
                nums.resize(n+1);
                n = nums.size();
                nums[n-1] = i;
            }
        }
    }
    n = nums.size();
    nums[n-1] *= (2*3*5*7*11*13);
}
void dfs(LL u, LL level, vector<vector<LL>> &levels, LL parent = -1)
{
    if (levels.size() <= level)
    {
        levels.resize(level + 1);
    }

    levels[level].push_back(u);
    for (auto v : g[u])
    {
        if(v != parent)
            dfs(v, level + 1, levels, u);
    }
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL t = 1;
    sieve();
    // cout << nums.size() << "\n";
    // for(auto a : nums) cout << a << " ";

    cin >> t;
    while (t--)
    {
      
        cin >> n;
        loop(i,1,n+1)g[i].clear();
        for (LL i = 0; i < n - 1; i++)
        {
            LL src, dest;
            cin >> src >> dest;
            g[src].PB(dest);
            g[dest].PB(src);
        }

        vector<vector<LL>> levels;
        vector<LL> ans(n+1);

        dfs(1, 0, levels);

        int l = levels.size();
        
            //filling x on 0,3,6, 9 etc
            // cout << l << "\n";
            for (LL i = 0, j = 1, k = 2; i < l || k < l || j < l; i += 3, j += 3, k += 3)
            {
                if(i  < l)
                for (auto node : levels[i])
                {
                    // cout << "i " << node << "\n"; 
                    ans[node] = nums[0];
                }
                
                if(j < l)
                for (auto node : levels[j])
                {
                    //   cout << "j " << node << "\n"; 
                    ans[node] = nums[1];
                }

                if(k < l)
                for (auto node : levels[k])
                {
                    //   cout << "k " << node << "\n"; 
                    ans[node] = nums[2];
                }
            }
      
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}
