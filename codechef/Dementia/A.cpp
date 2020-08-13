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
        LL n;
        cin >> n;
        vector<LL> a(n);
        for(auto &i : a) cin >> i;

        sort(a.begin(),a.end(),greater<int>());
        LL fc1 = 0, fc2 = 0; 
        fc1 += a[0];
        
        if(n >= 2)
        fc2 += a[1];
        
        if(n >= 3)
        fc2 += a[2];
        
        for(int i = 3; i < n; i++){
            if(i & 1) fc1 += a[i];
            else fc2 += a[i];
        }

        if(fc1 > fc2){
            cout<<"first\n";
            continue;
        }

        LL sc1 = 0,sc2 = 0;
        if(n >= 2)
            sc1 += a[1];
        if(n >= 3)
            sc1 += a[2];
        sc2 += a[0];

        for(int i = 3; i < n; i++){
            if(i & 1) sc2 += a[i];
            else sc1 += a[i];
        }

        if(sc1 > sc2){
            cout<<"second\n";
            continue;
        }
        cout <<"draw\n";
    }
    return 0;
}
