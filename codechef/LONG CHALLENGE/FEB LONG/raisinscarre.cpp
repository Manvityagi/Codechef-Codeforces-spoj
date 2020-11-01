#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = int (1e9) + int (1e5);
const ll INFL = ll(2e18) + ll(1e10);
#define FOR(i,n) for (int i=0;i<(n);++i)
#define MP make_pair
#define SIGN(x) ( ((x) > 0) - ((x) < 0)  )
#define dbg(x) cerr << #x"= " << x << endl

const int Seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64  generator(Seed);

void READ(bool _local){
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _DEBUG
    if (_local)
        freopen ("in.txt", "r", stdin);
#endif
}
struct Tiempo {
public:
    Tiempo(){start();}
    Tiempo(float _tlimit) : tlimit(_tlimit) {start();}

    bool salir() const { return elapsed() > tlimit; }

    void start() { init_t = clock_::now(); isrunning=true;}
    void finish() { final_t = clock_::now(); isrunning=false;}

    float elapsed() const {
        if (isrunning)
            return std::chrono::duration_cast<second_>(clock_::now() - init_t).count();
        return std::chrono::duration_cast<second_>(final_t - init_t).count();
    }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> init_t,final_t;
    float tlimit;
    bool isrunning;
};

const int W=720720;
const int R=1E5;
const int limit = 1024;

struct pt {
    int x, y;
    pt(){}
    pt(int x,int y) : x(x),y(y){}
};
bool cmp(const pt &a, const pt &b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(const pt &a, const pt &b, const pt &c) {
    return (ll)a.x*(b.y-c.y)+(ll)b.x*(c.y-a.y)+(ll)c.x*(a.y-b.y) < 0;
}

bool ccw(const pt &a, const pt &b, const pt &c) {
    return (ll)a.x*(b.y-c.y)+(ll)b.x*(c.y-a.y)+(ll)c.x*(a.y-b.y) > 0;
}
ll dist(const pt &a,const pt &b){
    ll x=a.x-b.x, y=a.y-b.y;
    return x*x+y*y;
}



struct CH {
public:
    vector<pt> puntos;
    vector<pt> up,down;
    CH(){}
    CH(vector<pt> &a){build(a);}

    void build(vector<pt> a) {
        if (a.size() < 2) {
            puntos = a;
            return;
        }
        if (a.size()==2){
            if (a[0].x==a[1].x && a[0].y==a[1].y) puntos={a[0]};
            else puntos=a;
            return;
        }
        sort(a.begin(), a.end(), &cmp);
        pt p1 = a[0], p2 = a.back();
        up.clear(),down.clear();
        up.push_back(p1);
        down.push_back(p1);
        for (int i = 1; i < (int) a.size(); i++) {
            if (i == (int)a.size() - 1 || cw(p1, a[i], p2)) {
                while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], a[i]))
                    up.pop_back();
                up.push_back(a[i]);
            }
            if (i == (int)a.size() - 1 || ccw(p1, a[i], p2)) {
                while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], a[i]))
                    down.pop_back();
                down.push_back(a[i]);
            }
        }

        puntos.resize(up.size()+down.size()-2);
        int i;
        for (i = 0; i < (int) up.size(); i++)
            puntos[i]=up[i];
        for (int j = down.size() - 2; j > 0; j--, ++i)
            puntos[i]=down[j];
    }


    ll area(){
        if (puntos.size()<3) return 0;
        ll area= (ll)puntos.back().y*puntos[0].x - (ll)puntos.back().x*puntos[0].y;
        for(int i=0;i+1<(int)puntos.size();++i){
            area += (ll)puntos[i].y*puntos[i+1].x- (ll)puntos[i].x*puntos[i+1].y;
        }
        return area;
    }
    ll diameter() {// devuelve la máxima distancia (al cuadrado) entre 2 puntos del hull
        int n=puntos.size();
        vector<pt> hull(n+1);
        hull[0]=down[0];
        for(int j=1,i=n-1;i>=0;--i,++j) hull[j]=puntos[i];
        ll ans = 0;
        for (int i = 0, j = 1; i < n; ++i) {
            while (dist(hull[i], hull[j + 1]) > dist(hull[i], hull[j])) {
                if (++j==n) j=0;
            }
            ans = max(ans, dist(hull[i], hull[j]));
            ans = max(ans, dist(hull[i + 1], hull[j + 1]));
        }
        return ans;
    }

    bool inner(const pt &p){//indica si un punto es interior al hull (los puntos del hull no lo son)
        for(int i=0;i+1<(int)puntos.size();++i){
            if (!cw(p,puntos[i],puntos[i+1])) return false;
        }
        return cw(p,puntos.back(),puntos[0]);
    }
};

