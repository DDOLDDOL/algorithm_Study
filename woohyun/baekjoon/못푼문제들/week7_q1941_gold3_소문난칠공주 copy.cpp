#include <iostream>
#include <vector>
using namespace std;

vector< pair<int, int> > s_position_vector;

int tetra;
int penta;
int hexa;
int hepta;

int main() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            char input;
            cin >> input;

            if(input == 'S')    s_position_vector.push_back(make_pair(i, j));
        }
    }

    return 0;
}

void dfs(int count, int dasom, int ) {

}