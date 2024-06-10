#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int test_case_count;
vector<int> answers;

int optimal(vector<int> price_list);

int main() {
    cin >> test_case_count;

    for(int i=0; i<test_case_count; i++) {
        vector<int> price_list;
        int days;
        
        cin >> days;

        for(int j=0; j<days; j++) {
            int input;
            cin >> input;

            price_list.push_back(input);
        }

        answers.push_back(optimal(price_list));
    }

    for(int i=0; i<answers.size(); i++) cout << answers[i] << endl;

    return 0;
}

int optimal(vector<int> price_list) {
    int sum = 0;
    int max_index = 0;
    int previous_index = 0;

    while(max_index < price_list.size()) {
        previous_index = max_index;
        max_index = max_element(price_list.begin() + max_index, price_list.end()) - price_list.begin();
        
        int max_value = price_list[max_index];

        for(int i = previous_index; i < max_index; i++) {
            // cout << "--- " << max_value << "-" << price_list[i] << " ---" << endl;

            sum += max_value - price_list[i];
        }

        max_index++;
    }

    return sum;
}