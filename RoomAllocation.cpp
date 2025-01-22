#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using lli = long long int;

struct customers {
    lli arrival;
    lli dep;
    int id;
};

struct CompareCustomers {
    bool operator()(const customers& a, const customers& b) {
        return a.dep > b.dep; // Min-heap based on dep time
    }
};

int main() {
    int n;
    std::cin >> n;
    std::vector<customers> rooms;
    for (int i = 0; i < n; i++) {
        lli a, b;
        std::cin >> a >> b;
        rooms.push_back({a, b, i});
    }

    // Sort customers by arrival time
    std::sort(rooms.begin(), rooms.end(), [](customers a, customers b) {
        if (a.arrival != b.arrival) {
            return a.arrival < b.arrival;
        } else {
            return a.dep < b.dep;
        }
    });

    // Priority queue to manage room allocations
    std::priority_queue<customers, std::vector<customers>, CompareCustomers> pq;
    std::vector<int> room_assignment(n);
    int max_rooms = 0;
    int current_rooms = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> available_rooms;

    for (int i = 0; i < n; i++) {
        // Free up rooms that are available before or at the current customer's arrival
        while (!pq.empty() && pq.top().dep < rooms[i].arrival) {
            available_rooms.push(room_assignment[pq.top().id]);
            pq.pop();
        }

        // Assign a room to the current customer
        if (available_rooms.empty()) {
            current_rooms++;
            room_assignment[rooms[i].id] = current_rooms;
            max_rooms = std::max(max_rooms, current_rooms);
        } else {
            room_assignment[rooms[i].id] = available_rooms.top();
            available_rooms.pop();
        }

        pq.push(rooms[i]);
    }

    // Output the results
    std::cout << max_rooms << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << room_assignment[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}