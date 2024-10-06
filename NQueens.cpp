#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // Reuse the ok function from your 1D 8 queens program.
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || abs(c-i) == abs(q[c] - q[i])) return false;
    }
    return true;
}

// This function should return the number of solutions for the given board size
// (you don't need to print the solutions).
int nqueens(int n) {
   // Dynamically declare an array of size n and initialize the first element to 0.
    int* q = new int[n];
   // Reuse the code from your 1D 8 queens program to find the solutions (may need updates).
    int c = 0, solutions = 0;
    q[0] = 0;
    c++;
    while (c >= 0){
        if(c == n){
            solutions++;
            c--;
            q[c]++;
        } else {
            if(q[c] == n){
                q[c] = 0;
                c--; 
                if (c != -1 ) q[c]++;
            }
            else if(ok(q, c)){
                c++;
            } else {
                q[c]++;
            }
        }
    }
    delete[] q;
   // Delete the array.
   return solutions;
   // Return the number of solutions.
}

int main() {
   int n = 8;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
