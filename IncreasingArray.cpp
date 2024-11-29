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
template <typename T=int>
T input(std::istream& in = std::cin) {
    T value;
    in >> value;
    return value;
}


template <typename T=int>
void print(T val,const std::string& delimiter = "\n") {
    std::cout<< val << delimiter;
   
}



int main(){
    long long int a  = input<long long int >();
    std::vector<long long int> b = take_vector<long long int>(a);
    long long int totalDiff ;
    // print(totalDiff);
    for(int i=1;i<a;i++){
        long long int diff = b[i-1] - b[i];
       if (diff > 0){
            totalDiff += (diff);
            b[i] = b[i-1];
       }
    }
    print<long long int>(totalDiff);
    return 0;
}