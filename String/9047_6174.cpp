#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string S1, S2;


int main() {

    cin >> N;
    while (N--)
    {
        cin >> S1;
        int ans = 0;
        while (S1 != "6174")
        {
            sort(S1.begin(), S1.end());
            S2 = S1;
            sort(S2.begin(), S2.end(), greater<char>());
            int n = stoi(S2) - stoi(S1);
            S1 = to_string(n);
            while (S1.size() < 4) S1 = '0' + S1;
            ++ans;
        }
        cout << ans << '\n';
    }
}

// https://www.acmicpc.net/problem/9047