#include <iostream>
using namespace std;

int T, N;
string S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N >> S;
        S.erase(S.begin() + N - 1);
        cout << S << '\n';
    }
}

// https://www.acmicpc.net/problem/2711