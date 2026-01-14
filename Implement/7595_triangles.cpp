#include <iostream>

using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    while (true)
    {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << "*";
            cout << '\n';
        }
    }
}

// https://www.acmicpc.net/problem/7595