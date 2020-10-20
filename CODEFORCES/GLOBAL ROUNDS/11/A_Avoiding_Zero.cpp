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
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (auto &i : a){  
            cin >> i;
            sum += i;
        }

        if (sum == 0){
            cout << "NO\n";
            continue;
        }

        sort(a.begin(),a.end()); 
        int neg = 0, pos = 0;
        int i = 0;
        for(i = 0; i < n; i++){
            if(a[i] >= 0) break;
            neg += a[i];
        }

        for(; i < n; i++){
            pos += a[i];
        }

        if(abs(pos) > abs(neg)){
            sort(a.begin(),a.end(),greater<int>()); 
        }

        cout << "YES\n";
        for(auto i : a) cout << i << " "; 
        cout << "\n";
    }
    return 0;
}
