#include <iostream>
#include <algorithm>
using namespace std;

int width, height;
int board[1001][1001] = { 0, };
int max_value = 0;

void search_max_square_width();
int min(int a, int b, int c);

int main() {
	cin >> height >> width;

    for(int i=0; i<height; i++) {
        string input;
        cin >> input;

        for(int j=0; j<width; j++)  board[i+1][j+1] = input[j] - '0';
    }

    search_max_square_width();

    // for(int i=1; i<=height; i++) {
    //     for(int j=1; j<=width; j++)  cout << board[i][j] << " ";
    //     cout << endl;
    // }
	
	cout << max_value * max_value << endl;

	return 0;
}

void search_max_square_width() {
	for (int i = 2; i <= height; i++) {
		for (int j = 2; j <= width; j++) {
			if (board[i][j] == 1)
				board[i][j] = min(board[i][j - 1], board[i - 1][j - 1], board[i - 1][j]) + 1;
			max_value = max(board[i][j], max_value);
		}
	}
}

int min(int a, int b, int c) {
	int temp = min(a, b);
	return min(temp, c);
}


// int width, height;
// int **area;
// int maxLength;

// void search();
// void drawSquare(int y, int x);

// int main() {
//     cin >> height >> width;
//     area = new int*[height];
    
//     maxLength = 0;

    // for(int i=0; i<height; i++) {
    //     string input;
    //     cin >> input;

    //     area[i] = new int[width];
    //     for(int j=0; j<width; j++)  area[i][j] = input[j] - '0';
    // }

//     search();

//     cout << maxLength * maxLength << endl;

//     return 0;
// }

// void search() {
//     for(int i=0; i<height; i++) {
//         for(int j=0; j<width; j++) {
//             if(area[i][j] == 1) drawSquare(i, j);
//         }
//     }
// }

// void drawSquare(int y, int x) {
//     int length = maxLength;

//     while(1) {
//         for(int i=0; i<=length; i++) {
//             for(int j=0; j<=length; j++) {
//                 if(y+i >= height || x+j >= width)   return;
//                 if(area[y+i][x+j] == 0) return;
//             }
//         }

//         length++;
//         maxLength = maxLength < length ? length : maxLength;
//     }
// }
