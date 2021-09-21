//http://www.usaco.org/index.php?page=viewproblem2&cpid=915
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdio>
#include <algorithm>

typedef long long ll;
#define FOR(i, x, y) for(ll i=x; i<y; i++)

using namespace std;

int main(){
    freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    if (b > c)
        swap(b, c);

    if (c-a==2) cout << 0 << "\n"; 
    else if (b-a == 2 || c-b == 2) cout << 1 << "\n";
    else cout << 2 << "\n";

    cout << max(b-a-1, c-b-1);
}