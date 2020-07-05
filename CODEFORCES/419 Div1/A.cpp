#include <bits/stdc++.h>
#define pb push_back
#define sz 105
using namespace std;
typedef long long int ll;

int n, m, flag = 1;
int a[sz][sz], t[sz][sz];

vector<pair<string, int>> ans;

int main()
{
	// READ
	optimize

		int k = 1e5;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];

			if (i == 0)
				k = min(k, a[i][j]);
		}
	}

	for (int i = 0; i <= k; i++)
		func(i);

	if (flag)
		cout << -1 << endl;
	else
	{
		cout << ans.size() << endl;

		for (auto x : ans)
			cout << x.first << " " << x.second << endl;
	}

	return 0;
}
