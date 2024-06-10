#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> numbers;
stack<int> nges;

vector<int> sorted;
int cnt = 0;

void printNge();
int nge(int number);

int main() {
    int numberCount;
    cin >> numberCount;

    for(int i=0; i<numberCount; i++) {
        int input;
        cin >> input;

        numbers.push(input);
    }

    printNge();

    return 0;
}

void printNge() {
    int numberLength = numbers.size();
    
    for(int i=0; i<numberLength; i++) {
        int current = numbers.top();
        numbers.pop();

        nges.push(nge(current));
        cout << cnt << endl;
    }

    // for(int i=0; i<nges.size(); i++) {
    //     cout << sorted[i] << ' ';
    // }
    // cout << endl;

    int ngeSize = nges.size();

    for(int i=0; i<ngeSize; i++) {
        int currentNge = nges.top();
        nges.pop();

        cout << currentNge << ' ';
    }
    cout << endl;
}

int nge(int number) {
    int start = 0;
    int end = sorted.size() - 1;

    int index = end/2;

    if(sorted.size() == 0) {
        sorted.push_back(number);
        return -1;
    }

    while(1) {
        cnt++;
    // cout << "---- " << count << " ----- " << number << " ----- " << '[' << start << ", " << end << ']' << index << " -----" << endl;

        int focused = sorted[index];

        if(number == focused) {
            if(index == sorted.size())  return -1;
            return sorted[index+1];
        }

        if(number < focused) {
            if(index == 0) {
                sorted.insert(sorted.begin(), number);
                return sorted[1];
            }

            if(sorted[index-1] == number)   return focused;

            if(sorted[index-1] < number) {
                sorted.insert(sorted.begin() + index, number);
                return focused;
            }

            end = index;
            index = (start + end) / 2;
        }

        if(number > focused) {
            if(index == sorted.size()-1) {
                sorted.push_back(number);
                return -1;
            }

            if(sorted[index+1] == number) {
                if(index+1 == sorted.size()-1)  return -1;
                return sorted[index+1];
            }

            if(sorted[index+1] > number) {
                sorted.insert(sorted.begin()+index+1, number);
                return sorted[index+2];
            }

            start = index;
            index = (start + end) / 2;
        }
    }
}