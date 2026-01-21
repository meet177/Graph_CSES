/**
 *    author:  Meet
 *    created: 11.01.2026 22:39:19
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

void dfs1(ll ver) {
    vis[ver] = 1;

    for(auto& child : adj[ver]) {
        if(vis[child]) continue;
        dfs1(child);
    }
}

void dfs2(ll ver) {
    vis[ver] = 1;

    for(auto& child : rev_adj[ver]) {
        if(vis[child]) continue;
        dfs2(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    adj.assign(n+1, {});
    rev_adj.assign(n+1, {});
    vis.assign(n+1, 0);

    for(ll i=0; i<m; ++i) {
        ll u,v;
        cin >> u >> v;

        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    //to check if all others are reachable from 1
    dfs1(1);

    ll not_reachable = -1;
    for(ll i=1; i<=n; ++i) {
        if(!vis[i]) {
            not_reachable = i;
            break;
        }
        vis[i] = 0;
    }

    if(not_reachable != -1) {
        no;
        cout << 1 << " " << not_reachable << "\n";
        return 0;
    }

    //to check if every other vertex can reach 1 or not by reversed graph
    dfs2(1);

    for(ll i=1; i<=n; ++i) {
        if(!vis[i]) {
            not_reachable = i;
            break;
        }
    }

    if(not_reachable != -1) {
        no;
        cout << not_reachable << " " << 1 << "\n";
        return 0;
    }

    yes;
    return 0;
}