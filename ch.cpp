#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int k = 1; k <= n; ++k) {
        // Total ways to place two knights
        long long total_ways = (long long)k * k * (k * k - 1) / 2;
        
        // Attacking ways (only applicable if k >= 2)
        long long attack_ways = 4 * (k - 1) * (k - 2);
        
        // Non-attacking ways
        long long non_attacking_ways = total_ways - attack_ways;
        
        cout << non_attacking_ways << endl;
    }

    return 0;
}
