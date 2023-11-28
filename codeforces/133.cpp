// author : latishab

#include <iostream>
#include <string>
#include <vector>

#define pushb push_back
#define popb pop_back
#define ll long long

using namespace std;

void solve(string a) {
    bool bisa = false;
    for(int i=0; i < a.size(); i++) {
        if((a[i] == 'H') || (a[i] == 'Q') || (a[i] == '9')) {
            bisa = true;
        } 
    }

    if(bisa) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    string p;

    cin >> p;
    solve(p);



return 0;
}
