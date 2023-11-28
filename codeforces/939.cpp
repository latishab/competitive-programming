// author : latishab

#include <iostream>
#include <vector>

#define pushb push_back
#define popb pop_back
#define ll long long

using namespace std;


int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int n, input;
    bool love = false;

    cin >> n;
    vector<int> adj[n+1];

    for(int i=1; i<=n; i++) {
        cin >> input;
        adj[i].pushb(input);
    }

    int check = 0;
    for(int i=1; i<=n; i++) {
        check = adj[i][0];
        if(adj[adj[check][0]][0] == i) {
            love = true;
            break;
        }
    }

    if(love) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

return 0;
}
