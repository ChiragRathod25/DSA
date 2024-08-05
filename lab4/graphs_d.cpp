#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int u){
    visited[u] = true;
    cout << u << " ";
    for(int i = 0; i < graph[u].size(); i++){
        int v = graph[u][i];
        if(!visited[v]){
            dfs(graph, visited, v);
        }
    }
}
void bfs(vector<vector<int>> &graph, vector<bool> &visited, int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void matrixRepresent(vector<vector<int>> &mat, vector<vector<int>> edges)
{
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        mat[u][v] = 1;
        mat[v][u] = 1; 
    }
}


void listRepresent(unordered_map<int, list<int>> &mp, vector<vector<int>> edges)
{
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        mp[u].push_back(v);
        mp[v].push_back(u); 
    }
}

int main()
{
    int numVertices = 6; 
    vector<vector<int>> mat(numVertices + 1, vector<int>(numVertices + 1, 0));
    unordered_map<int, list<int>> mp;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 5}, {2, 4}, {3, 6}, {5, 4}, {6, 5}};

 
    listRepresent(mp, edges);
    matrixRepresent(mat, edges);

   
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= numVertices; i++)
    {
        for (int j = 1; j <= numVertices; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

 
    cout << "\nAdjacency List:" << endl;
    for (auto &temp : mp)
    {
        cout << temp.first << "->";
        for (auto &neighbor : temp.second)
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    vector<vector<int>> graph(numVertices + 1);
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "DFS Traversal:" << endl;
    vector<bool> visited(numVertices + 1, false);
    dfs(graph, visited, 1);
    
    cout << "\nBFS Traversal:" << endl;
    visited.assign(numVertices + 1, false);
    bfs(graph, visited, 1);

    return 0;
}