#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vs vector<string>
#define vb vector<bool>
#define vp vector<pair<ll,ll>>
#define pll pair<ll,ll>

#define f(i,a,b) for(ll i=a; i<b; ++i)
#define fr(i,a,b) for(ll i=a-1; i>=b; --i)
#define fa(v) for(auto& it : v)
#define ff first
#define ss second
#define whole(x) (x).begin(), (x).end()

#define yes cout << "Yes\n"
#define no cout << "No\n"
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

void dfs(ll i, ll j, ll n, ll m, vs& grid) {
    if(i < 0 || j < 0 || i >= n || j >= m) return;
    if(grid[i][j] == '#') return;
    grid[i][j] = '#';
    dfs(i-1,j,n,m,grid);
    dfs(i+1,j,n,m,grid);
    dfs(i,j-1,n,m,grid);
    dfs(i,j+1,n,m,grid);   
}

int main() {
    setupIO();
    ll n,m;
    cin >> n >> m;
    vs grid(n);
    f(i,0,n) cin >> grid[i];
    ll rooms = 0;
    f(i,0,n) {
        f(j,0,m) {
            if(grid[i][j] == '#') continue;
            dfs(i,j,n,m,grid);
            rooms++;
        }
    }
    out1(rooms);
    return 0;
}

