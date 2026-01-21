/**
 *    author:  Meet
 *    created: 07.01.2026 14:23:58
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

vector<array<ll,3>> edges;
vector<ll> dp, par;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    dp.assign(n+1,0);
    par.assign(n+1,-1);
    // dp[1] = 0; //this can be used for finding cycle path reachable from 1 but here we can start from any node so we have made all dp as 0

    for(ll i=0; i<m; ++i) {
        ll u,v,c;
        cin >> u >> v >> c;
        edges.push_back({u,v,c});
    }

    for(ll i=0; i<n-1; ++i) {
        for(auto& [u,v,c] : edges) {
            if(dp[u] + c < dp[v]) {
                dp[v] = dp[u] + c;
                par[v] = u;
            }
        }
    }

    ll pnt = -1;
    bool have = 0;
    for(auto& [u,v,c] : edges) {
        if(dp[u] + c < dp[v]) {
            par[v] = u;
            pnt = v;
            have = 1;
            break;
        }
    }

    if(!have) {
        no;
        return 0;
    }

    //the node which currently is pnt may not be a part of cycle but it can be reachable from cycle, so we are doing n times parent it gurantees to be inside cycle, it will rotate around cycle only, why n because any simple path can be of length n-1 max, so doing n means we are able to find a cycle always
    for(ll i=0; i<n; ++i) pnt = par[pnt];

    vector<ll> cycle;
    ll curr = pnt;

    do {
        cycle.push_back(curr);
        curr = par[curr];
    }while(curr != pnt);
    cycle.push_back(pnt);

    reverse(whole(cycle));
    yes;
    for(auto& c : cycle) cout << c << " ";
    cout << "\n";
    return 0;
}