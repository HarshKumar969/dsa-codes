#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool issafe(int x, int y, vector<vector<int>> &visited, vector<vector<int>> &m, int n) {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0 && m[x][y] == 1)) {
            return true;
        }
        else {
            return false;
        }
    }

    void solve(vector<vector<int>> &m, int n, vector<string> &ans, int srcx, int srcy, vector<vector<int>> &visited, string path) {
        if (srcx == n - 1 && srcy == n - 1) {
            ans.push_back(path);
            return;
        }
        visited[srcx][srcy] = 1;

        // down
        int newx = srcx + 1, newy = srcy;
        if (issafe(newx, newy, visited, m, n)) {
            path.push_back('D');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // up
        newx = srcx - 1, newy = srcy;
        if (issafe(newx, newy, visited, m, n)) {
            path.push_back('U');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // left
        newx = srcx, newy = srcy - 1;
        if (issafe(newx, newy, visited, m, n)) {
            path.push_back('L');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        // right
        newx = srcx, newy = srcy + 1;
        if (issafe(newx, newy, visited, m, n)) {
            path.push_back('R');
            solve(m, n, ans, newx, newy, visited, path);
            path.pop_back();
        }

        visited[srcx][srcy] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";
        solve(m, n, ans, 0, 0, visited, path);

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(m, n);

        if (result.empty())
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";

        cout << endl;
    }

    return 0;
}
