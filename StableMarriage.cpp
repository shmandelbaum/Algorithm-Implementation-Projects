#include <iostream>
using namespace std;

bool ok (int arr[], int c) {
    int mp[3][3] = {{0,2,1},
                    {0,2,1},
                    {1,2,0}};
    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};
    for (int i = 0; i < c; i++) {
        if (arr[i] == arr[c]) return false;
    }
    for (int i = 0; i < c; i++) {
        if((mp[i][arr[i]] > mp[i][arr[c]]) && (wp[arr[c]][c] > wp[arr[c]][i])) return false; // if current man prefers new woman and new woman prefers current man
        if((mp[c][arr[c]] > mp[c][arr[i]]) && (wp[arr[i]][i] > wp[arr[i]][c])) return false; // if new man prefers current woman and current woman prefers new man
    }
    return true;
}
void print (int arr[]) {
    static int count = 1;
    cout << "Solution #" << count << ":\nMan \tWoman\n" ; 
    for (int i = 0; i < 3; i++) {
        cout << i << "\t" << arr[i] << endl;
    }
    count++;
}

int main () {
    int q[3] = {0}, c = 0;
    q[0] = 0;
    c++; //move to next man
    while (c >= 0) { // while you did not go before men
    if (c == 3) {
        print(q);
        c--;
        q[c]++;
    } else {
        if (q[c] > 2) {
            q[c] = 0;
            c--;
            if (c != -1) q[c]++;
        }
        else if (ok(q,c)) {
            c++;
        } else {
            q[c]++;
        }
        }
    }
    return 0;
}