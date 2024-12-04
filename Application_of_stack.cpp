#include <iostream>

 

using namespace std;

 

// Recursive function to solve Tower of Hanoi puzzle

void hanoi(int n, char source, char target, char auxiliary) {

    if (n == 1) {

        cout << "Move disk 1 from " << source << " to " << target << endl;

        return;

    }

    hanoi(n - 1, source, auxiliary, target);

    cout << "Move disk " << n << " from " << source << " to " << target << endl;

    hanoi(n - 1, auxiliary, target, source);

}

 

int main() {

    int n = 3; // Number of disks

    hanoi(n, 'A', 'C', 'B'); // A is source, C is target, B is auxiliary

    return 0;

}
