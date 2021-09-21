//http://www.usaco.org/index.php?page=viewproblem2&cpid=809
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>

typedef long long ll;
#define FOR(i, x, y) for(ll i=x; i<y; i++)

using namespace std;

ll n, temp,ans=0,ans2=0;
vector<ll> logg;
bool imp = false;
bool realbreak = false;


ll solve(){
    FOR(i, 0, n){
        if (logg[i] > i){
            cout << -1;
            return 0;
        } 
    }
    FOR(i, 0, n){
        if (i==0){
            logg[i] =0;
            continue;
        }
        if (logg[i] != -1){
            temp = i;
            
            while(true){
                temp --;
                if (logg[temp+1] == 0) break;
                if (logg[temp] != -1 && logg[temp] != logg[temp+1]-1){
                    cout << -1;
                    return 0;
                }
                logg[temp] = logg[temp+1]-1;
            }
        }
    }
    FOR(i, 0, n){
        if(logg[i] == 0) ans += 1;
        if(logg[i] == -1) ans2 += 1;
    }
    cout << ans << " " << ans+ans2;
    return 0;
}

int main(){
    freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
    cin >> n;
    FOR(i, 0, n){
        cin >> temp;
        logg.push_back(temp);
    }
    solve();
}
