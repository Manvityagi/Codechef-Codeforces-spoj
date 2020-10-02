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
        LL n, x;
        cin >> n >> x;
        int diff = 0;
        vector<int> ratings(n), diff(n);
        bool zero = 1; 
        for(auto &i : ratings){
            cin >> i;
            diff += (x-i);
            if(i != x) zero = 0;
        } 
        if(zero){
            cout << 0 << "\n"; 
            continue;

        }

        if(diff == 0){
            cout << "1\n";
        } else {
            cout << "2\n";
        }
      
     }
    return 0;
}
