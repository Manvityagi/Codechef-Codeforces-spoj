
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
#define int LL
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;
string s;

bool solve()
{
    if (s.size() < 3)
    {
        int n = stoll(s);
        if (n % 8 == 0)
            return 1;
        string temp(s);

        reverse(temp.begin(), temp.end());
        n = stoll(temp);
        if (n % 8 == 0)
            return 1;

        return 0;
    }

    unordered_map<int, int> mp;
    for (auto &i : s)
    {
        i -= '0';
        mp[i]++;
    }


    for (int i = 104; i < 1000; i += 8)
    {
        int orig = i; 
        int freq[10] = { 0 }; 
        freq[orig % 10]++; 
        orig = orig / 10; 
        freq[orig % 10]++; 
        orig = orig / 10; 
        freq[orig % 10]++; 
  
        orig = i; 
        if (freq[orig % 10] > mp[orig % 10]) 
            continue; 
        orig = orig / 10; 
  
        if (freq[orig % 10] > mp[orig % 10]) 
            continue; 
        orig = orig / 10; 
  
        if (freq[orig % 10] > mp[orig % 10]) 
            continue; 
  
        return true; 
    }
    return 0;
}

signed main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        cin >> s;
        if (solve())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}