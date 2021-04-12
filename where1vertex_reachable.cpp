#include <algorithm>
#include <iostream>
#include <vector>

void dfs(std::vector<bool> &visited,
         std::vector<std::vector<int>> &edges, int now) {
    visited[now] = true;
    for (const auto &neighbor: edges[now]) {
        if (!visited[neighbor]) {
            dfs(visited, edges, neighbor);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> edges(n + 1);
    for (int i = 0; i < m; ++i) {
        int fr, to;
        std::cin >> fr >> to;
        if (fr != to) {
            edges[to].push_back(fr);
        }
    }
    std::vector<bool> visited(n + 1, false);
    dfs(visited, edges, 1);
    int cnt = 0;
    for (const auto &e: visited) {
        cnt += e;
    }
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) {
            std::cout << i << ' ';
        }
    }
}
