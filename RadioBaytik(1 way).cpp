#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>


struct Node {
    int num;
    std::vector<Node *> neighbors{};
};

struct Point {
    double x;
    double y;
};

std::vector<std::vector<double>> distances;
std::vector<int> color;

void dfs(Node &v, int c) {
    color[v.num] = c;
    for (auto &e : v.neighbors) {
        if (color[e->num] == 0) {
            dfs(*e, 3 - c);
        }
    }
}

bool check(int n, double power) {
    //std::cout << "POWER: " << power << '\n';
    color = std::vector<int>(n, 0);
    std::vector<Node> gr(n);
    for (int i = 0; i < n; ++i) {
        gr[i].num = i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (distances[i][j] < power) {
                //std::cout << i << ' ' << j << '\n';
                gr[i].neighbors.push_back(&gr[j]);
                gr[j].neighbors.push_back(&gr[i]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            dfs(gr[i], 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (distances[i][j] < power && color[i] == color[j]) {
                return false;
            }
        }
    }
    return true;
}

double find_dist(Point &a, Point &b) {
    return std::sqrt(std::pow((a.x - b.x), 2) + std::pow((a.y - b.y), 2));
}

int main() {
    int n;
    std::cin >> n;
    distances.resize(n);
    for (auto &e: distances) {
        e.resize(n);
    }
    std::vector<Point> points(n);
    for (auto &e: points) {
        std::cin >> e.x >> e.y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            distances[i][j] = find_dist(points[i], points[j]);
            distances[j][i] = find_dist(points[i], points[j]);
        }
    }
    double l = 0, r = 100000.0, m, eps = 0.00000001;
    while (r - l > eps) {
        m = (l + r) / 2;
        if (check(n, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    check(n, l);
    std::cout << std::setprecision(8) << std::fixed << r / 2 << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << color[i] << ' ';
    }
}
