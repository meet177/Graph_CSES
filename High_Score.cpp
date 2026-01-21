/**
 *    author:  Meet
 *    created: 06.01.2026 16:27:46
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
vector<array<ll,3>> edges;
vector<ll> dp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    edges.assign(m, {});
    adj.assign(n+1,{});
    dp.assign(n+1,MINF);
    dp[1] = 0;

    for(ll i=0; i<m; ++i) {
        ll u,v,c;
        cin >> u >> v >> c;

        edges[i] = {u,v,c};
        adj[u].push_back(v);
    }

    //BellMen Ford
    for(ll i=0; i<n-1; ++i) {
        for(auto& [u,v,c] : edges) {
            if(dp[u] != MINF) {
                dp[v] = max(dp[v], dp[u] + c);
            }
        }
    }

    vector<bool> affected(n+1,0);
    for(auto& [u,v,c] : edges) {
        if(dp[u] != MINF && dp[u] + c > dp[v]) {
            affected[v] = 1;
        }
    }

    bool poss = 1;
    for(ll i=1; i<=n; ++i) {
        if(!affected[i]) continue;
        vector<bool> vis(n+1,0);
        queue<ll> q;
        q.push(i);
        while(!q.empty()) {
            ll curr = q.front(); q.pop();
            if(curr == n) {
                poss = 0;
                break;
            }
            for(auto& child : adj[curr]) {
                if(vis[child]) continue;
                vis[child] = 1;
                q.push(child);
            }
        }
        if(!poss) break;
    }

    if(!poss) {
        minus;
        return 0;
    }
    cout << dp[n] << "\n";
    return 0;
}