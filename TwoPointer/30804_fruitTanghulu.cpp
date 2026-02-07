#include <iostream>
#include <algorithm>

using namespace std;

int l = 0, r = 0, cnt = 0, K[10], N, F[200001], ans = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> F[i];
    K[F[0]]++;
    ++cnt;
    while (true)
    {
        ++r;
        if (r >= N) break;
        if (K[F[r]]++ == 0)
        {
            ++cnt;
        }
        while (l < r && cnt > 2)
        {
            if (--K[F[l++]] == 0)
                --cnt;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}

// https://www.acmicpc.net/problem/30804