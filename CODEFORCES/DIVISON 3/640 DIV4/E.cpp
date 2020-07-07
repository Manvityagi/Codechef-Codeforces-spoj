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
        int n;
        cin >> n;

        vector<int> a(n);

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        unordered_map<int, int> cnt;

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            for (int j = i + 1; j < n; j++)
            {
                sum += a[j];
                if (sum > n)
                    break;
                if (freq.find(sum) != freq.end())
                {
                    cnt[sum]++;
                }
            }
            sum = 0;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (cnt[a[i]] > 0)
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
