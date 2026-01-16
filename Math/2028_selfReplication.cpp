#include <iostream>
#include <unordered_map>

using namespace std;

int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N;
        int n = N * N;
        n -= N;
        int d = 1;
        while (d <= N)
            d *= 10;
        if (n == 0 || n % d == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

// https://www.acmicpc.net/problem/2028