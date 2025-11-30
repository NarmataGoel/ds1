#include <bits/stdc++.h>
using namespace std;

class graph {
    int v;
    vector<vector<pair<int,int>>> adj;

public:
    graph(int x) {
        v = x;
        adj.resize(v);
    }

    void addedges(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto &it : adj[node]) {
                if (!visited[it.first]) {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFS(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto &it : adj[node]) {
            if (!visited[it.first]) {
                DFS(it.first, visited);
            }
        }
    }

    // Dijkstra
    void Dijkstra(int start) {
        vector<int> dis(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;

                if (dist + wt < dis[adjnode]) {
                    dis[adjnode] = dist + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        cout << "Shortest Distance from " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << i << " : " << dis[i] << endl;
        }
    }

    // Prim's
    void prims(int start) {
        vector<bool> vis(v, false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += dist;

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (!vis[adjnode]) {
                    pq.push({wt, adjnode});
                }
            }
        }

        cout << "Prim MST Total Weight = " << sum << endl;
    }

    // Disjoint Set
    int parentnode(int node, vector<int> &parent) {
        if (parent[node] == node) return node;
        return parent[node] = parentnode(parent[node], parent);
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = parentnode(u, parent);
        int pv = parentnode(v, parent);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Kruskal
    int kruskal() {
        vector<pair<int, pair<int,int>>> edges;

        for (int i = 0; i < v; i++) {
            for (auto &it : adj[i]) {
                edges.push_back({it.second, {i, it.first}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(v), rank(v, 0);
        for (int i = 0; i < v; i++) parent[i] = i;

        int mstwt = 0;

        for (auto &it : edges) {
            int node = it.second.first;
            int adjnode = it.second.second;
            int wt = it.first;

            if (parentnode(node, parent) != parentnode(adjnode, parent)) {
                mstwt += wt;
                unionset(node, adjnode, parent, rank);
            }
        }

        cout << "Kruskal MST Weight = " << mstwt << endl;
        return mstwt;
    }
};

int main() {
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class graph {
    int v;
    vector<vector<pair<int,int>>> adj;

public:
    graph(int x) {
        v = x;
        adj.resize(v);
    }

    void addedges(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto &it : adj[node]) {
                if (!visited[it.first]) {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFS(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto &it : adj[node]) {
            if (!visited[it.first]) {
                DFS(it.first, visited);
            }
        }
    }

    // Dijkstra
    void Dijkstra(int start) {
        vector<int> dis(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;

                if (dist + wt < dis[adjnode]) {
                    dis[adjnode] = dist + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        cout << "Shortest Distance from " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << i << " : " << dis[i] << endl;
        }
    }

    // Prim's
    void prims(int start) {
        vector<bool> vis(v, false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += dist;

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (!vis[adjnode]) {
                    pq.push({wt, adjnode});
                }
            }
        }

        cout << "Prim MST Total Weight = " << sum << endl;
    }

    // Disjoint Set
    int parentnode(int node, vector<int> &parent) {
        if (parent[node] == node) return node;
        return parent[node] = parentnode(parent[node], parent);
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = parentnode(u, parent);
        int pv = parentnode(v, parent);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Kruskal
    int kruskal() {
        vector<pair<int, pair<int,int>>> edges;

        for (int i = 0; i < v; i++) {
            for (auto &it : adj[i]) {
                edges.push_back({it.second, {i, it.first}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(v), rank(v, 0);
        for (int i = 0; i < v; i++) parent[i] = i;

        int mstwt = 0;

        for (auto &it : edges) {
            int node = it.second.first;
            int adjnode = it.second.second;
            int wt = it.first;

            if (parentnode(node, parent) != parentnode(adjnode, parent)) {
                mstwt += wt;
                unionset(node, adjnode, parent, rank);
            }
        }

        cout << "Kruskal MST Weight = " << mstwt << endl;
        return mstwt;
    }
};

int main() {
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class graph {
    int v;
    vector<vector<pair<int,int>>> adj;

public:
    graph(int x) {
        v = x;
        adj.resize(v);
    }

    void addedges(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto &it : adj[node]) {
                if (!visited[it.first]) {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFS(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto &it : adj[node]) {
            if (!visited[it.first]) {
                DFS(it.first, visited);
            }
        }
    }

    // Dijkstra
    void Dijkstra(int start) {
        vector<int> dis(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;

                if (dist + wt < dis[adjnode]) {
                    dis[adjnode] = dist + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        cout << "Shortest Distance from " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << i << " : " << dis[i] << endl;
        }
    }

    // Prim's
    void prims(int start) {
        vector<bool> vis(v, false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += dist;

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (!vis[adjnode]) {
                    pq.push({wt, adjnode});
                }
            }
        }

        cout << "Prim MST Total Weight = " << sum << endl;
    }

    // Disjoint Set
    int parentnode(int node, vector<int> &parent) {
        if (parent[node] == node) return node;
        return parent[node] = parentnode(parent[node], parent);
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = parentnode(u, parent);
        int pv = parentnode(v, parent);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Kruskal
    int kruskal() {
        vector<pair<int, pair<int,int>>> edges;

        for (int i = 0; i < v; i++) {
            for (auto &it : adj[i]) {
                edges.push_back({it.second, {i, it.first}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(v), rank(v, 0);
        for (int i = 0; i < v; i++) parent[i] = i;

        int mstwt = 0;

        for (auto &it : edges) {
            int node = it.second.first;
            int adjnode = it.second.second;
            int wt = it.first;

            if (parentnode(node, parent) != parentnode(adjnode, parent)) {
                mstwt += wt;
                unionset(node, adjnode, parent, rank);
            }
        }

        cout << "Kruskal MST Weight = " << mstwt << endl;
        return mstwt;
    }
};

int main() {
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class graph {
    int v;
    vector<vector<pair<int,int>>> adj;

public:
    graph(int x) {
        v = x;
        adj.resize(v);
    }

    void addedges(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto &it : adj[node]) {
                if (!visited[it.first]) {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFS(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto &it : adj[node]) {
            if (!visited[it.first]) {
                DFS(it.first, visited);
            }
        }
    }

    // Dijkstra
    void Dijkstra(int start) {
        vector<int> dis(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;

                if (dist + wt < dis[adjnode]) {
                    dis[adjnode] = dist + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        cout << "Shortest Distance from " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << i << " : " << dis[i] << endl;
        }
    }

    // Prim's
    void prims(int start) {
        vector<bool> vis(v, false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += dist;

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (!vis[adjnode]) {
                    pq.push({wt, adjnode});
                }
            }
        }

        cout << "Prim MST Total Weight = " << sum << endl;
    }

    // Disjoint Set
    int parentnode(int node, vector<int> &parent) {
        if (parent[node] == node) return node;
        return parent[node] = parentnode(parent[node], parent);
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = parentnode(u, parent);
        int pv = parentnode(v, parent);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Kruskal
    int kruskal() {
        vector<pair<int, pair<int,int>>> edges;

        for (int i = 0; i < v; i++) {
            for (auto &it : adj[i]) {
                edges.push_back({it.second, {i, it.first}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(v), rank(v, 0);
        for (int i = 0; i < v; i++) parent[i] = i;

        int mstwt = 0;

        for (auto &it : edges) {
            int node = it.second.first;
            int adjnode = it.second.second;
            int wt = it.first;

            if (parentnode(node, parent) != parentnode(adjnode, parent)) {
                mstwt += wt;
                unionset(node, adjnode, parent, rank);
            }
        }

        cout << "Kruskal MST Weight = " << mstwt << endl;
        return mstwt;
    }
};

int main() {
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class graph {
    int v;
    vector<vector<pair<int,int>>> adj;

public:
    graph(int x) {
        v = x;
        adj.resize(v);
    }

    void addedges(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto &it : adj[node]) {
                if (!visited[it.first]) {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFS(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto &it : adj[node]) {
            if (!visited[it.first]) {
                DFS(it.first, visited);
            }
        }
    }

    // Dijkstra
    void Dijkstra(int start) {
        vector<int> dis(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;

                if (dist + wt < dis[adjnode]) {
                    dis[adjnode] = dist + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        cout << "Shortest Distance from " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << i << " : " << dis[i] << endl;
        }
    }

    // Prim's
    void prims(int start) {
        vector<bool> vis(v, false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += dist;

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (!vis[adjnode]) {
                    pq.push({wt, adjnode});
                }
            }
        }

        cout << "Prim MST Total Weight = " << sum << endl;
    }

    // Disjoint Set
    int parentnode(int node, vector<int> &parent) {
        if (parent[node] == node) return node;
        return parent[node] = parentnode(parent[node], parent);
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = parentnode(u, parent);
        int pv = parentnode(v, parent);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Kruskal
    int kruskal() {
        vector<pair<int, pair<int,int>>> edges;

        for (int i = 0; i < v; i++) {
            for (auto &it : adj[i]) {
                edges.push_back({it.second, {i, it.first}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(v), rank(v, 0);
        for (int i = 0; i < v; i++) parent[i] = i;

        int mstwt = 0;

        for (auto &it : edges) {
            int node = it.second.first;
            int adjnode = it.second.second;
            int wt = it.first;

            if (parentnode(node, parent) != parentnode(adjnode, parent)) {
                mstwt += wt;
                unionset(node, adjnode, parent, rank);
            }
        }

        cout << "Kruskal MST Weight = " << mstwt << endl;
        return mstwt;
    }
};

int main() {
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class graph {
    int v;
    vector<vector<pair<int,int>>> adj;

public:
    graph(int x) {
        v = x;
        adj.resize(v);
    }

    void addedges(int u, int v, int w = 1) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // BFS
    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        cout << "BFS: ";

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto &it : adj[node]) {
                if (!visited[it.first]) {
                    visited[it.first] = true;
                    q.push(it.first);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFS(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (auto &it : adj[node]) {
            if (!visited[it.first]) {
                DFS(it.first, visited);
            }
        }
    }

    // Dijkstra
    void Dijkstra(int start) {
        vector<int> dis(v, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dis[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;

                if (dist + wt < dis[adjnode]) {
                    dis[adjnode] = dist + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        cout << "Shortest Distance from " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << i << " : " << dis[i] << endl;
        }
    }

    // Prim's
    void prims(int start) {
        vector<bool> vis(v, false);
        int sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0, start});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (vis[node]) continue;

            vis[node] = true;
            sum += dist;

            for (auto &it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (!vis[adjnode]) {
                    pq.push({wt, adjnode});
                }
            }
        }

        cout << "Prim MST Total Weight = " << sum << endl;
    }

    // Disjoint Set
    int parentnode(int node, vector<int> &parent) {
        if (parent[node] == node) return node;
        return parent[node] = parentnode(parent[node], parent);
    }

    void unionset(int u, int v, vector<int> &parent, vector<int> &rank) {
        int pu = parentnode(u, parent);
        int pv = parentnode(v, parent);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pu] > rank[pv]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    // Kruskal
    int kruskal() {
        vector<pair<int, pair<int,int>>> edges;

        for (int i = 0; i < v; i++) {
            for (auto &it : adj[i]) {
                edges.push_back({it.second, {i, it.first}});
            }
        }

        sort(edges.begin(), edges.end());

        vector<int> parent(v), rank(v, 0);
        for (int i = 0; i < v; i++) parent[i] = i;

        int mstwt = 0;

        for (auto &it : edges) {
            int node = it.second.first;
            int adjnode = it.second.second;
            int wt = it.first;

            if (parentnode(node, parent) != parentnode(adjnode, parent)) {
                mstwt += wt;
                unionset(node, adjnode, parent, rank);
            }
        }

        cout << "Kruskal MST Weight = " << mstwt << endl;
        return mstwt;
    }
};

int main() {
    return 0;
}
