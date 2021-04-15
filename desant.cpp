#include<iostream>
#include<algorithm>
#include<vector>
#include <tuple>

struct Node {
  int x, y;
  int val;
  bool visited = false;
};

int n, m;
std::vector<Node> mat;
std::vector<std::vector<Node>> field;
std::vector<int> di = {0, 0, 1, -1};
std::vector<int> dj = {1, -1, 0, 0};


void dfs(Node& v) {
    field[v.x][v.y].visited = true;
    for (int i = 0; i < 4; ++i) {
        int x = std::min(std::max(v.x + di[i], 0), n - 1);
        int y = std::min(std::max(v.y + dj[i], 0), m - 1);
        if (field[x][y].val >= v.val && !field[x][y].visited) {
            dfs(field[x][y]);
        }
    }
}

int main() {
    std::cin >> n >> m;
    field = std::vector<std::vector<Node>> (n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            Node tmp;
            std::cin >> tmp.val;
            tmp.x = i;
            tmp.y = j;
            mat.push_back(tmp);
            field[i].push_back({tmp.x, tmp.y, tmp.val});
        }
    }
    std::sort(mat.begin(), mat.end(), [](Node& a, Node& b) {
      return std::tie(a.val, a.x, a.y) < std::tie(b.val, b.x, b.y);
    });
    int cnt = 0;
    for (auto& v : mat) {
        if (!field[v.x][v.y].visited) {
            ++cnt;
            dfs(v);
        }
    }
    std::cout << cnt << "\n";
}
