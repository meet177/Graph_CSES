/**
 *    author:  Meet
 *    created: 14.01.2026 00:59:00
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

#define ll long long int
const ll INF = 4e18;
const ll MINF = -4e18;
const ll M = 1e9 + 7;
//const ll M = 998244353;
const ll M1 = 111053273;
const ll M2 = 4011052531;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define minus cout << -1 << "\n"

vector<vector<pair<ll,ll>>> adj;
vector<ll> path;
vector<ll> deg;
vector<bool> vis;

void dfs(ll ver) {
    while(!adj[ver].empty()) {
        auto [child, ind] = adj[ver].back();
        adj[ver].pop_back();
        if(vis[ind]) continue;
        vis[ind] = 1;
        dfs(child);
    }
    path.push_back(ver);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    adj.assign(n+1, {});
    vis.assign(m+1, 0);
    deg.assign(n+1, 0);

    for(ll i=1; i<=m; ++i) {
        ll u,v;
        cin >> u >> v;

        ++deg[u], ++deg[v];
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    bool poss = 1;

    //check for all degrees are even or not
    for(ll i=1; i<=n; ++i) {
        if(deg[i] & 1) {
            poss = 0;
            break;
        }
    }

    if(!poss) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    dfs(1);

    //check for connectivity
    for(ll i=1; i<=m; ++i) {
        if(!vis[i]) {
            poss = 0;
            break;
        }
    }

    if(!poss) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    reverse(whole(path));
    for(auto& ver : path) cout << ver << " ";
    cout << "\n";
    return 0;
}