//http://www.usaco.org/index.php?page=viewproblem2&cpid=1088
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

typedef long long ll;
#define FOR(i, x, y) for(ll i=x; i<y; i++)

using namespace std;

ll n, temp, sum=0, ans=0;
vector<vector<ll> > grid;
vector<ll> temps;
vector<ll> ansz;
unordered_map<ll, bool> used;

ll colsum(ll a, ll b){
    ll sumz = 0;
    FOR(i, 0, n){
        if ((i%2)==b){
            sumz += grid[i][a];
        }
    }
    return sumz;
}

ll rowsum(ll a, ll b){
    ll sumz = 0;
    FOR(i, 0, n){
        if ((i%2) == b){
            sumz += grid[a][i];
        }
    }
    return sumz;
}

int main(){
    cin >> n;
    FOR(i, 0, n){
        temps.clear();
        FOR(j, 0, n){
            cin >> temp;
            sum += temp;
            temps.push_back(temp);
        }
        grid.push_back(temps);
    }

    FOR(i, 0, n){
        if (colsum(i, 1) > colsum(i, 0)) ans += colsum(i, 1);
        else ans+= colsum(i, 0);
    }
    ansz.push_back(ans);
    ans = 0;
    FOR(i, 0, n){
        if (rowsum(i, 1) > rowsum(i, 0)) ans += rowsum(i, 1);
        else ans+= rowsum(i, 0);
    }
    ansz.push_back(ans);
    sort(ansz.rbegin(), ansz.rend());

    cout << ansz[0];
}