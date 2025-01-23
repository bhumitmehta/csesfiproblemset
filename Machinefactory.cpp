#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool canProduce(const vector<long long>& machines, long long t, long long time) {
    long long totalProducts = 0;
    for (long long machine : machines) {
        totalProducts += time / machine;
        if (totalProducts >= t) {
            return true; // No need to check further if we've already met the requirement
        }
    }
    return totalProducts >= t;
}

long long findMinTime(int n, long long t, const vector<long long>& machines) {
    long long low = 1; // Minimum possible time
    long long high = *min_element(machines.begin(), machines.end()) * t; // Maximum possible time
    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canProduce(machines, t, mid)) {
            result = mid; // Store the current minimum feasible time
            high = mid - 1; // Try for a smaller time
        } else {
            low = mid + 1; // Try for a larger time
        }
    }

    return result;
}

int main() {
    int n;
    long long t;
    cin >> n >> t;

    vector<long long> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    cout << findMinTime(n, t, machines) << endl;

    return 0;
}
