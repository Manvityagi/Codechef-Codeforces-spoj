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
        LL r,g,b,w, o= 0, e = 0;
        cin >> r >> g >> b >> w;
        // unordered_map<char,int
        if(r){
            if(r & 1) o++; 
            else e++;
        }

        if(g){
            if(g & 1) o++; 
            else e++;
        }

        if(b){
            if(b & 1) o++; 
            else e++;
        }

        if(w){
            if(w & 1) o++; 
            else e++;
        }

        if(o <= 1) {
            cout << "Yes\n";
            continue;
        }
        
        if(r == 0 || g == 0 || b == 0){
        	cout << "No\n";
        	continue;
        }
        
        if(e <= 1){
        	cout << "Yes\n";
            continue;
        }
        
        cout << "No\n";
    }
    return 0;
}
