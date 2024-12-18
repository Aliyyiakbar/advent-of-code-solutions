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

int n,m;

void solve()
{
    string s;
    getline(cin, s);
    vector<int> v;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (i & 1)
        {
            for (int j = 1; j <= (s[i] - '0'); ++j)
            {
                v.ep(-1);
            }
        }
        else
        {
            for (int j = 1; j <= (s[i] - '0'); ++j)
            {
                v.ep((i>>1));
            }
        }
    }
    int e = v.size() - 1;
    while (e >= 0)
    {
        int st = 0;
        while (e >= 0 && v[e] == -1)
        {
            e--;
        }
        if (e < 0)
        {
            break;
        }
        int id = v[e], sz = 0, p = e;
        while (p >= 0 && v[p] == id)
        {
            p--;
            sz++;
        }
        int cur = 0, found = 0;
        while (cur < e)
        {
            int i = 0, ok = 1;
            while (i < sz)
            {
                if (v[cur + i] != -1)
                {
                    ok = 0;
                    break;
                }
                i++;
            }
            if (ok)
            {
                found = 1;
                break;
            }
            cur += i;
            while (cur < v.size() && v[cur] != -1)
            {
                cur++;
            }
        }
        if (found)
        {
            for (int i = 0; i < sz; ++i)
            {
                v[cur + i] = id;
                v[e--] = -1;
            }
        }
        else
        {
            e -= sz;
        }
    }
    int ans = 0;
    for (int i = 0; i < (int)v.size(); ++i)
    {
        if (v[i] != -1)
        {
            ans += i * v[i];
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
    $AzH_TxdmN$
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}