struct Zona {
    CH r;
    CH spe[4];
    ll val_spe[4];
    int left, right, up, down;

    void build(vector<pt> &a,int w){
        r.build(a);
        fill_vals(w);
    }

    void fill_vals(int w){
        vector<pt> puntos=r.puntos;
        puntos.emplace_back(w,W-w);
        puntos.emplace_back(W-w,W-w);
        puntos.emplace_back(W-w,w);
        spe[0].build(puntos);
        val_spe[0]=spe[0].area();

        int j=puntos.size()-1;
        puntos[j] = pt(W-w,0);
        puntos[j-1] = pt(W-w,-W+2*w);
        puntos[j-2] = pt(w,-W+2*w);
        spe[1].build(puntos);
        val_spe[1]=spe[1].area();

        puntos[j] = pt(0,-W+2*w);
        puntos[j-1] = pt(-W+2*w,-W+2*w);
        puntos[j-2] = pt(-W+2*w,0);
        spe[2].build(puntos);
        val_spe[2]=spe[2].area();;

        puntos[j] = pt(-W+2*w,w);
        puntos[j-1] = pt(-W+2*w,W-w);
        puntos[j-2] = pt(0,W-w);
        spe[3].build(puntos);
        val_spe[3]=spe[3].area();

        left=down=w; right=up=0;
        for(const auto &p:r.puntos){
            if (p.x<left) left=p.x;
            else if (p.x>right) right=p.x;
            if (p.y<down) down=p.y;
            else if (p.y>up) up=p.y;
        }
    };
};


struct State{
    vvi z;
    vii op;
    ll area;
    CH r;
    State(){}
    void buildCH(int N,int w,const vector<Zona> &zonas){
        vector<pt> puntos;
        FOR(i,N){
            for(const auto &p:zonas[z[i][0]].r.puntos){
                puntos.emplace_back(p.x, p.y + i*w);
            }
            for(const auto &p:zonas[z[i][29]].r.puntos){
                puntos.emplace_back(p.x + (29)*w, p.y + i*w);
            }
        }
        FOR(i,N){
            for(const auto &p:zonas[z[0][i]].r.puntos){
                puntos.emplace_back(p.x + i*w, p.y);
            }
            for(const auto &p:zonas[z[29][i]].r.puntos){
                puntos.emplace_back(p.x + i*w, p.y + (29)*w);
            }
        }
        r.build(puntos);
        area=r.area();
    }

};
vector<pt> puntos0;
struct Solution{
    bool doit;
    int N,w;
    vector<Zona> zonas;
    State state;

    Solution(int _N):doit(1),N(_N),w(W/N){
        state.z.resize(N,vi(N));
        build();
        FOR(i,N) FOR(j,N) state.z[i][j] = i*N+j;

        vi vert={0,1,2,3};
        for(int i=0;i<4;++i) {
            for (int j = 0; j < 900; ++j) {
                if (zonas[j].val_spe[i] < zonas[vert[i]].val_spe[i]){
                    bool doit=true;
                    for(int k=0;k<i;++k){
                        if (vert[k]==j) {doit=false; break;}
                    }
                    if (doit) vert[i]=j;
                }
            }
        }
        poner(vert);
        state.buildCH(N,w,zonas);
    }

    int getrow(pt &p){
        return p.y/w;
    }
    int getcol(pt &p){
        return p.x/w;
    }

    void findrowcol(int z,int &row,int &col){
        if (state.z[z/N][z%N] == z){
            row=z/N,col=z%N;
            return;
        }
        for(row=0;row<N;++row) {
            for (col = 0; col < N; ++col) {
                if (state.z[row][col] == z) {
                    return;
                }
            }
        }
        assert(false);
    }

    void rotate_col(vvi &x,int col,int idx){
        vi v(N);
        FOR(i,N) v[i] = x[i][col];
        rotate(v.begin(),v.begin()+idx,v.end());
        FOR(i,N) x[i][col] = v[i];
    }

    void build(){
        zonas.resize(900);
        vector<pt> pp[N][N];
        FOR(i,R){
            int x=puntos0[i].x;
            int y=puntos0[i].y;
            pp[y/w][x/w].emplace_back(x%w,y%w);
        }
        FOR(i,N)
            FOR(j,N)
                zonas[i*N+j].build(pp[i][j],w);

    }

