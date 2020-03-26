#include <iostream>
using namespace std;

int fun(int p1, int p2) {
    int i = 0;
    i = p1 + p2;
    return i;
}

int main() {
    int (*pf)(int p1, int p2);
    int p;
    pf = &fun;
    p = (*pf)(1, 2);

    cout << p << endl;
    return 0;
}