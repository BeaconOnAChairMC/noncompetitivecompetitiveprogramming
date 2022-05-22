#include <bits/stdc++.h>
    
typedef long long ll;
#define FOR(i,x,y) for(ll i=x; i<y; i++)
using namespace std;
 
#define TREESIZE 1048576
#define HSIZE 524288
 
ll tree[TREESIZE];
void update(ll a, ll b){
    a += HSIZE;
    tree[a] = b;
    while (a>1){
        a/=2;
        tree[a] = tree[a*2] + tree[a*2+1];
    }
}
 
ll query(ll a, ll b){
    a += HSIZE;
    b += HSIZE;
    if (a>b) swap(a,b);
    ll sum = 0;
    while (a<=b){
        if (a%2==1){
            sum += tree[a++];
        }
        if (b%2==0){
            sum += tree[b--];
        }
        a/=2;
        b/=2;
    }
    return sum;
}
 
long long count_swaps(vector<int> s) {
    ll n = s.size();
    unordered_map<ll, queue<ll>> susmap;
 
    FOR(i,0,n){
        susmap[s[i]].push(i);
    }
    ll cur = 0;
    ll ans = 0;
    FOR(i,0,n){
        if (susmap[s[i]].size() == 0 || susmap[s[i]].front() != i){
            continue;
        }
        if (s[i] > 0){
            ans += abs(i - susmap[-1*s[i]].front());
            ans -= query(i, susmap[-1*s[i]].front());
        }else{
            ans += abs(i+1 - susmap[-1*s[i]].front());
            ans -= query(i+1, susmap[-1*s[i]].front());
        }
        update(susmap[s[i]].front(), 1);
        update(susmap[-1*s[i]].front(), 1);
        susmap[-1*s[i]].pop();
        susmap[s[i]].pop();
    }
 
 
    return ans;
}