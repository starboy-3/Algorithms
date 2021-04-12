#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int value;
    int tree_size = 1;
    std::vector<Node*> neighbors{};
    bool was = false;
};

void dfs(Node& v) {
    v.was = true;
    for (auto& e : v.neighbors) {
        if (!e->was) {
            dfs(*e);
            v.tree_size += e->tree_size;
        }
    }
}

int main() {
    int n, fr, to;
    std::cin >> n;
    int m = n - 1;
    std::vector<Node> vertice;
    for (int i = 0; i < n + 1; ++i) {
        vertice.push_back({i});
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> fr >> to;
        vertice[fr].neighbors.push_back(&vertice[to]);
        vertice[to].neighbors.push_back(&vertice[fr]);
    }
    dfs(vertice[1]);
    for (int i = 1; i <= n; ++i) {
        std::cout << vertice[i].tree_size << " ";
    }
}
