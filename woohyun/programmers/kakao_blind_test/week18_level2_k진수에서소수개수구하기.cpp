#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) {
    int answer = -1;
    
    int copy = n;
    int digits = 0;
    
    while(copy >= 1) {
        copy /= k;
        digits++;
    }

    for(int i=digits; i>0; i++) {
        
    }
    
    return answer;
}