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
#define INF LONG_MAX
#define pr(i,x,n) for(int ii=i;ii<n+i;ii++){cout<<x[ii]<<" ";}cout<<endl;
#define ip(i,x,n) for(int ii=i;ii<n+i;ii++){cin>>x[ii];};
#define db(x, y) cout << x << " " << y << endl;
#define N 400100
#define LD long double
#define PR pair<LD, LL>

vector<int> initializeDiffArray(vector<LL> &rad)
{
    int n = rad.size();
    vector<int> D(n + 1);
    D[0] = rad[0];
    D[n] = 0;
    for (auto i = 1; i < n; i++)
    {
        D[i] = rad[i] - rad[i - 1];
    }
    return D;
}

void update(vector<int> &D, int l, int r)
{
    D[l] += 1;
    D[r + 1] -= 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<LL> rad(n+1), health(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin >> rad[i];
        }

        vector<int> D = initializeDiffArray(rad);

        for (int i = 1; i <= n; i++)
        {
            int lower = i - rad[i];
            int upper = i + rad[i];
            if (lower <= 0)
                lower = 1;
            if (upper > n)
                upper = n;

            //call update from lower to upper
            update(D, lower, upper);
        }

        //get the updated rad array
        for (int i = 1; i <= rad.size(); i++)
        {
            if (i == 1)
                rad[i] = D[i];
            else
            {
                rad[i] = D[i] + rad[i - 1];
            }
        }

        // unordered_map<int, int> mp;

        for (int i = 1; i <= n; i++)
        {
            cin >> health[i];
            // mp[health[i]]++;
        }

        // bool found = false;
        // for (int i = 1; i <= n; i++)
        // {

        //     if (mp.find(rad[i]) == mp.end())
        //     {
        //         found = true;
        //         cout << "NO \n";
        //         break;
        //     }

        //     if (mp[rad[i]] == 0)
        //     {
        //         found = true;
        //         cout << "NO \n";
        //         break;
        //     }
        //     mp[rad[i]]--;
        // }

        // if (!found)
        //     cout << "YES\n";
    }
    return 0;
}
