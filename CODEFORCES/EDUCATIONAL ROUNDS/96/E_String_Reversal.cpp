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
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
#define int LL

int mergeSort(vector<int> &arr, int lo, int hi){
        if(lo >= hi) return 0; 
        int ans = 0; 
        int mid = lo+hi >> 1; 

        ans += mergeSort(arr,lo,mid);
        ans += mergeSort(arr,mid+1,hi); 

        for(int i = mid+1; i <= hi; i++){
            ans += (mid+1-(upper_bound(arr.begin()+lo,arr.begin()+mid+1,arr[i])-arr.begin()));
        }
        sort(arr.begin()+lo,arr.begin()+hi+1);
        return ans; 
}


int countInversions(vector<int> &arr){
    int n = arr.size(); 
    return mergeSort(arr,0,n-1);
}


signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    while (t--){
        int n;
        cin >> n;
        string s; 
        cin >> s; 
        map<char,queue<int>> mp;
        for(int i = 0; i < n; i++) mp[s[i]].emplace(i);
        reverse(s.begin(),s.end()); 
        vector<int> arr; 

        for(auto c : s){
            int curr = mp[c].front();
            mp[c].pop();
            arr.emplace_back(curr);
        }
        cout << countInversions(arr); 
     }
    return 0;
}
