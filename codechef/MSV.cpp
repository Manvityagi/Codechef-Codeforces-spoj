#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll x,ans=0;
		cin>>x;
		unordered_map <ll,ll> map;
		ll arr[x];

		for(ll k=0;k<x;k++){
			cin>>arr[k];
			ll n=arr[k];
			ans=max(ans,map[arr[k]]);
			for(ll i=1;i<=sqrt(n);i++){
				if(n%i==0){
                    map[i]++;
                    if(n/i != i)
                        map[n/i]++;
				}
			}
	    }
	    cout<<ans<<endl;
	}
}