#include <bits/stdc++.h>
 
 
typedef long long ll;
using namespace std;
 
#define FOR(i, x, y) for(ll i=x; i<y; i++)
#define FORNEG(i, x, y) for(ll i=x; i>y; i--)
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
 
 
ll grid[801][801];
ll visited[801][801];
ll n,s;
vector<vector<ll>> hives;
vector<ll> start;
vector<ll> endd;
vector<vector<ll>> ops = {{0,1}, {0,-1}, {1,0}, {-1,0}};
 
void bfsinit(){
    queue<vector<ll>> d;
    for (auto&i : hives){
        d.push({i[0], i[1], 0});
    }
    while (d.size()){
        vector<ll> node = d.front();;
        d.pop();
        for (auto&i : ops){
            ll a = node[0] + i[0];
            ll b = node[1] + i[1];
            if (0<=a && a<n && 0<=b && b<n){
                if (grid[a][b] == -3){
                    d.push({a,b,node[2]+1});
                    grid[a][b] = node[2]+1;
                }
 
            }
        }
 
    }
 
}
 
bool test(ll time){
    queue<vector<ll>> d;
    if (grid[start[0]][start[1]] <= time){
        return false;
    }
    FOR(i,0,n){
        FOR(j,0,n){
            visited[i][j] = false;
        }
    }
    d.push({start[0], start[1], 0});
    while (d.size()){
        vector<ll> node = d.front();
        d.pop();
        if (node[0]==endd[0] && node[1] == endd[1]){
            return true;
        }
        for (auto&i : ops){
            ll a = node[0]+i[0];
            ll b = node[1] + i[1];
            if (0<=a && a<n && 0<=b && b<n && !(visited[a][b])){
                if (grid[a][b] == -2) continue;
                if (grid[a][b] == -1 || grid[a][b] > time+(node[2]+1)/s){
                    d.push({a,b,node[2]+1});
                    visited[a][b] = true;
                }
            }
 
        }
    }
    return false;
}
 
 
int main(){
    fast();
    cin >> n >> s;
    FOR(i,0,n){
        string sus;
        cin >> sus;
        FOR(j,0,n){
            grid[i][j] = sus[j];
        }
    }
    FOR(i,0,n){
        FOR(j,0,n){
            if (grid[i][j] == 'T') grid[i][j] = -2;
            else if (grid[i][j] == 'D'){
                grid[i][j] = -1;
                endd = {i,j};
            } 
            else if (grid[i][j] == 'H'){
                grid[i][j] = 0;
                hives.push_back({i,j});
            } 
            else if (grid[i][j] == 'M'){
                start = {i,j};
                grid[i][j] = -3;
            }
            else{
                grid[i][j] = -3;
            }
        }
    }
    bfsinit();
    ll lo = -1;
    ll hi = n*n;
    while (lo<hi){
        ll mid = lo+(hi-lo+1)/2;
        if (test(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo;
 
}