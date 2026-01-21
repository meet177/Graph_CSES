/**
 *    author:  Meet
 *    created: 08.01.2026 21:34:19
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
vector<ll> par, color;

ll st = -1;

bool dfs(ll ver) {
    color[ver] = 1;

    for(auto& child : adj[ver]) {
        if(color[child] == 2) continue;
        
        par[child] = ver;
        if(color[child] == 1) {
            st = child;
            return true;
        }

        if(dfs(child)) return true;
    }

    color[ver] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    adj.assign(n+1,{});
    par.assign(n+1,-1);
    color.assign(n+1, 0);

    for(ll i=0; i<m; ++i) {
        ll u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(ll i=1; i<=n; ++i) {
        if(color[i] == 2) continue;
        
        if(dfs(i)) {
            vector<ll> cycle;
            ll curr = st;
            do {
                cycle.push_back(curr);
                curr = par[curr];
            }while(curr != st);
            cycle.push_back(curr);

            reverse(whole(cycle));
            cout << cycle.size() << "\n";
            for(auto& c : cycle) cout << c << " ";
            cout << "\n";
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}