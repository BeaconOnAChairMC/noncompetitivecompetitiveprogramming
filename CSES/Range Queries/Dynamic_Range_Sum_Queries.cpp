#include <iostream>
#include <array>
#include <cmath>


#define FOR(i, x, y) for(ll i=x; i<y; i++)
#define FORNEG(i, x, y) for(ll i=x; i>y; i--)
typedef long long ll;

using namespace std;

int main(){
    ll n, q, a, b,w, temp;
    ll powz = ll(pow(2, 21));
    ll powzz = ll(pow(2, 22));
    ll* tree = new ll[powzz];
    cin >> n >> q;

    FOR(i, powz, powzz){
        if ((i-powz) < n){
            cin >> temp;
            tree[i] = temp;
        }
        else{
            tree[i] = 0;
        }
    }
    FORNEG(i, powz-1, 0){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    FOR(i, 0, q){
        cin >> w;
        if (w == 2){
            ll summ = 0;
            cin >> a >> b;
            a += powz-1;
            b += powz-1;
            while (a<=b){
                if (a%2 == 1) summ += tree[a++];
                if (b%2 == 0) summ += tree[b--];
                a/=2;
                b/=2;
            }
            cout << summ << "\n";
        } else{
            cin >> a >> b;
            ll j = a+powz-1;
            tree[j] = b;
            j/=2;
            while (j!=0){
                tree[j] += tree[j*2] + tree[j*2+1];
                j /= 2;
            }
        }
    }
}
