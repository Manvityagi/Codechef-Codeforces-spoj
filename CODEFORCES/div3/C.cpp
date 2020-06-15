
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
char a[MAX_N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_set<int> eset, oset;
        int e = 0, o = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
            {
                oset.insert(arr[i]);
                o++;
            }
            else
            {
                eset.insert(arr[i]);
                e++;
            }
        }

        // sort(arr.begin(), arr.end());

        if (e == 0 || o == 0 || (!(e & 1) && !(o & 1)) )
            {
                cout << "YES\n";
                continue;
            }
        bool found = false;
        for (auto oelt : oset)
        {
            if (eset.find(oelt + 1) != eset.end() || eset.find(oelt - 1) != eset.end())
            {
                cout << "YES\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "NO\n";
    }

    return 0;
}
