#include "lib.h"
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        const int &m = matrix.size();
        const int &n = matrix[0].size();
        
        std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, false));
        std::vector<int> ans;

        int dirx[] = {0, 1, 0, -1};
        int diry[] = {1, 0, -1, 0};

        int dir = 0;
        int i = 0, j = 0;

        for (int k = 0; k < m * n; k++) {
            ans.push_back(matrix[i][j]);
            vis[i][j] = true;

            int ni = i + dirx[dir];
            int nj = j + diry[dir];

            if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj]) {
                dir = (dir + 1) % 4;
            }

            i += dirx[dir];
            j += diry[dir];
        }

        return ans;
    }
};