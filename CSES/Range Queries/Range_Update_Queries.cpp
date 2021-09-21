#include <iostream>
#include <array>
#include <cmath>

#define FOR(i, x, y) for(int i=x; i<y; i++)
#define FORNEG(i, x, y) for(int i=x; i>y; i--)
typedef long long ll;

using namespace std;

int main(){
    ll n, q, a, b,c,w,s, temp;
    ll powz = ll(pow(2, 21));
    ll powzz = ll(pow(2, 22));
    ll* tree = new ll[powzz];
    cin >> n >> q;
    s = 0;
    FOR(i, powz, powzz){
        if (i-powz < n){
            cin >> temp;
            tree[i] = temp-s;
            s = temp;
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
        if (w==1){
            cin >> a >> b >> c;
            a += powz-1;
            b += powz;
            tree[a] += c;
            tree[b] -= c;
            a/=2;
            b/=2;
            while (a!=0){
                tree[a] = tree[a*2]+ tree[a*2+1];
                a /= 2;
            }
            while (b!=0){
                tree[b] = tree[b*2]+ tree[b*2+1];
                b /= 2;
            }
        } else{
            ll sumz = 0;
            cin >> b;
            a = 0;
            a += powz-1;
            b += powz-1;
            
            while (a<=b){
                if (a%2==1) sumz += tree[a++];
                if (b%2==0) sumz += tree[b--];
                a/=2;
                b/=2;
            }
            cout << sumz << endl;
        }
    }
}



