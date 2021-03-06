#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main()
{
	c_p_c();
	w(t)
	{
		int n; cin >> n;
		vector<bool> done(n + 1, 0);
		int free_girl = 0;

		for (int i = 1; i <= n; ++i)
		{
			int k; cin >> k;
			int girl_done = 0;
			while (k--)
			{
				int pi; cin >> pi;

				if (girl_done)
					continue;

				//the girl isn't married yet

				if (done[pi])
					continue;

				//prince also isn't married yet
				done[pi] = 1;
				girl_done = 1;
			}

			if (girl_done == 0)
			{
				free_girl = i;
			}
		}

		if (free_girl == 0)
		{
			cout << "OPTIMAL\n";
		}

		else
		{
			cout << "IMPROVE\n";
			cout << free_girl << ' ';

			for (int i = 1; i <= n; ++i)
				if (!done[i])
				{
					cout << i << '\n';
					break;
				}
		}
	}
	return 0;
}