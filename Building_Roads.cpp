#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ll long long int
#define INF LONG_LONG_MAX
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

const ll N = 1e5 + 1;
vll graph[N];
vb vis(N,0);

void dfs(ll ver) {
    vis[ver] = true;
    for(auto& child : graph[ver]) {
        if(vis[child]) continue;
        dfs(child);
    }
}

int main() {
    setupIO();
    ll n,m;
    cin >> n >> m;
    f(i,0,m) {
        ll v1,v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    vpll roads;
    ll prev = -1;
    f(i,1,n+1) {
        if(vis[i]) continue;
        dfs(i);
        if(prev == -1) {
            prev = i;
            continue;
        }
        roads.push_back(mp(prev,i));
        prev = i;
    }
    out1(roads.size());
    for(auto& road : roads) cout << road.first << " " << road.second << "\n";
    return 0;
}