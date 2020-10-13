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
       bool found = 0; 

        if(n % 3 == 0){
            cout << n/3 << " " << 0 << " " << 0 << "\n";
            continue;
        }else if(n%5 == 0){
            cout << 0 << " " << n/5 << " " << 0 << "\n";
            continue;
        }else if(n%7 == 0){
            cout << 0 << " " << 0 << " " << n/7 << "\n";
            continue;
        }

       for(int x = 0; 3*x <= n; x++){
           for(int y = 0; 5*y <= n; y++){
               for(int z = 0; 7*z <= n; z++){
                   if(3*x + 5*y + 7*z == n){
                       cout << x << " " << y << " " << z << "\n";
                       found = 1;
                       break;
                   }
               }
               if(found) break;
           }
           if(found) break;
       }

       if(!found) cout << -1 << "\n";
    }
    return 0;
}