    void poner(vi z){
        vi row(4),col(4);
        FOR(i,2){
            row[i] = z[i]/N;
            col[i] = z[i] %N;
        }
        if (row[1]==0){
            rotate_col(state.z,col[1],29);
            state.op.push_back(ii(2,col[1]));
            row[1]=1;
        }
        if (row[0]){
            rotate_col(state.z,col[0],row[0]);
            state.op.resize(state.op.size() + N - row[0],ii(2,col[0]));
            if (col[1]==col[0]) row[1] = (row[1] + N-row[0])%N;
            row[0]=0;
        }
        if (col[0]){
            rotate(state.z[row[0]].begin(),state.z[row[0]].begin() + col[0],state.z[row[0]].end());
            state.op.resize(state.op.size() + N - col[0],ii(1,row[0]));
            col[0]=0;
        }
        if (col[1]!=29){
            rotate(state.z[row[1]].begin(),state.z[row[1]].begin() + col[1]+1,state.z[row[1]].end());
            state.op.resize(state.op.size() + N - col[1]-1,ii(1,row[1]));
            col[1]=29;
        }
        if (row[1]){
            rotate_col(state.z,col[1],row[1]);
            state.op.resize(state.op.size() + N - row[1],ii(2,col[1]));
            row[1]=0;
        }

        findrowcol(z[2],row[2],col[2]);
        findrowcol(z[3],row[3],col[3]);

        if (col[2]==col[3]){
            while (row[2]==0 || row[3]==0){
                rotate_col(state.z,col[2],29);
                state.op.emplace_back(2,col[2]);
                if (++row[2]==N) row[2]=0;
                if (++row[3]==N) row[3]=0;
            }
            rotate(state.z[row[3]].begin(),state.z[row[3]].begin()+29,state.z[row[3]].end());
            state.op.emplace_back(1,row[3]);
            if (++col[3]==N) col[3]=0;
        }

        while(row[2]!=29 || row[3] !=29 || col[2]+1!=col[3]){
            if (row[2]==0) {
                rotate_col(state.z,col[2],29);
                state.op.emplace_back(2,col[2]);
                row[2]=1;
            }
            if (row[3]==0) {
                rotate_col(state.z,col[3],29);
                state.op.emplace_back(2,col[3]);
                row[3]=1;
            }
            if (row[2]==row[3]){
                while(col[2]==0 || col[2]==29 || col[3]==0 || col[3]==29){
                    rotate(state.z[row[3]].begin(),state.z[row[3]].begin()+29,state.z[row[3]].end());
                    state.op.emplace_back(1,row[3]);
                    if (++col[3]==N) col[3]=0;
                    if (++col[2]==N) col[2]=0;
                }
                if (col[2]+1==col[3]){
                    if (row[2]!=29) {
                        rotate_col(state.z,col[2],row[2]+1);
                        state.op.resize(state.op.size() + N-row[2]-1,ii(2,col[2]));
                        row[2]=29;
                        rotate_col(state.z,col[3],row[3]+1);
                        state.op.resize(state.op.size() + N-row[3]-1,ii(2,col[3]));
                        row[3]=29;
                    }
                }else{
                    rotate(state.z[row[3]].begin(),state.z[row[3]].begin()+29,state.z[row[3]].end());
                    state.op.emplace_back(1,row[3]);
                    if (++col[3]==N) col[3]=0;
                }
            }else{
                if (col[3]==29 && row[3]!=29){
                    rotate(state.z[row[3]].begin(),state.z[row[3]].begin()+N-3,state.z[row[3]].end());
                    state.op.resize(state.op.size()+3,ii(1,row[3]));
                    col[3]=2;
                }else if (col[2]==N-2 || col[2]==29){
                    rotate(state.z[row[2]].begin(),state.z[row[2]].begin()+col[2]-1,state.z[row[2]].end());
                    state.op.resize(state.op.size()+N-col[2]+1,ii(1,row[2]));
                    col[2]=1;
                }else if (col[3]<col[2]){
                    rotate(state.z[row[3]].begin(),state.z[row[3]].begin()+N-(col[2]-col[3]+1),state.z[row[3]].end());
                    state.op.resize(state.op.size()+col[2]-col[3]+1,ii(1,row[3]));
                    col[3] = col[2]+1;
                }else if (col[2]+1!=col[3]){
                    rotate(state.z[row[2]].begin(),state.z[row[2]].begin()+N-(col[3]-col[2]-1),state.z[row[2]].end());
                    state.op.resize(state.op.size()+col[3]-col[2]-1,ii(1,row[2]));
                    col[2] = col[3]-1;
                }else if (col[2]!=0){
                    rotate_col(state.z,col[2],row[2]+1);
                    rotate_col(state.z,col[3],row[3]+1);
                    state.op.resize(state.op.size()+N-row[2]-1,ii(2,col[2]));
                    state.op.resize(state.op.size()+N-row[3]-1,ii(2,col[3]));
                    row[2]=row[3]=29;
                }else{
                    rotate(state.z[row[2]].begin(),state.z[row[2]].begin()+29,state.z[row[2]].end());
                    state.op.emplace_back(1,row[2]);
                    ++col[2];
                }
            }
        }

        if (col[3]){
            rotate(state.z[row[3]].begin(),state.z[row[3]].begin()+col[3],state.z[row[3]].end());
            state.op.resize(state.op.size()+N-col[3],ii(1,row[3]));
            col[3]=0;
            col[2]=29;
        }
    }

