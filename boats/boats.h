#pragma once

#include <vector>


using Matrix = std::vector<std::vector<char>>;


inline std::size_t calcBoats(const Matrix& matrix) {
    const std::size_t yLast = matrix.size() - 1;
    const std::size_t xLast = matrix[0].size() - 1;

    std::size_t count = 0;

    for (std::size_t y = 0; y <= yLast; y++) {
        for (std::size_t x = 0; x <= xLast; x++) {
            if (matrix[y][x]) {
                if (y == yLast && x == xLast) {
                    count++;
                }
                else if (y == yLast && !matrix[y][x + 1]) {
                    count++;
                }
                else if (x == xLast && !matrix[y + 1][x]) {
                    count++;
                }
                else if (y < yLast && x < xLast && !matrix[y + 1][x] && !matrix[y][x + 1]) {
                    count++;
                }
            }
        }
    }

    return count;
}
