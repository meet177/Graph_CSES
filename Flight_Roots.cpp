/**
 *    author:  Meet
 *    created: 08.01.2026 13:57:34
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

vector<ll> cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m,k;
    cin >> n >> m >> k;

    adj.assign(n+1, {});
    cnt.assign(n+1,0);

    for(ll i=0; i<m; ++i) {
        ll u,v,c;
        cin >> u >> v >> c;

        adj[u].push_back({v,c});
    }

    //it is just dijkstra with visiting every node at most k times as we need k shortest distances
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});

    vector<ll> ans;

    while(!pq.empty()) {
        auto [d, ver] = pq.top(); pq.pop();
        if(cnt[ver] == k) continue;

        if(ver == n) ans.push_back(d);
        ++cnt[ver];

        for(auto& [child, dis] : adj[ver]) {
            if(cnt[child] < k) {
                pq.push({d+dis, child});
            }
        }
    }

    for(auto& a : ans) cout << a << " ";
    cout << "\n";
    
    return 0;
}