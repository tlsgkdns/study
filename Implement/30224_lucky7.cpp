#include <iostream>
#include <unordered_map>

using namespace std;
int N, tmp = 0;
bool c = false;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> N; tmp = N;
    while (!c && tmp > 0)
    {
        if (tmp % 10 == 7)
            c = true;
        tmp /= 10;
    }

    if (!c)
    {
        if (N % 7 > 0) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    else
    {
        if (N % 7 > 0) cout << 2 << '\n';
        else cout << 3 << '\n';
    }
}

// https://www.acmicpc.net/problem/30224