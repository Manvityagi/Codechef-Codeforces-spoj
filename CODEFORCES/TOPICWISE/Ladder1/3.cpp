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

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

   
        int n, t;
        cin >> n >> t;
        string s;
        cin >> s;
        //optimization - store  position of firts girl from end and then do the process reverse 
        while (t--)
        {
            for (int i = 0; i < n-2; i++)
            {
                if(s[i] == 'B' && s[i+1] == 'G'){
                    s[i+1] = 'B';
                    s[i] = 'G';
                    i++;
                }
            } 
        }

        cout << s;
    
    return 0;
}
