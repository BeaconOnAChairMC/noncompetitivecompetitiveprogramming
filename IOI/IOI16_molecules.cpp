#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "molecules.h"
 
 
typedef long long lll;
using namespace std;
using namespace __gnu_pbds;
 
#define FOR(i, x, y) for(int i=x; i<y; i++)
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
 
 
vector<int> find_subset(int l, int u, vector<int> k){
    vector<int> w;
    w = k;
    sort(w.begin(), w.end());
 
    lll n = k.size();
    lll ll = 0; lll rr = 0;
    lll cur = 0;
    while (ll<=rr){
        if (cur<l){
            if (rr>n) break;
            cur += w[rr];
            rr++;
        }else if (cur>u){
            cur -= w[ll];
            ll ++; 
        }else{
            break;
        }
    }
    vector<int> ans;
    unordered_multiset<int> realsus;
    if (l<=cur && cur<=u){
        FOR(i,ll,rr){
            realsus.insert(w[i]);
        }
    }
    FOR(i,0,n){
        if (realsus.count(k[i])){
            ans.push_back(i);
            realsus.erase(realsus.find(k[i]));
        }
    }
 
    return ans;
}