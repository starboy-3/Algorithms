#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
  int value;
  std::vector<Node*> neighbors{};
  bool was = false;
};

void dfs(Node& v, std::vector<int>& comp) {
    v.was = true;
    comp.push_back(v.value);
    for (auto& e : v.neighbors) {
        if (!e->was) {
            dfs(*e, comp);
        }
    }
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
    std::vector<std::vector<int>> all_comp;
    for (auto& vertex : vertice) {
        if (!vertex.was) {
            std::vector<int> comp;
            dfs(vertex, comp);
            all_comp.push_back(comp);
        }
    }
    std::cout << all_comp.size() - 1 << '\n';
    for (size_t i = 1; i < all_comp.size(); ++i) {
        std::cout << all_comp[i].size() << "\n";
        for (const auto& e: all_comp[i]) {
            std::cout << e << ' ';
        }
        std::cout << "\n";
    }
}
