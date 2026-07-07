#include "lib.h"
class Solution {
public:
    std::vector<std::vector<int>> reverseSubmatrix(std::vector<std::vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> copyGrid = grid;

        int lenM = std::min(x + k - 1, m - 1);
        int lenN = std::min(y + k - 1, n - 1);

        for(int i = x; i <= (x + lenM) / 2; i++) {
            for(int j = y; j <= lenN; j++) {
                std::swap(copyGrid[i][j], copyGrid[lenM - i + x][j]);
            }
        }
        return copyGrid;
    }
};

/*

[[6,16,14],
[1,2,19],
[14,17,15],
[18,7,6],
[14,12,5]]

[[6,16,14],
[1,2,19],
[14,17,15],
[18,7,6],
[14,12,5]]

[[6,16,14],
[1,2,19],
[14,7,6],
[18,17,15],
[14,12,5]]
*/
