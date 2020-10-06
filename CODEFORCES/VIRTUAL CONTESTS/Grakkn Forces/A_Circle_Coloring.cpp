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

bool helper(int idx, vector<int> currans, vector<int> &a, vector<int> &b, vector<int> &c, int &n){
    if(idx == n){
        for(auto i : currans) cout << i << " ";
        cout << "\n";
        return 1;
    }
    int prev2 = -1; 
    if(idx == n-1) prev2 = currans[0]; 

    int prev = -1;
    if(currans.size()) prev = currans.back();

    if(prev != a[idx] && prev2 != a[idx]){
        currans.emplace_back(a[idx]);
        if(helper(idx+1,currans,a,b,c,n)) return 1;
        currans.pop_back();
    }

    if(prev != b[idx] && prev2 != b[idx]){
        currans.emplace_back(b[idx]);
        if(helper(idx+1,currans,a,b,c,n)) return 1;
        currans.pop_back();
    }

    if(prev != c[idx] && prev2 != c[idx]){
        currans.emplace_back(c[idx]);
        if(helper(idx+1,currans,a,b,c,n)) return 1;
        currans.pop_back();
    }

    return 0;
}

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
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n); 

        for(auto &i : a) cin >> i; 
        for(auto &i : b) cin >> i; 
        for(auto &i : c) cin >> i;

        helper(0,{},a,b,c,n);

     }
    return 0;
}
