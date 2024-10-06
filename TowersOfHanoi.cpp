#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3]; //three towers A,B,C represented as an array of 3 vectors
    int n, candidate, to, from, near, far, move=0; //move counts the move number

    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;

    //initialize the 3 towers
    for (int i = n+1; i >= 1; i--) t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    //initialize towers and candidate
    if (n%2 == 0) {
        near = 2, far = 1;
    }
    else {
        near = 1, far = 2;
    }
    from = 0; to = near; candidate = 1;

    while(t[1].size() < n+1) {//there are still rings to transfer to tower B = t[1]
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << endl;
        t[to].push_back(t[from].back());
        t[from].pop_back();
        if(t[(to+1)%3].back() < t[(to+2)%3].back()) from = (to + 1)%3;
        else from = (to + 2)%3;
        candidate = t[from].back();
        if(t[(from + near)%3].back() > candidate) to = (from + near)%3;
        else to = (from + far)%3;
    }
    return 0;
}