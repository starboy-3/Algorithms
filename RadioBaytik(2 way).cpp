#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

std::vector<int> color(1205, 0);
struct Node {
  double x;
  double y;
  int num;
  bool used = false;
  std::vector<Node*> neighbors;
};

struct Edge {
  int from;
  int to;
  double dist = 0;
};

double dist(Node& f, Node& s) {
    return sqrt((f.x - s.x) * (f.x - s.x) + (f.y - s.y) * (f.y - s.y));
}

void dfs(Node& v, int c) {
    v.used = true;
    color[v.num] = c;
    for (auto& e : v.neighbors) {
        if (!e->used) {
            dfs(*e, 3 - c);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Edge> edges;
    std::vector<Node> graph(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> graph[i].x >> graph[i].y;
        graph[i].num = i;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            double d = dist(graph[i], graph[j]);
            edges.push_back({i, j, d});
        }
    }

    std::sort(edges.begin(), edges.end(), [](Edge& f, Edge& s) {
      return f.dist < s.dist;
    });
    for (int i = 0; i < n - 1; ++i) {
        graph[edges[i].from].neighbors.push_back(&graph[edges[i].to]);
        graph[edges[i].to].neighbors.push_back(&graph[edges[i].from]);
    }
    dfs(graph[1], 1);
    double m = 1e8;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (color[i] == color[j]) {
                m = std::min(m, dist(graph[i], graph[j]));
            }
        }
    }
    std::cout << std::setprecision(8) << std::fixed << m / 2 << '\n';
    for (int i = 1; i <= n; ++i) {
        std::cout << color[i] << ' ';
    }
}
