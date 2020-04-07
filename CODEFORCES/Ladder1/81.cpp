#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int d[1000003];
 
int main() {
	for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)d[j]++;
    int a,b,c;    
    cin>>a>>b>>c;
    int ans=0;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
          for(int k=1;k<=c;k++)ans+=(d[i*j*k])%1073741824;
    cout<<ans%1073741824;
 
	return 0;
}