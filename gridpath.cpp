#include <iostream>
#include <vector>
#include <string>

int total_paths = 0; // Global counter for the number of valid paths

// Function to print the grid state
void print_grid(const std::vector<std::vector<bool>>& grid) {
    for (const auto& row : grid) {
        for (bool cell : row) {
            std::cout << (cell ? "X " : ". ");
        }
        std::cout << '\n';
    }
    std::cout << "-------------------\n";
}

// Function to check if a move will close the path (edge case handling)
bool checkClosed(int x, int y, std::vector<std::vector<bool>>& grid, char c) {
    // Check if the move goes out of bounds or is blocked
    if (c == 'D' && (x + 1 >= 9 || grid[x + 1][y])) { // Moving down from previous position
        if (!(y > 0 && !grid[x + 1][y - 1]) && !(y < 8 && !grid[x + 1][y + 1])) { // Check left or right lateral move is possible
            return true; // Blocked, no lateral move possible
        }
    }
    if (c == 'U' && (x - 1 < 0 || grid[x - 1][y])) { // Moving up from previous position
        if (!(y > 0 && !grid[x - 1][y - 1]) && !(y < 8 && !grid[x - 1][y + 1])) { // Check left or right lateral move is possible
            return true; // Blocked, no lateral move possible
        }
    }
    if (c == 'R' && (y + 1 >= 9 || grid[x][y + 1])) { // Moving right from previous position
        if (!(x > 0 && !grid[x - 1][y]) && !(x < 8 && !grid[x + 1][y])) { // Check up or down lateral move is possible
            return true; // Blocked, no lateral move possible
        }
    }
    if (c == 'L' && (y - 1 < 0 || grid[x][y - 1])) { // Moving left from previous position
        if (!(x > 0 && !grid[x - 1][y]) && !(x < 8 && !grid[x + 1][y])) { // Check up or down lateral move is possible
            return true; // Blocked, no lateral move possible
        }
    }
    return false; // Not blocked
}

// Recursive backtracking function
void solve(std::vector<std::vector<bool>>& grid, const std::string& path, int step, int x, int y) {
    // Base case: Reached the bottom-left corner (7, 1) and path length is 48
    if (x == 7 && y == 1) {
        if (step == 48) {
            total_paths++;
            
        }
        return;
    }
    if (x==7&&y==7){
        return;
    }
    
    // Terminate invalid paths early
    if (step >= 48) return;

    // Mark the current cell as visited
    grid[x][y] = true;

    // Explore all possible directions
    if (path[step] == '?' || path[step] == 'U') {
        if (x > 0 && !grid[x - 1][y] && !checkClosed(x - 1, y, grid, path[step])) { // Move up
            solve(grid, path, step + 1, x - 1, y);
        }
    }
    if (path[step] == '?' || path[step] == 'D') {
        if (x < 8 && !grid[x + 1][y] && !checkClosed(x + 1, y, grid, path[step])) { // Move down
            solve(grid, path, step + 1, x + 1, y);
        }
    }
    if (path[step] == '?' || path[step] == 'L') {
        if (y > 0 && !grid[x][y - 1] && !checkClosed(x, y - 1, grid, path[step])) { // Move left
            solve(grid, path, step + 1, x, y - 1);
        }
    }
    if (path[step] == '?' || path[step] == 'R') {
        if (y < 8 && !grid[x][y + 1] && !checkClosed(x, y + 1, grid, path[step])) { // Move right
            solve(grid, path, step + 1, x, y + 1);
        }
    }

    // Backtrack: Unmark the current cell
    grid[x][y] = false;
}

int main() {
    // Input the 48-character path description
    std::string path;
    std::cin >> path;

    // Initialize grid (9x9) with boundaries as true
    std::vector<std::vector<bool>> grid(9, std::vector<bool>(9, false));
    for (int i = 0; i < 9; i++) {
        grid[0][i] = true;   // Top row
        grid[i][0] = true;   // Left column
        grid[i][8] = true;   // Right column
        grid[8][i] = true;   // Bottom row
    }

    // Call the solve function from the starting position (1, 1)
    solve(grid, path, 0, 1, 1);

    // Output the number of valid paths found
    std::cout << total_paths << std::endl;

    return 0;
}
