#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> // Include this header for std::accumulate
#include <stdexcept> // Include this header for std::out_of_range




template<typename T>
std::vector<T> take_vector(size_t size, std::istream& in = std::cin) {
    std::vector<T> vec;
    std::copy_n(std::istream_iterator<T>(in), size, std::back_inserter(vec));
    return vec;
}

template<typename T>
void print_vector(const std::vector<T>& vec, const std::string& delimiter = " ") {
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1, std::ostream_iterator<T>(std::cout, delimiter.c_str()));
        std::cout << vec.back(); // Print last element without delimiter
    }
    std::cout << std::endl;
}

template<typename T>
T sum_vector_element(const std::vector<T>& vec, int start = 0, int end = -1) {
    // Set end to the size of the vector if not provided
    if (end == -1) {
        end = vec.size(); // Set end to the size of the vector
    }

    // Ensure that the start and end indices are within bounds
    if (start < 0 || end > vec.size() || start >= end) {
        throw std::out_of_range("Invalid start or end index");
    }

    // Use std::accumulate to sum the elements in the specified range
    return std::accumulate(vec.begin() + start, vec.begin() + end, T(0));
}

long long int findMinDifference(const std::vector<int>& vec, int index, long long int sum1, long long int sum2) {
    // Base case: when all apples have been assigned
    if (index == vec.size()) {
        return std::abs(sum1 - sum2);
    }
    
    // Either put the current apple in the first group or the second group
    long long int includeInFirstGroup = findMinDifference(vec, index + 1, sum1 + vec[index], sum2);
    long long int includeInSecondGroup = findMinDifference(vec, index + 1, sum1, sum2 + vec[index]);
    
    // Return the minimum difference
    return std::min(includeInFirstGroup, includeInSecondGroup);
}


long long int solve(const std::vector<int>& vec) {
    return findMinDifference(vec, 0, 0, 0);
}

int main(){
    int n;
    std::cin >> n;
    auto vec = take_vector<int>(n);
    long long int sum = solve(vec);
    std::cout<<sum;

    return 0;
}