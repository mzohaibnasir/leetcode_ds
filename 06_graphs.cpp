#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void printAdjMatrix(int n, int **adj_matrix)
{
    cout << "Resultant: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << adj_matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void insertAdjMatrix(int m, int **adj_matrix)
{
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Input adjacent nodes of edge" << endl;

        cin >> u >> v;

        adj_matrix[u - 1][v - 1] = 1;
        adj_matrix[v - 1][u - 1] = 1;

        cout << "Edge between " << u << " & " << v << "Added" << endl;
    }
}

void insertWeightedAdjMatrix(int m, int **adj_matrix)
{
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Input adjacent nodes of edge" << endl;

        cin >> u >> v >> w;

        adj_matrix[u - 1][v - 1] = w;
        adj_matrix[v - 1][u - 1] = w;

        cout << "Edge between " << u << " & " << v << "Added" << endl;
    }
}

void printAdjList(int n, vector<vector<int>> adj_matrix)
{
    cout << "Resultant List: " << endl;
    for (int i = 0; i < adj_matrix.size(); i++)
    {
        for (int j = 0; j < adj_matrix[i].size(); j++)
        {
            cout << "\t" << adj_matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

vector<vector<int>> insertAdjList(int n, int m)
{
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Input adjacent nodes of edge" << endl;

        cin >> u >> v;

        adj_list[u - 1].push_back(v);
        adj_list[v - 1].push_back(u); // # not required for Directed graph

        cout << "(" << u << " , " << v << ")" << endl;
    }
    cout << "Insertion Done" << endl;
    return adj_list;
}
vector<vector<pair<int, int>>> insertWeightedAdjList(int n, int m)
{
    vector<vector<pair<int, int>>> adj_list(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Input adjacent nodes of edge with weight: n1,n2,w" << endl;

        cin >> u >> v >> w;

        adj_list[u - 1].push_back(make_pair(v, w));
        adj_list[v - 1].push_back(make_pair(u, w)); // # not required for Directed graph

        cout
            << "(" << u << " , " << v << " : " << w
            << ")" << endl;
    }
    cout << "Insertion Done" << endl;

    cout << "Resultant List: " << endl;
    for (int i = 0; i < adj_list.size(); i++)
    { // printing the 2D vector.
        for (int j = 0; j < adj_list[i].size(); j++)
            cout << "(" << adj_list[i][j].first << " , " << adj_list[i][j].second << ") ";
        cout << endl;
    }

    return adj_list;
}

void xBFS(int n)
{
    vector<vector<int>> adj_list = {{2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 7}, {1, 7, 8}, {6, 5}, {6}};

    bool visited[n] = {false};
    int start = 1;
    // int node = start;
    visited[start - 1] = 1;

    queue<int> q;
    q.push(start);
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (int i = 0; i < adj_list[node - 1].size(); i++)
        {
            if (!visited[adj_list[node - 1][i] - 1])
            {
                cout << endl
                     << endl
                     << endl
                     << endl
                     << endl;
                cout << "Accepted: " << adj_list[node - 1][i] << endl;

                visited[adj_list[node - 1][i] - 1] = true;

                cout << "Visited:";
                for (int j = 0; j < n; j++)
                {
                    cout << "\t" << visited[j];
                }
                cout << endl;
                cout << "PUSHED in queue: "
                     << "\t" << adj_list[node - 1][i] << endl;
                q.push(adj_list[node - 1][i]);
            }
        }
    }

    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << "\t";
    }
}

void xxBFS(int n)
{
    vector<vector<int>> adj_list = {{2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 7}, {1, 7, 8}, {6, 5}, {6}};

    queue<int> q;
    int visited[n] = {0};
    vector<int> bfs;

    int start = 1;
    visited[start - 1] = 1;
    q.push(start - 1);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << "\n\n\n Visited: " << node << endl;
        bfs.push_back(node);
        for (int i = 0; i < adj_list[node].size(); i++)
        {
            if (!visited[adj_list[node][i] - 1])

            {
                visited[adj_list[node][i] - 1] = 1;

                q.push(adj_list[node][i] - 1);
            }
        }
        cout << endl
             << "Visited: \t";
        for (auto i : visited)
        {
            cout << "-----------" << i;
        }
        cout << endl
             << "BFS: \t        ";
        for (int i = 0; i < bfs.size(); i++)
        {
            cout << "-----------" << bfs[i] + 1;
        }

        cout << "\n\n\n\n";
    }
    cout << endl
         << "Visited: \t";
    for (auto i : visited)
    {
        cout << "\t" << i;
    }
    cout << endl
         << "BFS: \t";
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << "\t" << bfs[i];
    }
}

