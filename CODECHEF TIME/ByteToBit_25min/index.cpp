//start time: 8:28 am
//end time: 8:53
//hint taken: yes


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
#define INF LONG_MAX
#define pr(i,x,n) for(int ii=i;ii<n+i;ii++){cout<<x[ii]<<" ";}cout<<endl;
#define ip(i,x,n) for(int ii=i;ii<n+i;ii++){cin>>x[ii];};
#define db(x,y) cout<<x<<" "<<y<<endl;
#define N 400100
#define LD long double
#define PR pair<LD,LL>

int main() {
    int q;
    cin>>q;
    LL t,ans,x,mark;
    int i,a[3]={2,8,16};
    while(q--)
    {	cin>>t;
    	bool flag=false;
    	x=0;mark=0;
    	while(t>0)
    	{	//cout<<"tt"<<t<<endl;
    		for(i=0;i<3;++i)
    		{	mark=i;
    			if(t-a[i]<=0)
    				{flag=true;break;}
    			t-=a[i];
    		}
    		if(flag)
    			break;
    		++x;
    	}
    	ans=1LL<<x;
    	for(i=0;i<3;++i)
    	{
    		if(i==mark)
    			{cout<<ans<<" ";continue;}
    		else
    			cout<<0<<" ";
    	}
    	cout<<"\n";
    }
    return 0;
}



