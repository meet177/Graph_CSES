/**
 *    author:  Meet
 *    created: 06.01.2026 12:09:22
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

vector<pair<ll,ll>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<char> dir = {'U', 'D', 'L', 'R'};

vector<string> grid;
vector<vector<pair<ll,ll>>> par;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    ll n,m;
    cin >> n >> m;

    grid.assign(n, "");
    par.assign(n, vector<pair<ll,ll>>(m,{-1,-1}));

    for(ll i=0; i<n; ++i) cin >> grid[i];

    vector<vector<ll>> dp1(n, vector<ll>(m, INF)), dp2(n, vector<ll>(m, INF));    

    auto isValid = [&] (ll i, ll j) -> bool {
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#');
    };

    pair<ll,ll> pos;
    //bfs on man
    queue<pair<ll,ll>> q;
    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<m; ++j) {
            if(grid[i][j] == 'A') {
                pos = {i,j};
                q.push({i,j});
                dp1[i][j] = 0;
                break;
            }
        }
    }

    while(!q.empty()) {
        auto [i,j] = q.front(); q.pop();
        for(auto& [di,dj] : dirs) {
            ll ni = i+di, nj = j+dj;
            if(isValid(ni,nj) && dp1[ni][nj] == INF) {
                par[ni][nj] = {i,j};
                dp1[ni][nj] = dp1[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }

    //bfs on monsters
    for(ll i=0; i<n; ++i) {
        for(ll j=0; j<m; ++j) {
            if(grid[i][j] == 'M') {
                q.push({i,j});
                dp2[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        auto [i,j] = q.front(); q.pop();
        for(auto& [di,dj] : dirs) {
            ll ni = i+di, nj = j+dj;
            if(isValid(ni,nj) && dp2[ni][nj] == INF) {
                dp2[ni][nj] = dp2[i][j] + 1;
                q.push({ni,nj});
            }
        }
    }

    string path;

    bool found = 0;

    for(ll i=0; i<n; ++i) {
        if(dp1[i][0] < dp2[i][0] || dp1[i][m-1] < dp2[i][m-1]) {
            pair<ll,ll> st;
            if(dp1[i][0] < dp2[i][0]) st = {i,0};
            else st = {i,m-1};

            while(st != pos) {
                pair<ll,ll> p = par[st.first][st.second];
                pair<ll,ll> diff = {st.first-p.first, st.second-p.second};
                for(ll i=0; i<4; ++i) {
                    if(dirs[i] == diff) {
                        char ch = dir[i];
                        path.push_back(ch);
                        break;
                    }
                }
                st = p;
            }
            found = 1;
            break;
        }
    }

    if(!found) {
        for(ll j=0; j<m; ++j) {
            if(dp1[0][j] < dp2[0][j] || dp1[n-1][j] < dp2[n-1][j]) {
                pair<ll,ll> st;
                if(dp1[0][j] < dp2[0][j]) st = {0,j};
                else st = {n-1,j};

                while(st != pos) {
                    pair<ll,ll> p = par[st.first][st.second];
                    pair<ll,ll> diff = {st.first-p.first, st.second-p.second};
                    for(ll i=0; i<4; ++i) {
                        if(dirs[i] == diff) {
                            char ch = dir[i];
                            path.push_back(ch);
                            break;
                        }
                    }
                    st = p;
                }
                found = 1;
                break;
            }
        }
    }

    if(!found) {
        no;
        return 0;
    }

    yes;
    reverse(whole(path));
    cout << path.size() << "\n";
    cout << path << "\n";
    return 0;
}