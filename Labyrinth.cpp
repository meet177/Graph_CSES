#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define IM INT_MAX
#define LLM LONG_LONG_MAX
#define ll long long int
#define pll pair<ll,ll>

#define vll vector<ll>
#define vpll vector<pll>
#define vb vector<bool>
#define vs vector<string>

#define vvll vector<vector<ll>>
#define vvpll vector<vector<pll>>
#define vvb vector<vector<bool>>
#define vvs vector<vector<string>>

#define f(i,a,b) for(ll i=a; i<b; ++i)
#define fr(i,a,b) for(ll i=a-1; i>=b; --i)
#define fa(v) for(auto& it : v)
#define ff first
#define ss second
#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define out1(x) cout << (x) << "\n"
#define out2(x,y) cout << (x) << " " << (y) << "\n"
#define out3(x,y,z) cout << (x) << " " << (y) << " " << (z) << "\n"

#define inarr(x) f(i,0,n) cin >> x[i];
#define outarr(x) f(i,0,n) cout << x[i] << " "; cout << "\n";

const ll M = 1e9 + 7;

void setupIO() {
    ios_base::sync_with_stdio(false); //disables the sync between ios and stdio
    cin.tie(0); //untie cin and cout
    cout.tie(0); //optional
}

vvll movements = {{0,1},{0,-1},{1,0},{-1,0}};

bool isValid(ll i, ll j, vs& grid) {
    ll n = grid.size();
    ll m = grid[0].size();
    return (i >= 0 && i < n && j >= 0 && j < m && (grid[i][j] == '.' || grid[i][j] == 'B'));
}

char dir(ll i, ll j, ll par_i, ll par_j) {
    if(par_i > i) return 'U';
    if(par_i < i) return 'D';
    if(par_j > j) return 'L';
    return 'R';
}

int main() {
    setupIO();
    ll n,m;
    cin >> n >> m;
    vs grid(n);
    f(i,0,n) cin >> grid[i];
    pll src, dst;
    f(i,0,n) {
        f(j,0,m) {
            if(grid[i][j] == 'A') src = mp(i,j);
            else if(grid[i][j] == 'B') dst = mp(i,j);
        }
    }
    vvpll par(n, vpll(m, {IM, IM}));
    queue<pll> q;
    q.push(src);
    par[src.ff][src.ss] = {-1,-1};
    // lev[src.first][src.second] = 0;
    while(q.size()) {
        pll ver = q.front(); q.pop();
        ll x = ver.ff;
        ll y = ver.ss;
        // out2(x,y);
        for(auto& move : movements) {
            ll child_x = x + move[0];
            ll child_y = y + move[1];
            if(!isValid(child_x,child_y,grid)) continue;
            if(par[child_x][child_y].first != IM) continue;
            par[child_x][child_y] = mp(x,y);
            q.push(mp(child_x,child_y));
        }
    }
    // f(i,0,n) {
    //     f(j,0,m) {
    //         cout << par[i][j].first << " " << par[i][j].second << "\n";
    //     }
    // }
    if(par[dst.ff][dst.ss].first == IM) {
        no;
        return 0;
    }
    string path;
    pll curr = dst;
    while(curr != src) {
        // cout << curr.first << " " << curr.second << "\n";
        pll parent = par[curr.ff][curr.ss];
        // cout << dir(curr.ff,curr.ss,parent.ff,parent.ss) << "\n";
        path.push_back(dir(curr.ff,curr.ss,parent.ff,parent.ss));
        curr = parent;
    }
    reverse(whole(path));
    yes;
    out1(path.size());
    out1(path);
    return 0;
}