//N-queen
#include<iostream>
using namespace std;

int x[20]; 
int n;     
int count = 0; 


bool place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return false;
        }
    }
    return true;
}


void nqueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i; 
            if (k == n) {
                
                count++; 
                for (int j = 1; j <= n; j++) {
                    cout << x[j] << " ";
                }
                cout << endl;
            } else {
               
                nqueen(k + 1, n);
            }
        }
    }
}

int main() {
    cout << "Enter the number of queens: ";
    cin >> n;
    nqueen(1, n); 

    cout << "Total number of solutions: " <<count << endl;
}
