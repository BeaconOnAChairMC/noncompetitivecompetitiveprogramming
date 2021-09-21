//http://www.usaco.org/index.php?page=viewproblem2&cpid=737
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

ll temp, n, maxx=0, maxy=0, minx, miny;
vector<ll> temps;
vector<vector<ll> > grid;
unordered_map<ll, vector<ll> > pos;
vector<ll> unable;

int main(){
    freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
    cin >> n;
    FOR(i, 0, n){
        cin >> temp;

        FOR(j, 0, n){
            temps.push_back((temp/ll(pow(10, j)))%10);
        }
        reverse(temps.begin(), temps.end());
        grid.push_back(temps);
    }
    FOR(x, 1, 10){
        maxx = -1;
        maxy = -1;
        minx = 100000000000;
        miny = 100000000000;

        FOR(i, 0, n){
            FOR(j, 0, n){
                if (grid[i][j] == x){
                    maxx = max(maxx, j);
                    maxy = max(maxy, i);
                    minx = min(minx, j);
                    miny = min(miny, i);
                }
            }
        }
        pos[x] = {minx, miny, maxx, maxy};
    }
    FOR(i, 1, 10){
        FOR(y, pos[i][1], pos[i][3]+1){
            FOR(x, pos[i][0], pos[i][2] + 1){
                if (grid[y][x] != i){
                    unable.push_back(grid[y][x]);
                }
            }
        }
    }
    ll ans = 0;
    FOR(i, 1, 10){
        if (find(unable.begin(), unable.end(), i) == unable.end() && pos[i][2] != -1){
            ans ++;
        }
    }
    cout << ans;
}