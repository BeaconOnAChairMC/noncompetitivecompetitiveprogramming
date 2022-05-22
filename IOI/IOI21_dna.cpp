#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#pragma GCC optimize ("Ofast")

#define FOR(i,x,y) for(ll i = x; i<y; i++)

string a, b;
ll prefab[100001], prefac[100001], prefba[100001], prefbc[100001],prefca[100001],prefcb[100001], prefsame[100001], pref1a[100001], pref1b[100001], pref1c[100001],pref2a[100001], pref2b[100001], pref2c[100001];

void init(string A, string B){
	for (auto&i : A){
		if (i=='A') a += 'a';
		if (i=='T') a += 'b';
		if (i=='C') a += 'c';
	}

	for (auto&i : B){
		if (i=='A') b += 'a';
		if (i=='T') b += 'b';
		if (i=='C') b += 'c';
	}

	ll n = a.size();

	pref1a[0] = 0;
	pref1b[0] = 0;
	pref1c[0] = 0;
	pref2a[0] = 0;
	pref2b[0] = 0;
	pref2c[0] = 0;

	prefab[0] = 0;
	prefac[0] = 0;
	prefba[0] = 0;
	prefbc[0] = 0;
	prefca[0] = 0;
	prefcb[0] = 0;
	prefsame[0] = 0;

	if (a[0] == 'a') pref1a[0] = 1;
	else if (a[0] == 'b') pref1b[0] = 1;
	else pref1c[0] = 1;

	if (b[0] == 'a') pref2a[0] = 1;
	else if (b[0] == 'b') pref2b[0] = 1;
	else pref2c[0] = 1;


	if (a[0] == b[0]) prefsame[0] = 1;

	if (a[0] == 'a' && b[0] == 'b') prefab[0] = 1;
	if (a[0] == 'a' && b[0] == 'c') prefac[0] = 1;
	if (a[0] == 'b' && b[0] == 'a') prefba[0] = 1;
	if (a[0] == 'b' && b[0] == 'c') prefbc[0] = 1;
	if (a[0] == 'c' && b[0] == 'a') prefca[0] = 1;
	if (a[0] == 'c' && b[0] == 'b') prefcb[0] = 1;



	FOR(i,1,n){
		pref1a[i] = 0;
		pref1b[i] = 0;
		pref1c[i] = 0;
		pref2a[i] = 0;
		pref2b[i] = 0;
		pref2c[i] = 0;
		prefab[i] = 0;
		prefac[i] = 0;
		prefba[i] = 0;
		prefbc[i] = 0;
		prefca[i] = 0;
		prefcb[i] = 0;
		prefsame[i] = 0;

		if (a[i] == 'a') pref1a[i] = 1;
		else if (a[i] == 'b') pref1b[i] = 1;
		else pref1c[i] = 1;

		if (b[i] == 'a') pref2a[i] = 1;
		else if (b[i] == 'b') pref2b[i] = 1;
		else pref2c[i] = 1;


		if (a[i] == b[i]) prefsame[i] = 1;

		if (a[i] == 'a' && b[i] == 'b') prefab[i] = 1;
		if (a[i] == 'a' && b[i] == 'c') prefac[i] = 1;
		if (a[i] == 'b' && b[i] == 'a') prefba[i] = 1;
		if (a[i] == 'b' && b[i] == 'c') prefbc[i] = 1;
		if (a[i] == 'c' && b[i] == 'a') prefca[i] = 1;
		if (a[i] == 'c' && b[i] == 'b') prefcb[i] = 1;


		pref1a[i] += pref1a[i-1];
		pref1b[i] += pref1b[i-1];
		pref1c[i] += pref1c[i-1];
		pref2a[i] += pref2a[i-1];
		pref2b[i] += pref2b[i-1];
		pref2c[i] += pref2c[i-1];

		prefab[i] += prefab[i-1];
		prefac[i] += prefac[i-1];
		prefba[i] += prefba[i-1];
		prefbc[i] += prefbc[i-1];
		prefca[i] += prefca[i-1];
		prefcb[i] += prefcb[i-1];
		prefsame[i] += prefsame[i-1];



	}

}

int get_distance(int x, int y){
	if (!(pref1a[y] - pref1a[x] + (a[x]=='a') ==  pref2a[y] - pref2a[x] + (b[x]=='a') && pref1b[y] - pref1b[x] + (a[x]=='b') ==  pref2b[y] - pref2b[x] + (b[x]=='b') && pref1c[y] - pref1c[x] + (a[x]=='c') ==  pref2c[y] - pref2c[x] + (b[x]=='c'))){
		return -1;
	}
	ll ab = prefab[y] - prefab[x] + (a[x] == 'a' && b[x] == 'b');
	ll ac = prefac[y] - prefac[x] + (a[x] == 'a' && b[x] == 'c');
	ll ba = prefba[y] - prefba[x] + (a[x] == 'b' && b[x] == 'a');
	ll bc = prefbc[y] - prefbc[x] + (a[x] == 'b' && b[x] == 'c');
	ll ca = prefca[y] - prefca[x] + (a[x] == 'c' && b[x] == 'a');
	ll cb = prefcb[y] - prefcb[x] + (a[x] == 'c' && b[x] == 'b');

	ll ans = 0;


	ll sum = ab+ac+ba+bc+ca+cb;

	sum -= min(ab,ba)*2;
	sum -= min(ac,ca)*2;
	sum -= min(bc,cb)*2;

	ans += min(ab,ba) + min(ac,ca) + min(bc,cb);
	ans += sum/3 * 2;
	return ans;

}
