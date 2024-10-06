#include <iostream>
using namespace std;

void print (int arr[]) {
    static int count = 0;
    count ++;
    int board[8][8] = {0};
    for (int i = 0; i < 8; i++) {
        board[arr[i]][i] = 1;
    }
    cout << "Solution # " << count << ": \n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int q[8], c = 0;
    q[0] = 0;
    nextCol:
    c++;
    if (c == 8) goto print;
    q[c] = -1;
    nextRow:
    q[c]++;
    if (q[c] == 8) goto backtrack;
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || ((c-i) == abs(q[c] - q[i]))) goto nextRow;
    }
    goto nextCol;
    backtrack:
    c--;
    if (c == -1) {
        return 0;
    } 
    else goto nextRow;
    print:
    print(q);
    goto backtrack;
    return 0;
}