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
        LL n, m;
        cin >> n >> m;
        vector<LL> a(n), b(m);
        bool possible = 0;
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int ans, i = 0, j = 0;
        while (i < n && j < m)
        {
            if(a[i] == b[j]){
                ans = a[i];
                possible = 1;
                break;
            }
            else if(a[i] < b[j]){
                i++;
            }
            else{
                j++;
            }
        }


        if (possible) {
            cout << "YES\n";
            cout << 1 << " " << ans << "\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}
