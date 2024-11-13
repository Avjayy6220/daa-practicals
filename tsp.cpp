#include <iostream>
#include <limits.h>
using namespace std;

#define N 4  // Number of cities

// Function to calculate the lower bound for the current path
// cost - current cost so far
// adj - adjacency matrix storing distances between cities
// vis - visited array to mark cities that have already been visited
// curr - current city we are exploring from
int calcBound(int cost, int adj[N][N], bool vis[N], int curr) {
    int bound = cost;  // Start bound with the current cost
    int minCost = INT_MAX;  // To find the minimum edge cost to an unvisited city

    // Find the minimum cost edge from the current city to any unvisited city
    for (int i = 0; i < N; i++) {
        if (!vis[i] && adj[curr][i] < minCost) {
            minCost = adj[curr][i];
        }
    }

    // If there is no unvisited city, set minCost to 0
    if (minCost == INT_MAX) minCost = 0;  
    return bound + minCost;  // Return the calculated bound
}

// Recursive function to explore all possible paths
// lvl - current level in the path (starting from 0)
// curr - current city we are at
// adj - adjacency matrix storing distances between cities
// path - array to store the current path
// vis - visited array to track visited cities
// cost - cumulative cost of the current path
// minCost - minimum cost of any complete path found so far
// best - array to store the best (minimum cost) path
void explore(int lvl, int curr, int adj[N][N], int path[N], bool vis[N], int &cost, int &minCost, int best[N]);

// TSP function that sets up initial values and starts the recursive exploration
// adj - adjacency matrix storing distances between cities
// best - array to store the best path
// minCost - minimum cost of any complete path found
void tspBnB(int adj[N][N], int best[N], int &minCost) {
    int path[N];  // Array to store the current path
    bool vis[N] = {false};  // Visited array, initially all cities are unvisited
    int cost = 0;  // Initial cost is 0

    path[0] = 0;  // Start the path from the first city (index 0)
    vis[0] = true;  // Mark the first city as visited

    // Start recursive exploration
    explore(0, 0, adj, path, vis, cost, minCost, best);
}

// Recursive function to explore paths and find the minimum cost path
void explore(int lvl, int curr, int adj[N][N], int path[N], bool vis[N], int &cost, int &minCost, int best[N]) {
    // Base case: if we reached the last city, complete the path by returning to the start
    if (lvl == N - 1) {
        int totalCost = cost + adj[curr][0];  // Add cost to return to the starting city
        // If this path has a lower cost, update minCost and store the best path
        if (totalCost < minCost) {
            minCost = totalCost;
            for (int i = 0; i < N; i++) {
                best[i] = path[i];
            }
        }
        return;
    }

    // Explore each possible next city
    for (int next = 0; next < N; next++) {
        // Only consider unvisited cities
        if (!vis[next]) {
            int newCost = cost + adj[curr][next];  // Calculate new cost if we visit next
            int bound = calcBound(newCost, adj, vis, next);  // Calculate bound with the new cost

            // Only proceed if this bound is less than the current minimum cost path
            if (bound < minCost) {
                vis[next] = true;  // Mark next city as visited
                path[lvl + 1] = next;  // Add next city to the path
                cost = newCost;  // Update the current cost

                // Recurse to explore the next level
                explore(lvl + 1, next, adj, path, vis, cost, minCost, best);

                // Backtrack: unmark next city as visited and restore cost
                vis[next] = false;
                cost -= adj[curr][next];
            }
        }
    }
}

int main() {
    int adj[N][N];  // Adjacency matrix to store distances between cities
    cout << "Enter the adjacency matrix (" << N << "x" << N << "):" << endl;

    // Read the adjacency matrix from user input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> adj[i][j];
        }
    }

    int best[N];  // Array to store the best path found
    int minCost = INT_MAX;  // Initialize minimum cost to maximum integer value

    // Call the TSP function to find the best path and minimum cost
    tspBnB(adj, best, minCost);

    // Output the minimum cost and the best path
    cout << "Minimum cost: " << minCost << endl;
    cout << "Best path: ";
    for (int i = 0; i < N; i++) {
        cout << best[i] << " -> ";
    }
    cout << "0" << endl;  // Return to the starting city

    return 0;
}