void xxxBFS(int n, int s = 1)
{
    vector<vector<int>> adj_list = {{2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 7}, {1, 7, 8}, {6, 5}, {6}};

    int start = 1;

    int visited[n] = {0};

    visited[start - 1] = 1;

    queue<int> q;
    q.push(start - 1);

    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();

        q.pop();
        cout << "\n\n\n Visited: " << node << endl;

        bfs.push_back(node);

        for (int i = 0; i < adj_list[node].size(); i++)
        {
            if (!visited[adj_list[node][i] - 1])
            {
                q.push(adj_list[node][i] - 1);
                visited[adj_list[node][i] - 1] = 1;
            }
        }

        cout << endl
             << "Visited: \t";
        for (auto i : visited)
        {
            cout << "-----------" << i;
        }
        cout << endl
             << "BFS: \t        ";
        for (int i = 0; i < bfs.size(); i++)
        {
            cout << "-----------" << bfs[i] + 1;
        }

        cout << "\n\n\n\n";
    }
    cout << endl
         << "Visited: \t";
    for (auto i : visited)
    {
        cout << "\t" << i;
    }
    cout << endl
         << "BFS: \t";
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << "\t" << bfs[i];
    }
}

void BFS(int n, int start = 1)
{
    vector<vector<int>> adj_list = {{2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 7}, {1, 7, 8}, {6, 5}, {6}};

    int visited[n] = {0};

    int s = start - 1;

    queue<int> q;
    vector<int> bfs;

    q.push(start);
    visited[s] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (int i = 0; i < adj_list[node - 1].size(); i++)
        {
            // node index starts from 1 but adj_list is zero based
            if (!visited[adj_list[node - 1][i] - 1])
            {
                q.push(adj_list[node - 1][i]);
                visited[adj_list[node - 1][i] - 1] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << visited[i] << " ";
    }
    cout << "\n BFS: \n";
    for (int i = 0; i < bfs.size(); i++)
    {
        cout << bfs[i] << " ";
    }
}

//////////////////////////////

// void dfsHelper(int node, vector<int> adj[], int visited[], vector<int> &ls)
// {
//     visited[node] = 1;
//     ls.push_back(node);

//     for (int i = 0; i < adj[node].size(); i++)
//     {
//         if (!visited[adj[node][i]])
//         {
//             dfsHelper(adj[node][i], adj, visited, ls);
//         }
//     }
// }

void dfsHelper(int node, vector<int> &visited, vector<vector<int>> &adj_list, vector<int> &dfs)
{
    dfs.push_back(node);
    visited[node - 1] = 1;
    // cout << "visited: ";
    // for (int i = 0; i < 8; i++)
    // {
    //     cout << visited[i] << " ";
    // }
    // cout << endl;

    // cout << "dfs: ";
    // for (int i = 0; i < dfs.size(); i++)
    // {
    //     cout << dfs[i] << " ";
    // }

    // cout << endl;

    for (int i = 0; i < adj_list[node - 1].size(); i++)
    {
        if (!visited[adj_list[node - 1][i] - 1])
        {
            // int cnode = adj_list[node - 1][i];
            // cout << adj_list[node - 1][i] << "\t";
            dfsHelper(adj_list[node - 1][i], visited, adj_list, dfs);
        }
    }
}

void DFS()
{
    vector<vector<int>> adj_list = {{2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 7}, {1, 7, 8}, {6, 5}, {6}};
    int n = adj_list.size();
    vector<int> visited = {0, 0, 0, 0, 0, 0, 0, 0};
    int start = 1;
    // visited[start - 1] = 1;
    vector<int> dfs;

    dfsHelper(start, visited, adj_list, dfs);

    cout << "\n Visited: \n";

    for (int i = 0; i < n; i++)
    {
        cout << visited[i] << " ";
    }
    cout << "\n DFS: \n";
    for (int i = 0; i < dfs.size(); i++)
    {
        cout << dfs[i] << " ";
    }
}

int main()
{
    int n = 3, m = 8;

    cout << "Input nodes, edges" << endl;
    // cin >> n >> m;
    cout << n << "nodes & " << m << "edges" << endl;

    // int adj_matrix[n][n];

    /*In C++, a double pointer (**) is often used to represent a 2D array or a dynamic array of arrays.

    A single pointer (*) points to a memory address where a single value is stored. In the context of a 2D array, a single pointer can point to the memory address of the first element of an array, but it cannot directly represent the entire 2D array.

    To represent a 2D array dynamically, we need an array of pointers, where each pointer points to a row of the array. Therefore, we use a double pointer (**) to represent this array of pointers.*/

    // int **array;: Declares a double pointer array that can point to an array of pointers.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // int **adj_matrix = new int *[n];
    // for (int i = 0; i < n; i++)
    // {
    //     adj_matrix[i] = new int[n];
    // }

    // printAdjMatrix(n, adj_matrix);
    // insertAdjMatrix(m, adj_matrix);
    // printAdjMatrix(n, adj_matrix);

    ///////////////////////////////////////////////////////////

    // vector<vector<int>> adj_list = insertAdjList(n, m);
    // printAdjList(n, adj_list);
    // BFS(n = 8);
    // xxxBFS(n = 8);

    DFS();

    // CONNECTED components:subgraphs are component
}