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
        string a, b, c;
        cin >> a >> b >> c;

        int n = a.size();
        bool found = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i] && a[i] != c[i])
            {
                found = 1;
                cout << "NO\n";
                break;
            }

            if (c[i] != a[i] && c[i] != b[i])
            {
                found = 1;
                cout << "NO\n";
                break;
            }
        }

        if(!found){
            cout << "YES\n";
        }
    }
    return 0;
}
