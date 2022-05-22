#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "combo.h"
 
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
 
#define FOR(i, x, y) for(ll i=x; i<y; i++)
#define FORNEG(i, x, y) for(ll i=x; i>y; i--)
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
 
string guess_sequence(int N){
    int n = N;
    vector<char> possible = {'A','B','X','Y'};
    string prev = "";
    if (press("AB")){
        if(press("A")){
            possible.erase(possible.begin()+0);
            prev += "A";
        }else{
            possible.erase(possible.begin()+1);
            prev += "B";
        }
    }else{
        if(press("X")){
            possible.erase(possible.begin()+2);
            prev += "X";
        }else{
            possible.erase(possible.begin()+3);
            prev += "Y";
        }
    }
    
 
    FOR(i,0,n-2){
        string query = "";
        query += prev + possible[0];
        query += prev + possible[1] + possible[0];
        query += prev + possible[1] + possible[1];
        query += prev + possible[1] + possible[2];
 
        int sus = press(query);
 
        if (sus == i+2){
            prev += possible[0];
        }else if (sus==i+3){
            prev += possible[1];
        }else{
            prev += possible[2];
        }
    }
    if (n>1){
        if (press(prev + "A" + prev + "B")==n){
            if(press(prev + "A")==n){
                prev += "A";
            }else{
                prev += "B";
            }
        }else{
            if(press(prev + "X")==n){
                prev += "X";
            }else{
                prev += "Y";
            }
        }
    }
    return prev;
    
}