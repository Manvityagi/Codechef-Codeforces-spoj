#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define MOD 1000000007
#define nline cout << "\n";
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long int lli;
typedef vector<int> vi;
typedef pair<int, int> pi;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
 
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        REP(i, 0, n)
        cin >> a[i];
        REP(i, 0, n)
        cin >> b[i];
        int k = 0, l = 0;
        int flag = 0;
        REP(i, 0, n)
        {
            int diff = a[i] - b[i];
            if (diff > 0)
            {
                flag = -1;
                break;
            }
            else if (diff != 0 && flag == 0)
            {
                flag = 1;
                k = a[i] - b[i];
            }
            else if (diff != 0 && diff != k)
            {
                flag = -1;
                break;
            }
            else if (diff == 0 && flag == 1)
            {
                flag = 2;
            }
            else if (flag == 2 && diff != 0)
            {
                flag = -1;
                break;
            }
        }
        if (flag == -1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
