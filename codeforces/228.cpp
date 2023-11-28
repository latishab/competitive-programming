// author : latishab

#include <iostream>
#include <set>
#include <vector>

#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FOR2(i, a, b) for(int i=a; i<b; i++)
#define pushb push_back
#define popb pop_back
#define ll long long

using namespace std;

// Initialize variables
    vector<ll> v;

bool isValid(ll a) {
    if(!v.empty()) {
        FOR2(i, 0, v.size()) {
            if(v[i] == a) return false;
        }
    }

    return true;
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    ll input;

    FOR2(i, 0, 4) {
        cin >> input;
        if(isValid(input)) {
            v.pushb(input);
        }
    }

    if(v.size() != 4) {
        cout << 4-v.size() << endl;
    } else {
        cout << 0 << endl;
    }
return 0;
}
