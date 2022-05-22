#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
    
#define FOR(i, x, y) for(ll i=x; i<y; i++)
#define FORNEG(i, x, y) for(ll i=x; i>y; i--)
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define INF 2300000000
    
vector<ll> dist[100001];
vector<vector<ll>> edges[100001];
    
int travel_plan(int N, int M, int R[][2], int L[], int K, int P[]){
    
    FOR(i,0,M){
        edges[R[i][0]].push_back({R[i][1], L[i]});
        edges[R[i][1]].push_back({R[i][0], L[i]});
    }
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    FOR(i,0,N){
        dist[i] = {INF, INF};
    }
    FOR(i,0,K){
        dist[P[i]] = {0,0};
        pq.push({0,P[i]});
    }
    
    
    while (pq.size()){
        vector<ll> node = pq.top();
        pq.pop();
    
        if (node[0] != dist[node[1]][1]) continue;
        for (auto&i : edges[node[1]]){
            if (node[0]+i[1] <= dist[i[0]][0]){
                if (dist[i[0]][0] != dist[i[0]][1]) pq.push({dist[i[0]][0], i[0]});
                dist[i[0]][1] = dist[i[0]][0];
                dist[i[0]][0] = node[0]+i[1];
            } else if (node[0]+i[1] < dist[i[0]][1]){
                dist[i[0]][1] = node[0]+i[1];
                pq.push({dist[i[0]][1], i[0]});
            }else{
                continue;
            }
        }
    }
    
    return dist[0][1];
    
}