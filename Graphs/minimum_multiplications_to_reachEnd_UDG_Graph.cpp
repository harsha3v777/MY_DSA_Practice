#include <bits/stdc++.h>
using namespace std;

// ------------------- BFS with Visited Array -------------------
class SolutionBFS {
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        if (start == end) return 0;

        queue<pair<int,int>> q;
        vector<int> vis(100000, 0);

        q.push({start, 0});
        vis[start] = 1;

        while (!q.empty()) {
            auto front = q.front();
            int node = front.first;
            int steps = front.second;
            q.pop();

            if (node == end) return steps;

            for (auto nbr : arr) {
                int next = (node * nbr) % 100000;
                if (!vis[next]) {
                    vis[next] = 1;
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};

// ------------------- Dijkstra with Priority Queue -------------------
class SolutionDijkstra {
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        if (start == end) return 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(100000, 1e9);

        pq.push({0, start});
        dist[start] = 0;

        while (!pq.empty()) {
            auto front = pq.top();
            int steps = front.first;
            int node = front.second;
            pq.pop();

            if (node == end) return steps;

            for (auto nbr : arr) {
                int next = (node * nbr) % 100000;
                if (dist[next] > steps + 1) {
                    dist[next] = steps + 1;
                    pq.push({steps + 1, next});
                }
            }
        }
        return -1;
    }
};

// ------------------- BFS with Queue + Dist Array -------------------
//O(100000*N)
class SolutionQueueDist {
public:
    int minimumMultiplications(vector<int> &arr, int start, int end) {
        if (start == end) return 0;

        vector<int> dist(100000, 1e9);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end) return dist[node];

            for (auto nbr : arr) {
                int next = (node * nbr) % 100000;
                if (dist[next] > dist[node] + 1) {
                    dist[next] = dist[node] + 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};

// ------------------- Driver Code -------------------
int main() {
    SolutionBFS solBFS;
    SolutionDijkstra solDijkstra;
    SolutionQueueDist solQueueDist;

    // 🔹 Example testcases
    vector<int> arr1 = {2, 5, 10};
    cout << "BFS Test 1: " << solBFS.minimumMultiplications(arr1, 3, 30) << "\n";        
    cout << "Dijkstra Test 1: " << solDijkstra.minimumMultiplications(arr1, 3, 30) << "\n";
    cout << "Queue+Dist Test 1: " << solQueueDist.minimumMultiplications(arr1, 3, 30) << "\n"; // Expected 1

    vector<int> arr2 = {2, 3};
    cout << "BFS Test 2: " << solBFS.minimumMultiplications(arr2, 2, 512) << "\n";       
    cout << "Dijkstra Test 2: " << solDijkstra.minimumMultiplications(arr2, 2, 512) << "\n";
    cout << "Queue+Dist Test 2: " << solQueueDist.minimumMultiplications(arr2, 2, 512) << "\n"; // Expected 8

    vector<int> arr3 = {2};
    cout << "BFS Test 3: " << solBFS.minimumMultiplications(arr3, 99999, 1) << "\n";     
    cout << "Dijkstra Test 3: " << solDijkstra.minimumMultiplications(arr3, 99999, 1) << "\n";
    cout << "Queue+Dist Test 3: " << solQueueDist.minimumMultiplications(arr3, 99999, 1) << "\n"; // Expected -1

    vector<int> arr4 = {99999};
    cout << "BFS Test 4: " << solBFS.minimumMultiplications(arr4, 1, 99999) << "\n";     
    cout << "Dijkstra Test 4: " << solDijkstra.minimumMultiplications(arr4, 1, 99999) << "\n";
    cout << "Queue+Dist Test 4: " << solQueueDist.minimumMultiplications(arr4, 1, 99999) << "\n"; // Expected 1

    vector<int> arr5 = {2, 3, 5};
    cout << "BFS Test 5: " << solBFS.minimumMultiplications(arr5, 7, 7) << "\n";         
    cout << "Dijkstra Test 5: " << solDijkstra.minimumMultiplications(arr5, 7, 7) << "\n";
    cout << "Queue+Dist Test 5: " << solQueueDist.minimumMultiplications(arr5, 7, 7) << "\n"; // Expected 0

    return 0;
}
