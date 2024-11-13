//graph colouring
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10;
int G[MAX][MAX];
int x[MAX];
int m, n;

// Function to find the next valid color for vertex k
void NextValue(int k) {
    do {
        x[k] = (x[k] + 1) % (m + 1);  // Increment the color value

        if (x[k] == 0) {
            return;  // No valid color left, backtrack
        }

        int j;
        for (j = 0; j < n; j++) {
            if (G[k][j] != 0 && x[k] == x[j]) {  // Adjacent vertices with the same color
                break;
            }
        }

        if (j == n) {  // Valid color found for vertex k
            return;
        }

    } while (true);
}

// Function to recursively try coloring the graph
void Coloring(int k) {
    do {
        NextValue(k);

        if (x[k] == 0) {
            return;  // Backtrack if no valid color found
        }

        if (k == n - 1) {  // All vertices are colored
            // Print a valid coloring solution
            cout << "Coloring Solution: " << endl;
            for (int i = 0; i < n; i++) {
                cout << "Vertex " << i + 1 << ": Color " << x[i] << endl;
            }
            cout << endl;
        } else {
            Coloring(k + 1);  // Move to the next vertex
        }

    } while (true);
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of colors: ";
    cin >> m;

    // Initialize the adjacency matrix
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    // Initialize the color array
    for (int i = 0; i < n; i++) {
        x[i] = 0;
    }

    // Start coloring from the first vertex
    Coloring(0);

    return 0;
}
