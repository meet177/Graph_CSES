/**
 *    author:  Meet
 *    created: 11.01.2026 22:49:40
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

vector<vector<ll>> adj, rev_adj;
vector<bool> vis;
vector<ll> kingdom;

stack<ll> stk;

void dfs1(ll ver) {
    vis[ver] = 1;

    for(auto& child : adj[ver]) {
        if(vis[child]) continue;
        dfs1(child);
    }
    stk.push(ver);
}

void dfs2(ll ver, ll num) {
    vis[ver] = 1;

    kingdom[ver] = num;

    for(auto& child : rev_adj[ver]) {
        if(vis[child]) continue;
        dfs2(child, num);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    adj.assign(n+1, {});
    rev_adj.assign(n+1, {});
    vis.assign(n+1, 0);
    kingdom.assign(n+1, 0);

    for(ll i=0; i<m; ++i) {
        ll u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for(ll i=1; i<=n; ++i) {
        if(vis[i]) continue;
        dfs1(i);
    }

    fill(whole(vis), 0);

    ll num = 1;
    while(!stk.empty()) {
        ll ver = stk.top(); stk.pop();
        if(vis[ver]) continue;

        dfs2(ver, num);
        ++num;
    }

    cout << num-1 << "\n";
    for(ll i=1; i<=n; ++i) cout << kingdom[i] << " ";
    cout << "\n";
    return 0;
}