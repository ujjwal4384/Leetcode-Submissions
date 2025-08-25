class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {    
        vector<vector<pair<int,int>>> adj(n);
        for (auto &edge : flights) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        int steps = 0;
        while (!q.empty() && steps <= k) {
            int sz = q.size();
            vector<int> temp = dist;  // keep old distances for this level

            while (sz--) {
                int node = q.front(); 
                q.pop();

                for (auto [adjNode, w] : adj[node]) {
                    if (dist[node] != INT_MAX && dist[node] + w < temp[adjNode]) {
                        temp[adjNode] = dist[node] + w;
                        q.push(adjNode);
                    }
                }
            }

            dist = temp;  // update after finishing this layer
            steps++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
