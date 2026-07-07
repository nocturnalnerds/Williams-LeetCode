#include "lib.h"
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> arr(n, std::vector<int>(n, 0));

        int dir = 1; 
        int i = 0, j = 0;
        
        for(int num = 1; num <= n*n; num++) {
            arr[i][j] = num;

            if(dir == 1) { 
                if(j+1 == n || arr[i][j+1] != 0) { dir = 2; i++; }
                else j++;
            }
            else if(dir == 2) { 
                if(i+1 == n || arr[i+1][j] != 0) { dir = 3; j--; }
                else i++;
            }
            else if(dir == 3) { 
                if(j-1 < 0 || arr[i][j-1] != 0) { dir = 4; i--; }
                else j--;
            }
            else {
                if(i-1 < 0 || arr[i-1][j] != 0) { dir = 1; j++; }
                else i--;
            }
        }
        return arr;
    }
};