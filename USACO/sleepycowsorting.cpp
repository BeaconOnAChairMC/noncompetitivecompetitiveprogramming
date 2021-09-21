//http://www.usaco.org/index.php?page=viewproblem2&cpid=892
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>

typedef long long ll;
#define FOR(i, x, y) for(ll i=x; i<y; i++)

using namespace std;

ll largest(vector<ll> v){
    ll maxi = 0;
    ll ans = 0;
    ll len = 0;
    bool firstsort = false;
    FOR(i, 0, v.size()){
        maxi = max(maxi, v[i]);
    }
    FOR(i, 0, v.size()){
        if (i==v.size()-1){
            ans += 0;
            len = v.size();
            if (!(is_sorted(v.begin(), v.end()-1))) firstsort = true;
        } else{
            if (v[i] == maxi){
                ans += i+1;
                len = i+1;
                break;
            } 
        }
    }
    if (len == v.size() && !firstsort){
        return 0;
    }
    if (firstsort){
        return ans + largest(vector<ll>(v.begin(), v.end()-1));
    }
    return ans + largest(vector<ll>(v.begin()+len, v.end()));
}

int main(){
    freopen("sleepy.in", "r", stdin);

	freopen("sleepy.out", "w", stdout);
    vector<ll> order;
    ll n,len,lg,ans, temp;
    cin >> n;
    FOR(i, 0, n){
        cin >> temp;
        order.push_back(temp);
    }
    cout << largest(order);
}