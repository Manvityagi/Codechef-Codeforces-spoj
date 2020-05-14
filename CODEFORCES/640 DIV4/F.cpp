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
const int MAX_N = 200 * 1000 + 5;
char a[MAX_N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> a;
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        //total = n0+n1+n2
        //consecutive zeros = n0 + 1
        //consecutive 1s = n2+1
        // 111(10)00(01) - 2 n1 waale tp khud hi ban jayenge
        //baki 01,01,01 kar do n0+n1+n2-(n0+1+n2+1+2) = n1-4
        int total = n0 + n1 + n2+1;
        for (int i = 1; (n2 > 0 && i <= n2 + 1); i++)
        {
            a.push_back(1);
            total--;
        }
        
        bool zero = false;
        for (int i = 1; (n0 > 0 && i <= n0 + 1); i++)
        {
        	zero = true;
            a.push_back(0);
            total--;
        }
    
        int cnt = 1;

        while (n1 > 0 && total > 0)
        {
            if (cnt & 1)
            {
            	int val = (zero) ? 1 : 0;
                a.push_back(val);
            }
            else
            {
            	int val = (zero) ? 0 : 1;
                a.push_back(val);
            }
            cnt++;
            total--;
        }

        for (auto e : a)
        {
            cout << e;
        }
        cout << "\n";
    }
    return 0;
}
