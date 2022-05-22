#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,x,y) for(ll i=x; i<y; i++)
#define FORNEG(i,x,y) for(ll i=x; i>y; i--)
using namespace std;
 
#define ll int
 
ll pos[10000000][2];
ll pref[3001][3001];
ll r, c, h, w;
 
bool check(ll x){
    FOR(i,0,3001){
        FOR(j,0,3001){
            pref[i][j] = 0;
        }
    }
    FOR(i,1,x+1){
        ll a = pos[i][0];
        ll b = pos[i][1];
        pref[a+1][b+1] += 1;
        pref[max(0, a+1-h)][b+1] -= 1;
        pref[a+1][max(0, b+1-w)] -= 1;
        pref[max(0, a+1-h)][max(0, b+1-w)] += 1;
    }
 
    FOR(i,0,c-w+1){
        FOR(j,1,r-h+1){
            pref[j][i] += pref[j-1][i];
        }
    }
    FOR(i,0,r-h+1){
        if (pref[i][0] > (h*w)/2){
            return true;
        }
        FOR(j,1,c-w+1){
            pref[i][j] += pref[i][j-1];
            if (pref[i][j] > (h*w)/2){
                return true;
            }
        }
    }
    return false;
}
 
int rectangle(int R, int C, int H, int W, int Q[3001][3001]) {
    r = R; c = C; h = H; w = W;
    FOR(i,0,R){
        FOR(j,0,C){
            pos[Q[i][j]][0] = i;
            pos[Q[i][j]][1] = j;
        }
    }
 
    int lo = 0;
    int hi = int(R*C/2)+1;
    while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}