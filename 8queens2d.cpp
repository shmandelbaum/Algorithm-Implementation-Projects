#include <iostream>
using namespace std;
int main () {
    int b[8][8] = {};
    int r = 0, c = 0, count = 0;
    b[0][0] = 1;
    increment_col: 
    c++;
    if (c == 8) goto print;
    r = -1;
    increment_row: 
    r++;
    if (r == 8) goto backtrack;
    for (int i = 0; i < c; i++) {
        if (b[r][i] == 1) goto increment_row;
    }
    for (int i = 1; ((r-i) >= 0 && (c-i) >= 0); i++) {
        if (b[r-i][c-i] == 1) goto increment_row;
    }
    for (int i = 1; ((r+i) < 8 && (c-i) >= 0); i++) {
        if (b[r+i][c-i] == 1) goto increment_row;
    }
    b[r][c] = 1;
    goto increment_col;
    backtrack: 
    c--;
    if (c == -1) {
        cout << "There are " << count << " solutions \n";
        return 0;
    }
    r = 0;
    while (b[r][c] != 1) {
        r++;
    }
    b[r][c] = 0;
    goto increment_row;
    print: 
    count ++;
    cout << "Solution #" << count << ": \n";
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            cout << b[row][col] << " ";
        }
        cout << endl;
    }
    goto backtrack;
    return 0;
}