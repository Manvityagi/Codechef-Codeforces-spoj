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
#define pr(i,x,n) for(int ii=i;ii<n+i;ii++){cout<<x[ii]<<" ";}cout<<"\n";
#define ip(i,x,n) for(int ii=i;ii<n+i;ii++){cin>>x[ii];};
#define db(x,y) cout<<x<<" "<<y<<"\n";
#define N 400100
#define LD long double
#define PR pair<LD,LL>

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main() {
    
static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();
    int t;
    cin>>t;
        while(t--) {
        LL n ,m;
        cin >> n >> m;
        unordered_map <LL, LL> umap;
        vector <pair <LL, LL> > v;
        for(LL i = 0 ; i < m ; i++) {
            LL u , x;
            cin >> u >> x;
            umap[u]++;
            umap[x]++;
            v.push_back(make_pair(u,x));
        }

        LL odd_degree = 0,key,odd_vertex;

         //COUNT IN MAP NUMBER OF ODD DEGREES
            for(auto el : umap)
            {
                if(el.second % 2 != 0)
                    {
                        odd_degree++;
                        key = el.first;
                        // break;
                    }
            }

        //Case1: even number of edges present
        if(m % 2 == 0) {
            cout << 1 << "\n";
            for(LL i = 0 ; i < n ; i++) {
                cout << 1 << " ";
            }
            cout << "\n";
        }
        else{
            
        //case3: odd edges && no odd degrees           
            if(odd_degree == 0){		
                cout << 3 << "\n";
                key = 0;
                for(auto entry : umap) {
                    if(entry.second && entry.second % 2 == 0) {
                        key = entry.first;
                        break;
                    }
                }

                for(auto entry : v) {
                    if(entry.first == key || entry.second == key) {
                        umap[entry.first]--;
                        umap[entry.second]--;
                    }
                }

                for(auto entry : umap) {
                    if(entry.second % 2 != 0) {
                        odd_vertex = entry.first;
                        break;
                    }
                }

                for(LL i = 1 ; i <= n ; i++) {
                    if (i == odd_vertex) {
                        cout << 1 << " ";
                    }
                    else if(i == key) {
                        cout << 2 << " ";
                    }
                    else{
                        cout << 3 << " ";
                    }
                }
                cout << "\n";
            }
            else
            //case2: odd edges && odd degrees
            if(odd_degree != 0) {
                cout << 2 << "\n";
                for(LL i = 1 ; i <= n ; i++) {
                    if(i != key) {
                        cout << 1 << " ";
                    }
                    else{
                        cout << 2 << " ";
                    }
                }
                cout << "\n";
            }
            
        }
    }
    return 0;
}




