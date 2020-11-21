#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> nums;
int res = 0; 
int n,k;
 
void helper(int left, int right){
		if(left > right)return;
        res++;
        int newRight = upper_bound(nums.begin(),nums.end(),k-nums[right]) - nums.begin();
        left = max(left,newRight);
        helper(left,right-1);
}

signed main(){
    cin >> n >> k; 
    nums.resize(n); 
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(),nums.end());
    res = 0;
    helper(0,n-1);
    cout << res;
    return 0;
}