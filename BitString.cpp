#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric> 
#include <stdexcept> 
#include <cmath> 

using lli = long long int;
#define RESULT_MODULO  1000000007 

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
        std::cout << vec.back();
    }
    std::cout << std::endl;
}

template<typename T>
T sum_vector_element(const std::vector<T>& vec, int start = 0, int end = -1) {
    if (end == -1) {
        end = vec.size();
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

template <typename T=int>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T=int>
bool isOdd(T val) {
    return val % 2 != 0;
}

template <typename T = int >
T mod_exp(T base,T exp,T mod){
    T result= 1;
    while(exp >= 1){
        if(exp%2==1){
            result =(result*base)%mod;
            
        }
        base = (base*base)%mod;
        exp /=2;
    }
    return result;
}


int main() {
    lli n = input<lli>(); // Read input value
    lli result = (mod_exp<lli>(2, n ,RESULT_MODULO ) ) % RESULT_MODULO;
    print<lli>(result); // Print the result
    return 0;
}
