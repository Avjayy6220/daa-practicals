#include<iostream>
using namespace std;

void knapsack(float p[], float w[], int n, int m )
{
    float pw[20];
    for(int i=0; i<n;i++){
        pw[i]=p[i]/w[i];
    }

    for(int i=0;i<n;i++){
         int maxindex =i;
        for(int j=i+1;j<n;j++){
            if(pw[j]>pw[maxindex]){
                maxindex=j;
            }
        }
        float temp;
        temp = pw[i];
        pw[i] = pw[maxindex];
        pw[maxindex] = temp;

        temp = p[i];
        p[i] = p[maxindex];
        p[maxindex] = temp;

        temp = w[i];
        w[i] = w[maxindex];
        w[maxindex] = temp;

        }

        float total = 0;
    int u = m;
    cout << "Step\tPi\tWi\tU\tX\tpixi\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        int step = i + 1;
        float pixi;
        float x;
        
        if (w[i] <= u) {
            x = 1;
        } else {
            x = (float)u / w[i];
        }

        pixi = p[i] * x; 
        total += pixi;

        if (w[i] > u) {
            u = 0; 
        } else {
            u = u - w[i];
        }

        cout << step << "\t" << p[i] << "\t" << w[i] << "\t" << u << "\t" << x << "\t" << pixi << endl;

        if (u == 0) {
            break;
        }
    }
    cout << "Maximum profit: " << total << endl;
}

int main(){
    int n, m;
    float p[20], w[20];
    cout << "Enter the maximum capacity: ";
    cin >> m;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cout << "Enter the profit for object " << i + 1 << ": ";
        cin >> p[i];
        cout << "Enter the weight for object " << i + 1 << ": ";
        cin >> w[i];
    }
    
    knapsack(p, w, n, m);
}
