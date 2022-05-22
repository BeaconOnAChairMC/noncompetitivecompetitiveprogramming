#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "grader.h"
#include "memory.h"
    
    
    
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
    
#define FOR(i, x, y) for(ll i=x; i<y; i++)
#define FORNEG(i, x, y) for(ll i=x; i>y; i--)
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
    
    
ll sussies[50] = {0};
bool visited[50];
    
void play(){
    FOR(i,0,50){
        sussies[i] = 0;
        visited[i] = 0;
    }
    fast();
    FOR(i,1,51){
        sussies[i-1] = faceup(i);
    }
    FOR(i,1,51){
        if (visited[i-1]){
            continue;
        }
        faceup(i);
        FOR(j,1,51){
            if (sussies[i-1] == sussies[j-1] && (i-1) != (j-1)){
                faceup(j);
                visited[i-1] = true;
                visited[j-1] = true;
            } 
        }
    }
    
}