#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int mid = n;

    // Upper half + middle
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 2 * n - 1; j++) {

            if (j == mid - i || j == mid + i)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    // Lower half
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j <= 2 * n - 1; j++) {

            if (j == mid - i || j == mid + i)
                cout << "*";
            else
                cout << " ";
        }

        cout << endl;
    }

    return 0;
}