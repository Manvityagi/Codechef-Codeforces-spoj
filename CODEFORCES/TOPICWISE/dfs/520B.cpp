#include <bits/stdc++.h>
using namespace std;
const int maxN = 2*1e4;

unordered_map<int, int> mp;
int dfs(int n, int m)
{
	// cout << "DFS " << n << " " << m << "\n";
	if(n <= 0 || n >= 2*m){
		return maxN;
	}
    if(mp.find(n) != mp.end())
    {
        return mp[n];
    }

    if (n == m)
    {
        mp[n] = 0;
        return 0;
    }


    int op1 = dfs(n * 2,m);
    int op2 = dfs(n - 1,m);
    // cout << op1 << " " << op2 << "\n";

    int ans = min(op1, op2)+1;
    mp[n] = ans;

    return ans;
}

int main()
{
	int n, m;
    cin >> n >> m;
    mp.clear();
    cout << dfs(n,m);
}