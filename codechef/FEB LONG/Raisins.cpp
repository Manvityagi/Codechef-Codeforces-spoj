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
#define INF LONG_MAX
#define print(x, y) cout << x << " " << y << endl;
#define LD long double
#define PR pair<LD, LL>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    LL W, H, R;
    vector<pair<LL, LL>> raisins(R);
    for (int i = 0; i < R; i++)
    {
        LL xi, yi;
        cin >> xi >> yi;
        pair<LL, LL> cord = MP(xi, yi);
        raisins[i] = cord;
    }

    cout << 1 << 1 << 0;

    return 0;
}