#include <iostream>
#include <cstring>  
using namespace std;

const int MAX = 100;
int level[MAX], profit[MAX], weight[MAX], bound[MAX]; 
int Count = 0; 
int n, m;  
int w[20];  
int p[20];  

// Function to calculate bound for the node
int C_bound(int ttl_profit, int ttl_weight, int k) {
    if (ttl_weight >= m)  
        return 0;

    int b = ttl_profit;  
    int c = ttl_weight;  

   
    for (int i = k + 1; i <= n; i++) {
        if (c + w[i] <= m) {  
            c += w[i];
            b += p[i];
        } else {  
            b += (m - c) * (p[i] / w[i]);
            break;
        }
    }
    return b;
}


int knapsack() {
    Count = 0;  
    int maxProfit = 0;  

    level[Count] = 0;
    profit[Count] = 0;
    weight[Count] = 0;
    bound[Count] = C_bound(0, 0, 0);
    Count++;

    
    for (int i = 0; i < Count; i++) {
       
        if (bound[i] > maxProfit && level[i] < n) {
           
            int vLevel = level[i] + 1;
            int vWeight = weight[i] + w[vLevel];
            int vProfit = profit[i] + p[vLevel];

            if (vWeight <= m && vProfit > maxProfit) {
                maxProfit = vProfit;  
            }

            int vBound = C_bound(vProfit, vWeight, vLevel);  
            if (vBound > maxProfit && Count < MAX) {
                level[Count] = vLevel;
                weight[Count] = vWeight;
                profit[Count] = vProfit;
                bound[Count] = vBound;
                Count++;  
            }

        
            vWeight = weight[i];
            vProfit = profit[i];
            vBound = C_bound(vProfit, vWeight, vLevel); 

            if (vBound > maxProfit && Count < MAX) {
                level[Count] = vLevel;
                weight[Count] = vWeight;
                profit[Count] = vProfit;
                bound[Count] = vBound;
                Count++;  
            }
        }
    }

    return maxProfit;  
}

int main() {
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the capacity of the knapsack: ";
    cin >> m;

    cout << "Enter the weights and profits of the items:\n";
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> p[i];
    }

    int maxProfit = knapsack();  
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
