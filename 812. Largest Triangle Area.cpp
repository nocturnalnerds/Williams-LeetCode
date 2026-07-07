#include "lib.h"

class Solution {
public:
    double largestTriangleArea(std::vector<std::vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // shoelace formula for area of triangle
                    double area = 0.5 * std::abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                    );
                    maxArea = std::max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};