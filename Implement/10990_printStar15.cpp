#include <iostream>
using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1 - i; j > 0; j--)
            cout << " ";
        cout << "*";
        for (int j = 0; j < 2 * i - 1; j++)
            cout << " ";
        if (i > 0) cout << "*";
        cout << '\n';
    }
}

// https://www.acmicpc.net/problem/10990