#ifndef ONLINE_JUDGE
#include "AkbarKING.h"
#else
#define debug(...)
#define debugArr(...)
#define debugG(...)
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define int long long
#define $AzH_TxdmN$ ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")

#define ep emplace_back
#define pb push_back
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using __indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using __indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int sz = 3e5+9;
const int LOG = 63;
const int MOD = 1e9+7;
const int INF = 1e18;
const vector<pii> dirs = {{-1,-1},{-1,1},{1,1},{1,-1}};

int n,m;

void solve()
{
    string s;
    vector<string>v;
    while(getline(cin,s))
    {
        v.ep(s);
    }
    n = v.size();
    m = v[0].size();
    map<char, vector<pii>> mp;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (isalnum(v[i][j]))
            {
                mp[v[i][j]].ep(i,j);
            }
        }
    }
    auto inbound = [&](const int &x, const int &y) -> bool
    {
        return 0 <= x && 0 <= y && x < n && y < m;
    };
    set<pii>st;
    for (auto x : mp)
    {
        vector<pii>&vec = x.second;
        for (int i = 0; i < (int)vec.size(); ++i)
        {
            for (int j = 0; j < (int)vec.size(); ++j)
            {
                if (i != j)
                {
                    int dx = vec[i].first-vec[j].first;
                    int dy = vec[i].second-vec[j].second;
                    if (inbound(vec[i].first+dx,vec[i].second+dy))
                    {
                        st.insert({vec[i].first+dx,vec[i].second+dy});
                    }
                }
            }
        }
    }
    /*
    debug(st);
    for (const pii &vertices : st)
    {
        v[vertices.first][vertices.second] = '#';
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout<<v[i][j];
        }
        cout<<'\n';
    }
    */
    cout<<(int)st.size()<<'\n';
}

signed main()
{
    $AzH_TxdmN$
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }
}
