#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll st = -1, end, ans = 0, odd = 0, multiplesOf4 = 0, combine2 = 0, common = 0;
		vector<ll> a(n);
		ll p = -1, pp = -1, p0 = -1;
		for (ll i = 0; i < n; i++)
		{
			cin >> a[i];
			a[i] = abs(a[i]) % 4;

			// multiples of 4
			if (a[i] == 0)
			{
				p0 = i;
				multiplesOf4 += p0 + 1;
				// ll maxindex = min(pp,p0);
				// common += maxindex+1;
			}
			else
			{
				multiplesOf4 += p0 + 1;
			}

			//combinations of 2 making multiples of 4
			if (a[i] == 2)
			{
				combine2 += p + 1, pp = p, p = i;
				// ll maxindex = min(pp,p0);
				// common += maxindex+1;
			}
			else
				combine2 += pp + 1;

			ll maxindex = min(pp, p0);
			common += maxindex + 1;

			// odd product subarrays
			if (a[i] & 1)
			{
				if (st != -1)
					end++;
				else
					st = i, end = i;
			}
			else
			{
				if (st != -1)
				{
					ll len = end - st + 1;
					odd += len * (len + 1) / 2;
					st = -1;
				}
			}
		}

		if ((a[n - 1] & 1) && st != -1)
		{
			ll len = end - st + 1;
			odd += len * (len + 1) / 2;
		}

		ans = odd + multiplesOf4 + combine2;
		cout << ans << "\n";

		cout << "odd " << odd << "\n";
		cout << "mul4 " << multiplesOf4 << "\n";
		cout << "combine2 " << combine2 << "\n";
		cout << "common " << common << "\n";
	}

	return 0;
}
