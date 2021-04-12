#include <algorithm>
#include <iostream>
#include <map>
#include <vector>


std::vector<int> di = {0, -1, 1, 0};
std::vector<int> dj = {1, 0, 0, -1};

void dfs(std::map<std::vector<int>, bool>& visited,
         std::vector<std::vector<char>>& field, std::vector<int> now) {
    visited[now] = true;
    for (int i = 0; i < 4; ++i) {
        int x = now[0] + di[i];
        int y = now[1] + dj[i];
        if (field[x][y] == '.' && !visited[{x, y}]) {
            dfs(visited, field, {x, y});
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<char>> field(n, std::vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> field[i][j];
        }
    }
    std::map<std::vector<int>, bool> visited;
    std::vector<int> start(2);
    std::cin >> start[0] >> start[1];
    start[0]--;
    start[1]--;
    dfs(visited, field, start);
    int square = 0;
    for (auto& p: visited) {
        square += p.second;
    }
    std::cout << square << "\n";
}
