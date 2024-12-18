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

void solve()
{
    string x;
    vector<string>v;
    while(getline(cin,x))
    {
        v.ep(x);
    }
    int n = v.size();
    int m = v[0].size();
    vector<vector<bool>>dp(n,vector<bool>(m,0));
    array<int, 2> d;
    for (int i = 0 ; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (v[i][j] == '^')
            {
                d[0] = i;
                d[1] = j;
                break;
            }
        }
    }
    auto inbound = [&](const int &x, const int &y) -> bool
    {
        return 0 <= x && 0 <= y && x < n && y < m;
    };
    char c = v[d[0]][d[1]];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if ((i == d[0] && j == d[1]) || v[i][j] == '#')         continue;
            c = v[d[0]][d[1]];
            array<int, 2> dir;
            dir = d;
            char tmp = v[i][j];
            v[i][j] = '#';
            int res = 0, st = 0;
            for (int x = 0; x < n; ++x)
            {
                for (int y = 0; y < m; ++y)
                {
                    dp[x][y] = 0;
                }
            }
            while(inbound(dir[0],dir[1]) && st <= 100000)
            {
                //debug(d,res);
                ++st;
                if (!dp[dir[0]][dir[1]])
                {
                    ++res;
                    dp[dir[0]][dir[1]] = 1;
                }
                if (c == '^')
                {
                    if (inbound(dir[0]-1,dir[1]) && v[dir[0]-1][dir[1]] == '#')
                    {
                        c = '>';
                    }
                    else
                    {
                        dir[0]--;
                    }
                }
                if (c == '>')
                {
                    if (inbound(dir[0],dir[1]+1) && v[dir[0]][dir[1]+1] == '#')
                    {
                        c = 'v';
                    }
                    else
                    {
                        dir[1]++;
                    }
                }
                if (c == 'v')
                {
                    if (inbound(dir[0]+1,dir[1]) && v[dir[0]+1][dir[1]] == '#')
                    {
                        c = '<';
                    }
                    else
                    {
                        dir[0]++;
                    }
                }
                if (c == '<')
                {
                    if (inbound(dir[0],dir[1]-1) && v[dir[0]][dir[1]-1] == '#')
                    {
                        c = '^';
                    }
                    else
                    {
                        dir[1]--;
                    }
                }
            }
            if (st > 100000)
            {
                ++ans;
            }
            v[i][j] = tmp;
        }
    }
    cout<<ans<<'\n';
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
