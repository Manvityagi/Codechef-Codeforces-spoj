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
#define all(a) a.begin(), a.end()
#define loop(i, a, b) for (int i = a; i < b; i++)
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
#define int LL 
int findX(int A, int B)
{
    int j = 0, x = 0;
    while (A || B)
    {
        if ((A & 1) && (B & 1))
            x += (1 << j);

        A >>= 1;
        B >>= 1;
        j += 1;
    }
    return x;
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        LL a, b;
        cin >> a >> b;

        LL X = findX(a, b);

        cout << (a ^ X) + (b ^ X) << "\n";
    }
    return 0;
}
