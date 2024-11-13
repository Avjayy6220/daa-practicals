//0/1 knapsack
#include<iostream>
#include<algorithm>
using namespace std;

int knapsack(int n, int w[], int p[], int m) {
    int dp[n+1][m+1];

    // Initialize the dp array with 0
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    // Populate the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (w[i-1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i-1]] + p[i-1]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Print the tabular format of the DP table
    cout << "\nTabular Format of 0/1 Knapsack Problem:\n";
    cout << "   |";
    for (int j = 0; j <= m; j++)
        cout<< "\t"  << j;
    cout << endl;

    cout << "---|-------------------------------------------------------" << "\t";
    cout << endl;

    for (int i = 0; i <= n; i++) {
        cout << i << "  |  \t";
        for (int j = 0; j <= m; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }

    // Find the selected items by backtracking
    int maxProfit = dp[n][m];
    int weightRemaining = m;
    cout << "\nMaximum Profit is: " << maxProfit << endl;

    cout << "Included items (Indexing starts from 1):\n";
    bool included[n] = {false}; // Array to mark which items are included
    for (int i = n; i > 0 && weightRemaining > 0; i--) {
        if (dp[i][weightRemaining] != dp[i-1][weightRemaining]) {
            included[i-1] = true;
            weightRemaining -= w[i-1];
        }
    }

    // Print the included items
    for (int i = 0; i < n; i++) {
        if (included[i]) {
            cout << "Item " << i+1 << " (Profit: " << p[i] << ", Weight: " << w[i] << ")\n";
        }
    }

    return maxProfit;
}

int main() {
    int P[10], W[10], n, m;
    
    cout << "Enter No. of items: ";
    cin >> n;
    
    cout << "Enter the capacity of knapsack: ";
    cin >> m;

    for (int i = 0; i < n; i++) {
        cout << "Enter the Profit and Weight of Object " << i + 1 << ": ";
        cin >> P[i] >> W[i];
    }

    cout << "\nThe maximum profit is: " << knapsack(n, W, P, m);

    return 0;
}
