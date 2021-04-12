#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  int value;
  int color = 0;
  std::vector<Node*> neighbors{};
};

int invert(int c) {
    return c == 1 ? 2 : 1;
}

bool dfs(Node& v, int c) {
    v.color = c;
    bool acyclic = true;
    for (auto& e : v.neighbors) {
        if (e->color == 0) {
            acyclic = acyclic && dfs(*e, invert(c));
        } else if (e->color == c) {
            return false;
        }
    }
    return acyclic;
}

int main() {
    int n, m, fr, to;
    std::cin >> n >> m;
    std::vector<Node> vertice;
    for (int i = 0; i < n + 1; ++i) {
        vertice.push_back({i});
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> fr >> to;
        vertice[fr].neighbors.push_back(&vertice[to]);
        vertice[to].neighbors.push_back(&vertice[fr]);
    }
    for (auto& vertex : vertice) {
        if (vertex.color == 0 && !dfs(vertex, 1)) {
            std::cout << "NO" << "\n";
            return 0;
        }
    }
    std::cout << "YES" << "\n";
}
