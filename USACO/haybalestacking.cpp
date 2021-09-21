#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <array>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

typedef long long ll;
#define FOR(i, x, y) for(ll i=x; i<y; i++)

using namespace std;

ll n,k,a,b;

vector<ll> diff;
vector<ll> hay;
int main(){
    cin >> n >> k;
    FOR(i, 0, n){
        diff.push_back(0);
        hay.push_back(0);
    }
    FOR(i, 0,k){
        cin >> a >> b;
        diff[a-1] += 1;
        if (b<n) diff[b] -= 1;
        else diff[b-1] -= 1;
    }
    FOR(i, 0, n){
        if (i==0) hay[i] = diff[i];
        else hay[i] = diff[i]+hay[i-1];
    }
    sort(hay.begin(), hay.end());
    cout << hay[n/2];

}