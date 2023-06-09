//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) {
        // code here
        vector<int> in_degree(V, 0);
        vector<int> adj[V];
        for (auto vec: prerequisites) {
            int u = vec[0], v = vec[1];
            in_degree[u]++;
            adj[v].push_back(u);
        }
        queue<int> q; vector<int> res;
        for (int i=0; i<V; i++) {
            if (in_degree[i]) continue;
            q.push(i);
        }
        while (not q.empty()) {
            int v = q.front(); q.pop(); res.push_back(v);
            for (int c: adj[v]) {
                in_degree[c]--;
                if (not in_degree[c]) q.push(c);
            }
        }
        if (res.size() != V) return {};
        else return res;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends