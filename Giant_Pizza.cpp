/**
 *    author:  Meet
 *    created: 13.01.2026 20:20:28
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
vector<ll> comp;
vector<bool> vis;

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

    comp[ver] = num;

    for(auto& child : rev_adj[ver]) {
        if(vis[child]) continue;
        dfs2(child, num);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll m,n;
    cin >> m >> n;

    //1 to n is positive and n+1 to 2n is negative wishes
    adj.assign(2*n, {});
    rev_adj.assign(2*n, {});
    comp.assign(2*n, 0);
    vis.assign(2*n, 0);

    for(ll i=0; i<m; ++i) {
        char sign1, sign2;
        ll a,b;
        cin >> sign1 >> a >> sign2 >> b;

        --a, --b;
        if(sign1 == '-') {
            a += n;
        }
        if(sign2 == '-') {
            b += n;
        }

        ll nega = (a+n)%(2*n), negb = (b+n)%(2*n);

        //~a -> b 
        adj[nega].push_back(b);
        //~b -> a
        adj[negb].push_back(a);

        rev_adj[b].push_back(nega);
        rev_adj[a].push_back(negb);
    }

    for(ll i=0; i<2*n; ++i) {
        if(vis[i]) continue;
        dfs1(i);
    }

    for(ll i=0; i<2*n; ++i) vis[i] = 0;

    ll comp_num = 0;
    while(!stk.empty()) {
        ll ver = stk.top(); stk.pop();
        if(vis[ver]) continue;
        ++comp_num;
        dfs2(ver, comp_num);
    }

    vector<char> ans(n, '0');

    for(ll i=0; i<n; ++i) {
        //both are in the same component we can not assign anything it is impossible
        if(comp[i] == comp[i+n]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        //comp[x] > comp[~x]
        //always assign false to smaller component 
        if(comp[i] > comp[i+n]) {
            ans[i] = '+';
        }else {
            ans[i] = '-';
        }
    }

    for(ll i=0; i<n; ++i) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}