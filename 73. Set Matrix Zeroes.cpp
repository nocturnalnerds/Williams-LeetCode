#include "lib.h"

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool visited[n+1][m+1];
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && matrix[i][j] == 0){
                    for(int k=0;k<n;k++){
                        if(matrix[k][j] == 0 && !visited[i][j]) continue;
                        matrix[k][j] = 0;
                        visited[k][j] = true;
                    }
                    for(int k=0;k<m;k++){
                        if(matrix[i][k] == 0 && !visited[i][j]) continue;
                        matrix[i][k] = 0;
                        visited[i][k] = true;
                    }
                }
            }
        }
    }
};