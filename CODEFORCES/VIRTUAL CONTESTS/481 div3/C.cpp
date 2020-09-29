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
    // cin >> t;
    while (t--)
    {
        LL n, m;
        cin >> n >> m;
        vector<LL> rooms(n), letters(m); 
        for(auto &i : rooms) cin >> i;
        for(auto &i : letters) cin >> i;

        for(int i = 1; i < n; i++) rooms[i] += rooms[i-1];

        for(auto l : letters){
            //for each l, find just greater than index in rooms using binary search 
            LL idx = upper_bound(rooms.begin(),rooms.end(),l) - rooms.begin();
            if(idx && rooms[idx-1] == l) idx--;
            
            if(idx == n) idx = n-1;
        	LL rno; 
        	if(idx == 0) rno = l;  
        	else rno = l - rooms[idx-1];
            cout << idx+1 << " " << rno << "\n"; 
        }
     }
    return 0;
}
