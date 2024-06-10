#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string *pokemons;
    int count;
    int question;

    cin >> count;
    pokemons = new string[count];

    for(int i=0; i<count; i++) {
        string pokemon;
        cin >> pokemon;

        pokemons[i] = pokemon;
    }

    for(int i=0; i<question; i++) {
        string input;
        cin >> input;

        int index = pokemons->find(input);

        if(index == -1) {
            index = stoi(input);
            cout << pokemons[index] << endl;
        }
    
        cout << index << endl;
    }

    return 0;
}