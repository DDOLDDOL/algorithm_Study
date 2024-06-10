#include <iostream>
using namespace std;

int building[102][102][102] = { 0, };
int num, leftNum, rightNum;

void dp();

int main() {
    cin >> num >> leftNum >> rightNum;
    building[1][1][1] = 1;

    dp();

    cout << building[num][leftNum][rightNum] << endl;

    return 0;
}

void dp() {
    for(int n=2; n<=num; n++) {
        for(int l=1; l<=n; l++) {
            for(int r=1; r<=n-l+1; r++) {
                building[n][l][r] = (building[n-1][l-1][r] + building[n-1][l][r-1]) % 1000000007;
            }
        }
    }
}