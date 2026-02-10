#include <iostream>
using namespace std;

int N;
long long S = 0, ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cout << N * (N - 1) * (N - 2) * (N - 3) / 24 << '\n';
}

// https://www.acmicpc.net/problem/3049