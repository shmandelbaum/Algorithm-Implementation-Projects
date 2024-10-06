#include <iostream>
using namespace std;

bool ok(int q[], int c) {
    for (int i = 0; i < c; i++) {
        if ((q[i] == q[c]) || abs(c-i) == abs(q[c] - q[i])) return false;
    }
    return true;
}

void print (int q[]) {
    static int count = 0;
    int i, j, k, l;
    typedef char box[5][7];
    box bb, wb, bq, wq, *board[8][8];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 7; j++) {
            wb[i][j] = ' ',
            bb[i][j] = char(219);
            wq[i][j] = ' ';
            bq[i][j] = char(219);
        }
    }
    wq[1][1] = char(219);
    wq[1][3] = char(219);
    wq[1][5] = char(219);
    wq[2][1] = char(219);
    wq[2][3] = char(219);
    wq[2][5] = char(219);
    wq[3][1] = char(219);
    wq[3][2] = char(219);
    wq[3][3] = char(219);
    wq[3][4] = char(219);
    wq[3][5] = char(219);
    bq[1][1] = ' ';
    bq[1][3] = ' ';
    bq[1][5] = ' ';
    bq[2][1] = ' ';
    bq[2][3] = ' ';
    bq[2][5] = ' ';
    bq[3][1] = ' ';
    bq[3][2] = ' ';
    bq[3][3] = ' ';
    bq[3][4] = ' ';
    bq[3][5] = ' ';
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if((i+j)%2 == 0) board[i][j] = &bb;
            else board[i][j] = &wb;
        }
    }
    for (i = 0; i < 8; i++) {
        if((q[i] + i) % 2 == 0) board[q[i]][i] = &bq;
        else board[q[i]][i] = &wq;    
    }
    cout << "Solution # " << ++count <<": \n";
    // upper border
    for (i = 0; i < (7*8); i++) {
        cout << "_";
    }
    cout << endl;
    //print board
    for (i = 0; i < 8; i++) {
        for (k = 0; k < 5; k++) {
            cout << char(179);
            for (j = 0; j < 8; j++) {
                for (l = 0; l < 7; l++) {
                    cout << (*board[i][j])[k][l];
                }
            }
            cout << char(179) << endl;
        }
    }
    // lower border
    cout << " ";
    for (i = 0; i < (7*8); i++) {
        cout << char(196);
    }
    cout << endl << endl;
}
int main () {
    int board[8]={0}, col = 0;
    board[0] = 0;
    col++;
    while (col >= 0){
        if(col == 8){
            print(board);
            col--;
            board[col]++;
        } else {
            if(board[col] == 8){
                board[col] = 0;
                col--; 
                if (col != -1 ) board[col]++;
            }
            else if(ok(board, col)){
                col++;
            } else {
                board[col]++;
            }
        }
    }
return 0;
}