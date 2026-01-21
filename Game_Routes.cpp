/**
 *    author:  Meet
 *    created: 09.01.2026 16:03:17
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

vector<vector<ll>> adj;
vector<ll> dp, indeg, topo;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    adj.assign(n+1, {});
    dp.assign(n+1, 0);
    indeg.assign(n+1, 0);

    for(ll i=0; i<m; ++i) {
        ll u,v;
        cin >> u >> v;
        ++indeg[v];
        adj[u].push_back(v);
    }

    queue<ll> q;
    for(ll i=1; i<=n; ++i) {
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        ll ver = q.front(); q.pop();
        topo.push_back(ver);
        for(auto& child : adj[ver]) {
            if(--indeg[child] == 0) q.push(child);
        }
    }

    dp[1] = 1;

    for(auto& ver : topo) {
        if(dp[ver] == 0) continue;

        for(auto& child : adj[ver]) {
            dp[child] += dp[ver];
            dp[child] %= M;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}