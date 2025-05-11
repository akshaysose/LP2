#include <bits/stdc++.h>
using namespace std;

// Step 1: Calculate Heuristics (Manhattan distance)
int calculateHure(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// Step 2: Check if a cell is safe to move into
bool isSafe(int x, int y, int row, int col, vector<vector<int>>& mat, vector<vector<bool>>& visited) {
    if (x < 0 || y < 0 || x >= row || y >= col) return false;
    if (mat[x][y] == 1 || visited[x][y]) return false;
    return true;
}

// Step 3: Print the final path from start to goal
void printPath(pair<int, int> goal, vector<vector<pair<int, int>>>& parent) {
    stack<pair<int, int>> path;
    pair<int, int> curr = goal;

    while (curr != make_pair(-1, -1)) {
        path.push(curr);
        curr = parent[curr.first][curr.second];
    }

    cout << "Path from Start to Goal:\n";
    while (!path.empty()) {
        cout << "(" << path.top().first << "," << path.top().second << ")";
        path.pop();
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

// Step 4: A* Algorithm function
void aStar(vector<vector<int>>& mat, pair<int, int> start, pair<int, int> goal) {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));

    // Min-heap priority queue: (fCost, gCost, x, y)
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

    int sx = start.first, sy = start.second;
    int gx = goal.first, gy = goal.second;

    int h = calculateHure(sx, sy, gx, gy);
    pq.push({h, 0, sx, sy});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto [f, g, x, y] = pq.top();
        pq.pop();

        if (visited[x][y]) continue;
        visited[x][y] = true;

        if (x == gx && y == gy) {
            printPath(goal, parent);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isSafe(nx, ny, rows, cols, mat, visited)) {
                int newG = g + 1;
                int newH = calculateHure(nx, ny, gx, gy);
                int newF = newG + newH;

                pq.push({newF, newG, nx, ny});
                parent[nx][ny] = {x, y};
            }
        }
    }

    cout << "No path found from Start to Goal\n";
}

int main() {
    vector<vector<int>> mat{
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> end = {4, 2};

    aStar(mat, start, end);

    return 0;
}
