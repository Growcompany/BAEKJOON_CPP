#include <iostream>
#include <cmath>
using namespace std;

int visitOrder(int size, int r, int c) {
    if (size == 1) return 0;

    int half = size / 2;
    int quadrantSize = half * half;

    if (r < half && c < half) {
        // 1st quadrant (top-left)
        return visitOrder(half, r, c);
    }
    else if (r < half && c >= half) {
        // 2nd quadrant (top-right)
        return quadrantSize + visitOrder(half, r, c - half);
    }
    else if (r >= half && c < half) {
        // 3rd quadrant (bottom-left)
        return quadrantSize * 2 + visitOrder(half, r - half, c);
    }
    else {
        // 4th quadrant (bottom-right)
        return quadrantSize * 3 + visitOrder(half, r - half, c - half);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;

    int size = 1 << N;
    cout << visitOrder(size, r, c) << '\n';

    return 0;
}
