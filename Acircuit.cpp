#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using vecint = std::vector<int>;

// Function to read input
template <typename T=int>
T input(std::istream& in = std::cin) {
    T value;
    in >> value;
    return value;
}

// Function to read a vector of inputs
template<typename T=int>
std::vector<T> take_vector(size_t size, std::istream& in = std::cin) {
    std::vector<T> vec;
    std::copy_n(std::istream_iterator<T>(in), size, std::back_inserter(vec));
    return vec;
}

// Function to print output
template <typename T=int>
void print(T val, const std::string& delimiter = "\n") {
    std::cout << val << delimiter;
}

int main() {
    int t = input();  // Read the number of test cases
    while (t-- > 0) {
        int n = input();  // Read the number of lights
        vecint v = take_vector(2 * n);  // Read the states of the 2n switches
        
        int ones = std::count(v.begin(), v.end(), 1);  // Count the number of switches that are on (state 1)

        // Calculate the maximum number of lights that can be on
        int max = std::min(ones, 2 * n - ones);

        // Calculate the minimum number of lights that can be on
        int min = (ones % 2 == 0) ? 0 : 1;

        // Print the results
        print(min, " ");
        print(max);
    }
    return 0;
}
