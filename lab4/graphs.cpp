#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int j = 0; j < graph[i].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}