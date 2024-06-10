#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int stairCount;
vector<int> stairs;
int *sumArray;
int maxSum;

void maxStairs(int index);

int main() {
    cin >> stairCount;
    sumArray = new int[stairCount];

    for(int i=0; i<stairCount; i++) {
        int stair;
        cin >> stair;

        stairs.push_back(stair);
    }

    sumArray[0] = stairs[0];
    sumArray[1] = stairs[0] + stairs[1];
    sumArray[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for(int i=3; i<stairCount; i++) {
        sumArray[i] = max(sumArray[i-2] + stairs[i], sumArray[i-3] + stairs[i-1] + stairs[i]);
    }

    cout << sumArray[stairCount-1] << endl;

    return 0;
}