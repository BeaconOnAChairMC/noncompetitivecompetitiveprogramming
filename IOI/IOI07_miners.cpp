#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define FOR(i,x,y) for(ll i = x; i<y; i++)
 
ll dp[100001][4][4][4][4];
 
int main(){
	ll n;
	cin >> n;
	string sussy;
 
	cin >> sussy;
 
	vector<ll> food(n+1);
 
	FOR(i,1,n+1){
		if (sussy[i-1] == 'M') food[i] = 1;
		if (sussy[i-1] == 'F') food[i] = 2;
		if (sussy[i-1] == 'B') food[i] = 3;
	}
 
	FOR(i,0,n+1){
		FOR(j,0,4){
			FOR(k,0,4){
				FOR(l,0,4){
					FOR(m,0,4){
						dp[i][j][k][l][m] = -1;
					}
				}
			}
		}
	}
	dp[0][0][0][0][0] = 0;
 
	FOR(i,1,n+1){
		FOR(j,0,4){
			FOR(k,0,4){
				FOR(l,0,4){
					FOR(m,0,4){
						if (dp[i-1][j][k][l][m] == -1) continue;
						ll sus = 1;
 
						if (food[i] != j && j!=0) sus += 1;
						if (food[i] != k && k!=0) sus += 1;
						if (j == k && j!=0 && k!=0 && (food[i] != j || food[i] != k )) sus -= 1;
 
						dp[i][k][food[i]][l][m] = max(dp[i][k][food[i]][l][m], dp[i-1][j][k][l][m] + sus);
 
						sus = 1;
 
						if (food[i] != l && l!=0) sus += 1;
						if (food[i] != m && m!=0) sus += 1;
						if (l==m && l!=0 && m!=0 && (food[i] != l || food[i] != m )) sus -= 1;
 
						dp[i][j][k][m][food[i]] = max(dp[i][j][k][m][food[i]], dp[i-1][j][k][l][m] + sus);
					}
				}
			}
		}
	}
	ll ans = 0;
 
 
	FOR(j,0,4){
		FOR(k,0,4){
			FOR(l,0,4){
				FOR(m,0,4){
					ans = max(ans,dp[n][j][k][l][m]);
				}
			}
		}
	}
	cout << ans;
 
 
}