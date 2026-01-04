#include <iostream>

using namespace std;
int N;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cout << i * 2 + 1 << " ";
    cout << '\n';
    return 0;
}

// https://www.acmicpc.net/problem/31229