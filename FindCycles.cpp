#include <algorithm>
#include <iostream>
#include <vector>

int n;
std::vector <std::vector<int>> g;
std::vector<bool> visited;
std::vector<int> parents;
int cycle_st, cycle_end;

bool dfs(int v) {
    visited[v] = true;
    for (auto& e : g[v]) {
        int to = e;
        if (!visited[to]) {
            parents[to] = v;
            if (dfs(to))
                return true;
        } else if (visited[to]) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    visited[v] = 2;
    return false;
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool exists;
            std::cin >> exists;
            if (exists) {
                g[i].push_back(j);
            }
        }
    }
    parents = std::vector<int>(n, -1);
    visited = std::vector<bool>(n, 0);
    cycle_st = -1;
    for (int i = 1; i <= n; ++i) {
        if (dfs(i)) {
            break;
        }
    }
    if (cycle_st == -1) {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    std::vector<int> cycle;
    cycle.push_back(cycle_st);
    for (int v = cycle_end; v != cycle_st; v = parents[v]) {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_st);
    reverse(cycle.begin(), cycle.end());
    std::cout << cycle.size() << "\n";
    for (auto& e : cycle)
        std::cout << e << ' ';
}
