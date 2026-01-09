#include <iostream>


using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    while (true)
    {
        cin >> N;
        if (N <= 0) break;
        int ans = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                ans += i * j;
        cout << ans << '\n';
    }
}

// https://www.acmicpc.net/problem/35097