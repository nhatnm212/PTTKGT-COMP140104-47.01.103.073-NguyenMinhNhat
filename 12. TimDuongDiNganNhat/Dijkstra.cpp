#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 10000;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN]; // M?ng vector ch?a các c?nh c?a d? th?
int dist[MAXN]; // M?ng luu tr? kho?ng cách ng?n nh?t t? d?nh b?t d?u d?n các d?nh còn l?i
bool visited[MAXN]; // M?ng dánh d?u các d?nh dã du?c duy?t

void dijkstra(int start) {
    memset(dist, INF, sizeof(dist)); // Kh?i t?o kho?ng cách c?a t?t c? các d?nh là vô cùng
    memset(visited, false, sizeof(visited)); // Kh?i t?o t?t c? các d?nh chua du?c duy?t
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // S? d?ng priority_queue d? luu các d?nh có kho?ng cách ng?n nh?t

    dist[start] = 0; // Ð?t kho?ng cách c?a d?nh b?t d?u là 0
    pq.push(make_pair(0, start)); // Thêm d?nh b?t d?u vào priority_queue

    while (!pq.empty()) {
        int u = pq.top().second; // L?y d?nh có kho?ng cách ng?n nh?t
        pq.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true; // Ðánh d?u d?nh dã du?c duy?t

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[v] > dist[u] + w) { // N?u tìm th?y du?ng di ng?n hon, c?p nh?t l?i kho?ng cách và thêm d?nh vào priority_queue
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    dijkstra(start);
    if (dist[end] == INF) { // N?u không tìm th?y du?ng di gi?a hai d?nh, in ra "NO"
        cout << "NO\n";
    } else { // Ngu?c l?i, in ra kho?ng cách ng?n nh?t và du?ng di
        cout << dist[end] << "\n";
        vector<int> path;
        int u = end;
        while (u != start) {
            path.push_back(u);
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;
                if (dist[u] == dist[v] + w) {
                    u = v;
                    break;
                }
            }
        }
        path.push_back(start);
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

