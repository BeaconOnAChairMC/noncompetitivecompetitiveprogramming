#include <iostream>
#include <array>
#include <cmath>

#define FOR(i, x, y) for(ll i=x; i<y; i++)
#define FORNEG(i, x, y) for(ll i=x; i>y; i--)
typedef long long ll;

using namespace std;

int main(){
    ll n, q,a,b, temp;
    cin >> n >> q;
    ll powz = ll(pow(2, 21));
    ll powzz  = ll(pow(2, 22));
    ll ans[q];
    ll* tree = new ll[powzz];

    FOR(i,powz,powzz){
        if (i-powz < n){
            cin >> temp;
            tree[i] = temp;
        } else{
            tree[i] = 0;
        }
    }
    FORNEG(i, powz-1, 0){
        tree[i] = tree[i*2] ^ tree[i*2+1];
    }

    FOR(i, 0, q){
        ll anz = 0;
        cin >> a >> b;
        a += powz-1;
        b += powz-1;
        while (a<=b){
            if (a%2==1) anz = anz^tree[a++];
            if (b%2==0) anz = anz^tree[b--];
            a /= 2;
            b /= 2;
        }
        cout << anz<<endl;
    }
}