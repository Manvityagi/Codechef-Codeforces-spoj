#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main (){
	ll t;
	cin>>t;
	while(t--){
		ll n,m,evendeg=0,odddeg=0,zerodeg=0,grp=0;
		cin>>n>>m;
		ll arr[n];
		map <ll,ll> degree;
		for(ll i=1;i<=m;i++){
			ll x=0,y=0;
			cin>>x>>y;
			degree[x]++;
			degree[y]++;
		}
		for(ll i=1;i<=n;i++){

			if(degree[i] % 2 != 0){
				odddeg++;
			}
		}
		if( m%2 == 0 ){
			grp=1;
			for(ll i=0;i<n;i++){
				arr[i]=1;
			}	
		}
		else if( m%2 != 0 && odddeg == 0){
			arr[0]=1;
			arr[1]=2;
			for(ll i=2;i<n;i++){
				arr[i]=3;
			}
			grp=3;
		}
		else{
			ll x=0;
			for(ll i=0;i<n;i++){
				arr[i]=1;
			}
			for(ll i=1;i<=n;i++){
				if((degree[i]%2)!=0){
					x=i;
					break;
				}
			}
			arr[x-1]=2;
	        grp=2;	
		}
		cout<<grp<<endl;
		for( ll i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
}