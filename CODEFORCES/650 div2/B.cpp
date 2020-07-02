
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
        int n;
        cin >> n;
        vector<int> arr(2 * n + 1);
        vector<int> odd, even;
        int o = 0, e = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
            if (arr[i] & 1)
            {
                odd.push_back(i + 1);
                o++;
            }
            else
            {
                even.push_back(i + 1);
                e++;
            }
        }

        if (e & 1)
        {
            //remove 1 even elt
            even.pop_back();
        }
        if (o & 1)
        {
            //remove 1 odd elt
            odd.pop_back();
        }

        if ((!(e & 1) && !(o & 1)))
        {
            if (even.size() >= 2)
            {
                even.pop_back();
                even.pop_back();
            }
            else
            {
                odd.pop_back();
                odd.pop_back();
            }
        }

        for (int i = 0; i + 1 < odd.size(); i += 2)
        {
            cout << odd[i] << " " << odd[i + 1] << "\n";
        }
        for (int i = 0; i + 1 < even.size(); i += 2)
        {
            cout << even[i] << " " << even[i + 1] << "\n";
        }
    }

    return 0;
}
