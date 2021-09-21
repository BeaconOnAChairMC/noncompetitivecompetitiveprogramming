#include <iostream>
#include <vector>

#define FOR(i, x, y) for(int i=x; i<y; i++)
typedef long long ll;

using namespace std;

int main(){
    ll n, q, a, b, temp;
    vector<ll> nums;
    vector<ll> answers;
    cin >> n >> q;
    FOR(i, 0, n){
        cin >> temp;
        if (i==0) nums.push_back(temp);
        else nums.push_back(temp + nums[i-1]);
    }
    FOR(i, 0, q){
        cin >> a >> b;
        if (a-1 == 0) answers.push_back(nums[b-1]);
        else answers.push_back(nums[b-1] - nums[a-2]);
    }
    FOR(i, 0, q){
        cout << answers[i] << "\n";
    }
}

