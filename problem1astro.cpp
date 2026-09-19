#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int* next_ = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        next_[i] = (i == N) ? 1 : i + 1;
    }

    int current   = 1;
    int prev       = N;
    int remaining  = N;

    cout << "Elimination order: ";

    while (remaining > 1) {
        for (int step = 1; step < K; step++) {
            prev    = current;
            current = next_[current];
        }

        int eliminated = current;
        cout << eliminated;
        remaining--;
        if (remaining > 1) cout << " ";

        next_[prev] = next_[eliminated];
        current = next_[prev];

        if (eliminated % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }
        if (K < 2) K = 2;
    }

    cout << "\nLast surviving astronaut: " << current << endl;

    delete[] next_;
    return 0;
}