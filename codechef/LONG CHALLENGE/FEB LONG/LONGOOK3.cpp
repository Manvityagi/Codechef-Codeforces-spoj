//
//-------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define DEBUG(a) cout<<#a<<':'<<a<<endl;
#define DEBUGL(l,a) cout<<"l:"<<l<<' '<<#a<<':'<<a<<endl;
#define pb push_back
#define mp make_pair
#define MIN min_element
#define ACML accumulate
#define btoe(v) ((v).begin()),((v).end())
#define F first
#define S second
#define L length()
#define SZ size()

typedef unsigned long long int ulli;
typedef unsigned long long int ull;
typedef long long int lli;
typedef long long int ll;
#define f(i,a,b) for(int i=(a); i<(b); ++i)
#define fr(i,a,b) for(int i=(a); i>(b); --i)

#define fl(i,a,b) for(lli i=(a); i<(b); ++i)
#define flr(i,a,b) for(lli i=(a); i>(b); --i)

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

typedef pair<ulli,ulli> pulli;
typedef vector<ulli> vulli;
typedef vector<vulli> vvulli;
typedef vector<pulli> vpulli;

typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<vlli> vvlli;
typedef vector<plli> vplli;
#define PRIME 1000000007
int itmp1, itmp2;
char ctmp1, ctmp2;
ulli ullitmp1, ullitmp2;

const long long int MAX = 100000000;  //8
int ps[MAX];


bool isLeap(lli y) //1based indexing
{
    if(y%400 == 0 || (y%4 == 0 && y%100 !=0))
        return true;
    return false;
}

void solve(lli m1, lli y1, lli m2, lli y2)
{
    if(m1>2)
        y1++;
    if(m2<2)
        y2--;
    lli ans=0;
    //mon = 0, tue = 1, wed = 2, thur = 3
    for(lli y=y1; y<=y2; ++y)
    {
        int nly = (y/400 + y/4 - y/100);
        if(isLeap(y)) nly--;
        int day = ((y-1)%7 + nly%7)%7;
      
        if(!isLeap(y) and day==3) //thur
            ++ans;
        else if(day==2) //wed
            ++ans;
    }
    cout<<ans<<endl;
} 

void solve2(lli m1, lli y1, lli m2, lli y2)
{
    lli f1 = ceil(y1/(double)400);
    lli f2 = y1/(double)400;
    lli yy1 = 400*f1;
    lli yy2 = 400*f2;
    lli ans = ((yy2-yy1)/4)*101;

    if(m1>2)
        y1++;
    if(m2<2)
        y2--;
    //mon = 0, tue = 1, wed = 2, thur = 3
    for(lli y=y1; y<yy1; ++y)
    {
        int nly = (y/400 + y/4 - y/100);
        if(isLeap(y)) nly--;
        int day = ((y-1)%7 + nly%7)%7;
        //if(y==y1 || y==y2)
        //    cout<<y<<" : "<<day<<endl;
        if(!isLeap(y) and day==3) //thur
            ++ans;
        else if(day==2) //wed
            ++ans;
    }
    for(lli y=yy2+1; y<=y2; ++y)
    {
        int nly = (y/400 + y/4 - y/100);
        if(isLeap(y)) nly--;
        int day = ((y-1)%7 + nly%7)%7;
        //if(y==y1 || y==y2)
        //    cout<<y<<" : "<<day<<endl;
        if(!isLeap(y) and day==3) //thur
            ++ans;
        else if(day==2) //wed
            ++ans;
    }
    cout<<ans<<endl;
} 

ulli func(lli m, ulli y2)
{
    if(m==0) {m=12;y2--;}
    if(y2==0) return 0;
    lli y4 = y2/400;
    lli ans = y4*101;
    y4 = y4*400 + 1;
    //DEBUG(y4);

    if(m==1)
        y2--;
    //mon = 0, tue = 1, wed = 2, thur = 3
    for(lli y=y4; y<=y2; ++y)
    {
        int nly = (y/400 + y/4 - y/100);
        if(isLeap(y)) nly--;
        int day = ((y-1)%7 + nly%7)%7;
      
        if(!isLeap(y) and day==3) //thur
            ++ans;
        else if(day==2) //wed
            ++ans;
    }
    return ans;
}

void make_ps()
{
    ps[0] = 0;
    for(lli y=1; y<=MAX; ++y)
    {
        int nly = (y/400 + y/4 - y/100);
        if(isLeap(y)) nly--;
        int day = ((y-1)%7 + nly%7)%7;
        //DEBUG(y);
        //DEBUG(day);
        if(!isLeap(y) and day==3) //thur
            ps[y]=1+ps[y-1];
        else if(day==2) //wed
            ps[y]=1+ps[y-1];
        else
            ps[y]=ps[y-1];
    }
}

int main()
{
    //Option1, make prefix sum after program start
    //Option2, make prefix sum before program start

    int t; cin>>t;
    while(t--)
    {
        lli m1,y1,m2,y2;
        cin>>m1>>y1>>m2>>y2;
    
        cout<<func(m2,y2)-func(m1-1,y1)<<endl;
    }
    return 0;
}

