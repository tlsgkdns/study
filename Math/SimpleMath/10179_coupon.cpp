#include <iostream>


using namespace std;
int N;
double P;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    cout.precision(2); cout << fixed;
    while (N--)
    {
        cin >> P;
        P *= 0.8;
        cout << "$" << P << '\n';
    }
}

// https://www.acmicpc.net/problem/10179