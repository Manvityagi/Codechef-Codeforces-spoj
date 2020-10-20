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
    cin >> t;
    while (t--)
    {
        LL x1, y1, x2, y2; 
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == x2 || y1 == y2){
            cout << max(abs(x1-x2),abs(y1-y2)) << "\n";
            continue;
        }

        cout << abs(x1-x2) + abs(y1-y2) + 2 << "\n";

    }
    return 0;
}
