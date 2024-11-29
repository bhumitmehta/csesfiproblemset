#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> // For std::accumulate
#include <stdexcept> // For std::out_of_range
#include <cmath>

using vecint = std::vector<int>;
using str = std::string;
using lli = long long int;
#define RESULT_MODULO 1000000007 // Corrected macro

// Function to take vector input
template<typename T = int>
std::vector<T> take_vector(size_t size, std::istream& in = std::cin) {
    std::vector<T> vec;
    std::copy_n(std::istream_iterator<T>(in), size, std::back_inserter(vec));
    return vec;
}

// Function to print vector elements
template<typename T>
void print_vector(const std::vector<T>& vec, const std::string& delimiter = " ") {
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<T>(std::cout, delimiter.c_str()));
        std::cout << vec.back(); // Print last element without delimiter
    }
    std::cout << std::endl;
}

// Function to sum elements of a vector within a specified range
template<typename T>
T sum_vector_element(const std::vector<T>& vec, int start = 0, int end = -1) {
    if (end == -1) {
        end = vec.size(); // Set end to the size of the vector
    }
    if (start < 0 || end > vec.size() || start >= end) {
        throw std::out_of_range("Invalid start or end index");
    }
    return std::accumulate(vec.begin() + start, vec.begin() + end, T(0));
}

// Template function to input a value
template <typename T = int>
T input(std::istream& in = std::cin) {
    T value;
    in >> value;
    return value;
}

// Function to print a single value
template <typename T = int>
void print(T val, const std::string& delimiter = "\n") {
    std::cout << val << delimiter;
}

// Variadic template function to print multiple values
template <typename T, typename... Args>
void print(T first, const std::string& delimiter, Args... args) {
    std::cout << first << delimiter;
    print(args..., delimiter); // Recursively call with the remaining arguments
}

// Template function to find the maximum of two values
template <typename T = int>
T max(T a, T b) {
    return (a > b) ? a : b;
}

// Template function to find the minimum of two values
template <typename T = int>
T min(T a, T b) {
    return (a < b) ? a : b;
}

// Template function to check if a value is odd
template <typename T = int>
bool isOdd(T val) {
    return val % 2 != 0;
}

// Template function for modular exponentiation
template <typename T = int>
T mod_exp(T base, T exp, T mod) {
    T result = 1;
    while (exp >= 1) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int result =0;

bool isSafe(const std::vector<std::vector<char>>& chess, int row, int col) {
    // Check column above
    for (int i = 0; i < row; i++) {
        if (chess[i][col] == 'q') {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 'q') {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; i--, j++) {
        if (chess[i][j] == 'q') {
            return false;
        }
    }

    return true; // Position is safe
}


void solve(std::vector<std::vector<char>>& chess,int row){
    if (row ==8){
        result ++;
        return ;
    }else {
        for(int i=0;i<8;i++){
            if (chess[row][i]!='*'){
            chess[row][i] ='q';
            if(isSafe(chess , row ,i)){
                solve(chess,row+1);
            }
            chess[row][i] = '.';
            }
        }
    }
}

int main(){
    std::vector<std::vector<char>> chess(8);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            chess[i].push_back(input<char>());
        }
    }
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         print<char>(chess[i][j], " ");
    //     }print("");
    // }
    
    solve(chess,0);
    print(result);
    return 0;
}