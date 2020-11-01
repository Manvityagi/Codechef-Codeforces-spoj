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

void erast()
{
    int n;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

static bool sortByVal(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    int t;
    cin >> t;

    while (t--)
    {
        LL n, m;
        cin >> n >> m;
        map<LL, LL> mp;
        vector<LL> fruit(n), cost(n);

        for (int i = 0; i < n; i++)
        {
            cin >> fruit[i];
        }
        
        for (int i = 0; i < n; i++)
        {
            LL c;
            cin >> c;
            mp[fruit[i]] += c;
        }

        vector<pair<LL, LL>> vec;

        // copy key-value pairs from the map to the vector
   
        for (auto it2 = mp.begin(); it2 != mp.end(); it2++)
        {
            vec.push_back(make_pair(it2->first, it2->second));
        }

        // // sort the vector by increasing order of its pair's second value
        sort(vec.begin(), vec.end(), sortByVal);


        cout << vec[0].second << endl;
    }
    return 0;
}
