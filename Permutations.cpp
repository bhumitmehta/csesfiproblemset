#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> // Include this header for std::accumulate
#include <stdexcept> // Include this header for std::out_of_range
#include <cmath>



template<typename T=int>
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
    if (end == -1) {
        end = vec.size(); // Set end to the size of the vector
    }
    if (start < 0 || end > vec.size() || start >= end) {
        throw std::out_of_range("Invalid start or end index");
    }
    return std::accumulate(vec.begin() + start, vec.begin() + end, T(0));
}

template <typename T=int>
T input(std::istream& in = std::cin) {
    T value;
    in >> value;
    return value;
}

template <typename T=int>
void print(T val, const std::string& delimiter = "\n") {
    std::cout << val << delimiter;
}






int main() {
    int a = input();
    if (a == 1) {
        print(1);
    } else if (a <= 3) {
        print<std::string>("NO SOLUTION");
    } else {
        for (int i = 2; i <= a; i += 2) {
            print(i, " ");
        }
        for (int i = 1; i <= a; i += 2) { // Change condition to i <= a
            print(i, " ");
        }
    }
    return 0;
}
