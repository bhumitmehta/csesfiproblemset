#include <iostream>
#include <vector>
#include <algorithm>
#include <limits> // For INT_MAX

using lli = long long int;
using veclli = std::vector<lli>;

template <typename T = int>
T input(std::istream& in = std::cin) {
    T value;
    in >> value;
    return value;
}

template<typename T = int>
std::vector<T> take_vector(size_t size, std::istream& in = std::cin) {
    std::vector<T> vec(size);
    for (size_t i = 0; i < size; i++) {
        in >> vec[i];
    }
    return vec;
}

template<typename T>
void print(T val, const std::string& delimiter = "\n") {
    std::cout << val << delimiter;
}

int main() {
    int n = input();
    int t = input();
    veclli coins = take_vector<lli>(n);

    // Sort coins to ensure the smallest coins are considered first (optional)
    std::sort(coins.begin(), coins.end());

    // Create a 1D DP array initialized with a large value (unreachable state)
    std::vector<lli> dp(t + 1, std::numeric_limits<lli>::max());
    dp[0] = 0; // Base case: it takes 0 coins to make sum 0

    // Iterate through each coin
    for (const auto& coin : coins) {
        for (int j = coin; j <= t; j++) {
            if (dp[j - coin] != std::numeric_limits<lli>::max()) {
                dp[j] = std::min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    // The answer is in dp[t], or -1 if it is still an unreachable state
    lli result = dp[t];
    print((result == std::numeric_limits<lli>::max()) ? -1 : result);

    return 0;
}
