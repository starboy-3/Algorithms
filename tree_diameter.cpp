#include <algorithm>
#include <iostream>
#include <vector>

struct Node {
    int value;
    std::vector<Node *> neighbors{};
    bool was = false;
};

int vert;
int m = 0;

void dfs(Node &v, int depth) {
    v.was = true;
    if (depth > m) {
        m = depth;
        vert = v.value;
    }
    for (auto &e : v.neighbors) {
        if (!e->was) {
            dfs(*e, depth + 1);
        }
    }
}

int main() {
    int n, fr, to;
    std::cin >> n;
    std::vector<Node> vertice;
    for (int i = 0; i < n + 1; ++i) {
        vertice.push_back({i});
    }
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> fr >> to;
        vertice[fr].neighbors.push_back(&vertice[to]);
        vertice[to].neighbors.push_back(&vertice[fr]);
    }
    dfs(vertice[1], 0);
    for (int i = 1; i <= n; ++i) {
        vertice[i].was = false;
    }
    dfs(vertice[vert], 0);
    std::cout << m << "\n";
}
