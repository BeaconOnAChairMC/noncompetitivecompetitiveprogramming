//http://www.usaco.org/index.php?page=viewproblem2&cpid=808
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

ll n, temp, ans = 0;
bool rgt = true;
bool firstright = false;
bool lft = false;
vector<ll> pos;

ll passright(ll k){
    if (k==0) return true;
    if (k==n-1) return false;
    if (abs(pos[k-1]-pos[k]) > abs(pos[k+1]-pos[k])){
        return true;
    }
    return false;
}

int main(){
    freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
    cin >> n;
    FOR(i, 0, n){
        cin >> temp;
        pos.push_back(temp);
    }
    sort(pos.begin(), pos.end());
    FOR(i, 0, n){
        if (!passright(i) && firstright==true){
            if(lft){
                ans ++;
            }
            
            firstright = false;
            continue;
        }
        if (firstright == true){
            firstright = false;
        }
        if (rgt){
        if (passright(i) != rgt){
            if (!passright(i)){
                firstright = true;
                if (i>=2 && passright(i-2)){
                    lft = true;
                }else{
                    lft = false;
                }
            }
            ans ++;
            rgt = passright(i);
        }
        }else{
            rgt = passright(i);
        }
    }
    cout << ans;
}