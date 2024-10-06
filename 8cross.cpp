#include <iostream>
using namespace std;

bool ok(int arr[], int c) {
    int a[8][5] = {  // helper array
        {-1}, 
        {0,-1},
        {0,-1},
        {0,1,2,-1},
        {0,1,3,-1},
        {1,4,-1},
        {2,3,4,-1},
        {3,4,5,6,-1}
    };
    for (int i = 0; i < c; i++) {  //making sure that you are only putting each number once
        if (arr[i] == arr[c]) return false;
    }
    for (int i = 0; a[c][i] != -1; i++) {   //making sure no to consecutive numbers are adjacent using helper array
        if (abs (arr[c] - arr[a[c][i]]) == 1) return false;
    }
    return true;
}
void print (int arr[]) {
    static int count = 1;
    cout << "Solution #" << count << ": \n";
    cout << " " << arr[0] << arr[1] << " \n" << arr[2] << arr[3] << arr[4] << arr[5] << endl << " " << arr[6] << arr[7] << " \n";
    count ++;
}
int main () {
    int q[8] = {1}, c = 0;
    q[0] = 1; 
    c++; //move to next index
    while (c >= 0) {  // while you did not backtrack past index 0
        if (c == 8) {  // if all indexes are filled
            print(q);
            c--;  //backtrack
            q[c]++;
        } else {
            if (q[c] > 8) { // if number in any given index exceeds 8
                q[c] = 1;  //reset index
                c--; //backtrack
                if (c != -1) q[c]++;
            }
            else if (ok(q,c)) {  //check to see if number in index is okay
                c++; // if so, move to next index
            } else {
                q[c]++; // if not, try the next number
            }
        }
    }
    return 0;
}