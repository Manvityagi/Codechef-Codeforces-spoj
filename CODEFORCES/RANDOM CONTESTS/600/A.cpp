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
int movex[] ={ 0, 0, 1, -1 };
int movey[] ={ 1, -1, 0, 0 };

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
        LL n;
        cin >> n;
        vector<LL> a(n), b(n);
        bool possible = 1;
        for (auto &i : a)
            cin >> i;

        for (auto &i : b)
            cin >> i;

        int l = n-1, r = 0, kl = 0, kr = 0;

        //find first mismatch from left
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                l = i, kl = a[i] - b[i];
                break;
            }
        }

        //find first mismatch from right
        for (int i = n-1; i >= 0; i--) {
            if (a[i] != b[i]) {
                r = i, kr = a[i] - b[i];
                break;
            }
        }
        
        if (kl != kr || kl > 0 || kr > 0) {
            possible = 0;
        }
        else
            if (l == n-1 || r == 0) {
                possible = 1;
            }
            else {
                for (int i = l; i <= r; i++) {
                    if (a[i]-b[i] != kl) {
                        possible = 0;
                        break;
                    }
                }
            }


        if (possible)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
