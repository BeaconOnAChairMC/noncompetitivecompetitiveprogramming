//http://www.usaco.org/index.php?page=viewproblem2&cpid=832
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

int main(){
    freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
    ll n, m, k,temp1, temp2;
    ll next = 0, pos1=-1;
    ll nextpos=0;
    bool nextposneed = true;
    vector<ll> hier;
    unordered_map<ll, ll> pos;
    unordered_map<ll, ll> posz;
    cin >> n >> m >> k;
    FOR(i, 0, m){
        cin >> temp1;
        if (temp1 == 1) pos1 = i;
        hier.push_back(temp1);
    }
    FOR(i, 0, k){
        cin >> temp1 >> temp2;
        pos[temp1] = temp2-1;
        posz[temp2-1] = temp1;
    }
    if (pos.find(1) != pos.end()){
        cout << pos[1];
    }
    else if (pos1>=0){
        ll i = 0;
        while (i<n){
            if (hier[next] == 1 && posz.find(i) == posz.end()){
                cout << i+1;
                break;
            }
            if (pos.find(hier[next]) != pos.end()){
                i = pos[hier[next]]+1;
                next ++;
                continue;
            }
            if (posz.find(i) == posz.end()){
                next++;
            }
            i++;
        }
    }
    else{
        ll i = 0;
        while (i<n){
            if (next == m){
                cout << nextpos+1;
                break;
            }
            if (pos.find(hier[next]) != pos.end()){
                if (abs(i-(pos[hier[next]]+1))>1){
                    ll count=0;
                    FOR(j, i, pos[hier[next]]+1){
                        if (posz.find(j) == posz.end()){
                            count++;
                        }
                    }
                    if (count>0){
                        cout << nextpos+1;
                        break;
                    }
                    
                }
                i = pos[hier[next]]+1;
                next ++;
                nextposneed = true;
                continue;
            }
            
            if (posz.find(i) == posz.end()){
                if (nextposneed){
                    nextpos = i;
                    nextposneed = false;
                }
                next++;
            }
            i++;
        }

    }

}