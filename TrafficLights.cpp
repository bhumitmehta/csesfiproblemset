#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input: street length (x) and number of traffic lights (n)
    int x, n;
    cin >> x >> n;

    vector<int> positions(n);
    for (int &p : positions) cin >> p;

    // Set to store traffic light positions, initially with 0 and x
    set<int> lights = {0, x};

    // Multiset to store segment lengths

    multiset<int> segments = {x};

    for (int p : positions) {
        // Find the neighboring lights of the current position
        auto it = lights.lower_bound(p);
        int right = *it;
        int left = *prev(it);

        // Update segments: remove old segment and add two new ones
        segments.erase(segments.find(right - left));
        segments.insert(p - left);
        segments.insert(right - p);
        
        // Insert the new light position
        lights.insert(p);
        // Output the maximum segment length
        cout << *segments.rbegin() << " ";
    }
    cout << '\n';
    return 0;
}