    void dorow(int desde,int start,int fin,const vector<bool> &user){
        for (int i = desde; i+desde < N; ++i) {
            if (!user[i]) continue;
            int val = zonas[state.z[i][29]].right - zonas[state.z[i][0]].left;
            int best = 0;
            for (int j = start; j > fin; --j) {
                int val2 = zonas[state.z[i][j - 1]].right - zonas[state.z[i][j]].left;
                if (val2 < val) {
                    val = val2;
                    best = j;
                }
            }
            if (best != 0 && state.op.size() + N - best <= limit) {
                rotate(state.z[i].begin(), state.z[i].begin() + best, state.z[i].end());
                state.op.resize(state.op.size() + N - best, ii(1, i));
                doit=true;
            }
        }
    }

    void docol(int desde,int start,int fin,const vector<bool> &usec){
        for (int i = desde; i+desde  < N; ++i) {
            if (!usec[i]) continue;
            int val = zonas[state.z[29][i]].up - zonas[state.z[0][i]].down;
            int best = 0;
            for (int j = start; j > fin; --j) {
                int val2 = zonas[state.z[(j - 1)][i]].up - zonas[state.z[j][i]].down;
                if (val2 < val) {
                    val = val2;
                    best = j;
                }
            }
            if (best != 0 && state.op.size() + N - best <= limit) {
                rotate_col(state.z, i, best);
                state.op.resize(state.op.size() + N - best, ii(2, i));
                doit=true;
            }
        }
    }

    void solve(int desde){
        if (!doit) return;
        doit=false;
        if (state.op.size()==limit) return;
        vector<bool> user(N,false);
        vector<bool> usec(N,false);
        for(auto p:state.r.puntos){
            user[getrow(p)]=1;
            usec[getcol(p)]=1;
        }
        if (rand()%2){
            dorow(desde,29,25,user);
            docol(desde,29,25,usec);
            if (doit || state.op.size()+5>limit) return;
            dorow(desde,25,20,user);
            docol(desde,25,20,usec);
            if (doit || state.op.size()+10>limit) return;
            dorow(desde,20,15,user);
            docol(desde,20,15,usec);
            if (doit || state.op.size()+15>limit) return;
            dorow(desde,15,10,user);
            docol(desde,15,10,usec);
            if (doit || state.op.size()+20>limit) return;
            dorow(desde,10,5,user);
            docol(desde,10,5,usec);
            if (doit || state.op.size()+25>limit) return;
            dorow(desde,5,0,user);
            docol(desde,5,0,usec);
        }else{
            docol(desde,29,25,usec);
            dorow(desde,29,25,user);
            if (doit || state.op.size()+5>limit) return;
            docol(desde,25,20,usec);
            dorow(desde,25,20,user);
            if (doit || state.op.size()+10>limit) return;
            docol(desde,20,15,usec);
            dorow(desde,20,15,user);
            if (doit || state.op.size()+15>limit) return;
            docol(desde,15,10,usec);
            dorow(desde,15,10,user);
            if (doit || state.op.size()+20>limit) return;
            docol(desde,10,5,usec);
            dorow(desde,10,5,user);
            if (doit || state.op.size()+25>limit) return;
            docol(desde,5,0,usec);
            dorow(desde,5,0,user);
        }
    }
    void buildCH(){
        state.buildCH(N,w,zonas);
    }
};




void read(){
    int a,b,c;cin>>a>>b>>c;
    puntos0.resize(R);
    FOR(i,R){
        int x,y;cin>>x>>y;
        puntos0[i].x=x;
        puntos0[i].y=y;
    }
}

void write(int N,const vii &best){
    cout << N <<" "  << N << " " << best.size() << '\n';
    for(auto &p:best) cout << p.first << " " << p.second+1 << '\n';
}


int main(){
    //gen();
    srand(Seed);
    READ(1);
    read();
    Tiempo tiempo(4.95);

    Solution sol0=Solution(30);
    auto sol=sol0;

    auto bestarea=INFL;
    vii bestop;


    int loop=0;
    while (!tiempo.salir()) {
        sol.solve(++loop<4);
        if (sol.doit) {
            sol.buildCH();
            if (sol.state.area < bestarea) {
                bestarea = sol.state.area;
                bestop = sol.state.op;
            }
        }else if (loop<4 && sol.state.op.size()<limit){
            sol.doit=true;
            loop=4;
        }else{
            sol=sol0;
            loop=0;
        }

    }
    write(30,bestop);
}