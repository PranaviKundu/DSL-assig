#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<vector<int>, vector<int>> dijkstra(int V, vector<pair<int, int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        vector<int> parent(V);

        distTo[S] = 0;
        pq.push({0, S});
        parent[S] = S;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int w = it.first;
                int v = it.second;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    parent[v] = node;
                    pq.push({distTo[v], v});
                }
            }
        }

        return {distTo, parent};
    }
};

int main()
{
    int V = 9, S = 0;
    vector<pair<int, int>> adj[V];

    adj[0].push_back({4, 1});
    adj[0].push_back({8, 7});

    adj[1].push_back({4, 0});
    adj[1].push_back({8, 2});
    adj[1].push_back({11, 7});

    adj[2].push_back({8, 1});
    adj[2].push_back({7, 3});
    adj[2].push_back({4, 5});
    adj[2].push_back({2, 8});

    adj[3].push_back({7, 2});
    adj[3].push_back({9, 4});
    adj[3].push_back({14, 5});

    adj[4].push_back({9, 3});
    adj[4].push_back({10, 5});

    adj[5].push_back({4, 2});
    adj[5].push_back({14, 3});
    adj[5].push_back({10, 4});
    adj[5].push_back({2, 6});

    adj[6].push_back({2, 5});
    adj[6].push_back({1, 7});
    adj[6].push_back({6, 8});

    adj[7].push_back({8, 0});
    adj[7].push_back({11, 1});
    adj[7].push_back({1, 6});
    adj[7].push_back({7, 8});

    adj[8].push_back({2, 2});
    adj[8].push_back({6, 6});
    adj[8].push_back({7, 7});

    Solution obj;
    auto [dist, parent] = obj.dijkstra(V, adj, S);

    vector<tuple<int, int, string, int>> results;

    for (int i = 0; i < V; i++)
    {
        vector<int> path;
        int curr = i;
        while (parent[curr] != curr)
        {
            path.push_back(curr);
            curr = parent[curr];
        }
        path.push_back(S);
        reverse(path.begin(), path.end());

        string pathStr = "";
        for (int j = 0; j < path.size(); ++j)
        {
            pathStr += to_string(path[j]);
            if (j < path.size() - 1)
                pathStr += " → ";
        }

        results.push_back({(int)path.size(), i, pathStr, dist[i]});
    }

    sort(results.begin(), results.end());

    cout << "Shortest paths from source node " << S << ":\n\n";
    for (auto &[length, node, pathStr, cost] : results)
    {
        cout << "Path = " << pathStr << " ; Cost = " << cost << "\n";
    }

    return 0;
}
