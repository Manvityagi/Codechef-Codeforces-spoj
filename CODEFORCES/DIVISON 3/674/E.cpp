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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        LL a1,a2,a3,b1,b2,b3; 

        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

        LL maxWinsOfAlice = min(a1,b2) + min(a2,b3) + min(a3,b1); 

        LL maxWinsOfBob = min(b1,a2) + min(b2,a3) + min(b3,a1);

        LL minWinsOfAlice = n - maxWinsOfBob;

        cout << minWinsOfAlice << " " << maxWinsOfAlice << "\n";
     }
    return 0;
}
