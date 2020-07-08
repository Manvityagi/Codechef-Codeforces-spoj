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

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    LL n, k;
    cin >> n >> k;
    vector<int> arr(n), res;
    vector<pair<int, int>> a;

    loop(i, 0, n)
    {
        cin >> arr[i];
        a.emplace_back(arr[i], i);
    }

    int i = 0;
    while (i < n && k > 0)
    {
        k -= a[i].first;
        res.push_back(a[i].second);
        i++;
    }
    cout << res.size() << "\n";
    for (auto a : res)
        cout << a << " ";

    return 0;
}
