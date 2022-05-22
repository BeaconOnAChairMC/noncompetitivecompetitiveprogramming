#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#include "cave.h"
 
 
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
 
#define FOR(i, x, y) for(int i=x; i<y; i++)
#define FORNEG(i, x, y) for(ll i=x; i>y; i--)
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll int
 
 
 
vector<vector<ll> > found;
 
ll test(int N, int n){
    ll ans[N];
    FOR(i,0,N){
        ans[i] = 0;
    }
    for (auto&i : found){
        ans[i[1]] = i[2];
    }
    ll result = tryCombination(ans);
    if (result>n || result==-1){
        return 0;
    }else{
        return 1;
    }
 
}
 
ll test2(int n, int k, int s, int l){
    k++;
    ll ans[n];
    FOR(i,0,n){
        ans[i] = 0;
    }
    FOR(i,0,k) ans[i] = s;
    FOR(i,k,n){
        if (s==0) ans[i] = 1;
        else ans[i] = 0;
    } 
    for (auto&i : found){
        ans[i[1]] = i[2];
    }
    ll result = tryCombination(ans);
    if (result>l || result==-1){
        return 1;
    }else{
        return 0;
    }
 
}
 
void exploreCave(int N){
    FOR(i,0,N){
        ll switchd = test(N,i);
        ll lo = 0;
        ll hi = N;
        ll mid = 0;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (test2(N, mid, switchd, i)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        };
        found.push_back({i, lo, switchd});
    }
    ll S[N];
    ll D[N];
 
    for (auto&i : found){
        S[i[1]] = i[2];
        D[i[1]] = i[0];
    }
    answer(S,D);
}