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
        priority_queue<int> pq;
        for(int i = 1; i <= n; i++){
            pq.push(i); 
        }
        vector<pair<int,int>> ans;
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top(); 
            pq.pop(); 
            ans.emplace_back(a,b); 
            pq.push((a+b+1)/2); 
        }
    
    cout << pq.top() << "\n";
    for(auto p : ans){
        cout << p.F << " " << p.S << "\n";
    } 
    cout << "\n";
        
    }
    return 0;
}
