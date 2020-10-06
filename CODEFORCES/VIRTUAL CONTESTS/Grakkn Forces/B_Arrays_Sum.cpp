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
        vector<int> arr(n);
        bool allSame = 1;
        cin >> arr[0];  
        for(int i = 1; i < n; i++){
            cin >> arr[i];
            if(arr[i] != arr[i-1]) allSame = 0; 
        } 
        if(k >= n){ cout << "1\n"; continue;}
        if(k == 1){
            if(allSame) cout << "1\n";
            else cout << "-1" << "\n"; 
            continue;
        }
        sort(arr.begin(),arr.end()); 

        int ans = 1, diffCount = 1, i = 0, last = arr[0]; 
        for(i = 0; i < n; i++){
           if(diffCount < k || (i && arr[i-1] == arr[i])){
               if(i && arr[i-1] != arr[i]) diffCount++;
               last = arr[i];
           } else {
               ans++;
               if(arr[i-1] == arr[i]) diffCount = 1;
               else diffCount = 2;
           }
        }
        cout << ans << "\n";
    }
    return 0;
}
