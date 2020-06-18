
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
const int MAX_N = 2 * 1e5;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int n = s.size();
        if(!n) {
            cout << "" << "\n";
            continue;
        }

        string ans;
        ans.push_back(s[0]);
        for(int i = 1; i < s.size(); i+=2)
        {
            ans.push_back(s[i]);
        }

        cout << s << "\n";
    }

    return 0;
}
