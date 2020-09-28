#include <bits/stdc++.h>
#define pb push_back
#define sz 105
using namespace std;
typedef long long int ll;
int n, m, flag = 1;
int a[sz][sz], t[sz][sz];
vector<pair<string, int>> ans;
bool yes(int x[sz][sz])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (x[i][j])
				return false;
		}
	}

	return true;
}
void func(int x)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			t[i][j] = a[i][j];
		}
	}

	vector<pair<string, int>> tempans;

	//delete x from 1st row
	for (int i = 0; i < x; i++)
		tempans.emplace_back("row", 1);

	for (int i = 0; i < m; i++)
		t[0][i] -= x;

	//ab 0th row ke jis col me > 0 value bachi hai, unme se wo subtract kardo ,
	//aur agar kisi col me ye subtraction karte waqt value negative ho jaati hai to return kar do yahi se
	//or in other words arr[0][j] < arr[i][j] for all (0 <= j && j <= m) && for all (0 <= i && i <= m)

	for (int i = 0; i < m; i++)
	{
		int mn = 1e5;

		for (int j = 0; j < n; j++)
			mn = min(mn, t[j][i]);

		for (int j = 0; j < mn; j++)
			tempans.emplace_back("col", i + 1);

		for (int j = 0; j < n; j++)
			t[j][i] -= mn;
	}

	for (int i = 1; i < n; i++)
	{
		int mn = 1e5;

		for (int j = 0; j < m; j++)
			mn = min(mn, t[i][j]);

		for (int j = 0; j < mn; j++)
			tempans.emplace_back("row", i + 1);

		for (int j = 0; j < m; j++)
			t[i][j] -= mn;
	}

	if (yes(t))
	{
		flag = 0;
		if (ans.size() == 0)
			ans = tempans;
		else if (ans.size() > tempans.size())
			ans = tempans;
	}
}

int main()
{
	cin >> n >> m;
	int k = 1e5;
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
