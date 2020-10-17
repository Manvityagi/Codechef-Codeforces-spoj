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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<LL> a(n);
        for(auto &i : a) cin >> i;

        sort(a.begin(),a.end());
        if(k == 0){
            cout << a[n-1] - a[0] << "\n";
            continue;
        } 

        LL mx = a[n-1]; 
        for(int i = n-k-1 ; i < n-1; i++){
            mx += a[i]; 
        }

        cout << mx << "\n"; 
    }
    return 0;
}