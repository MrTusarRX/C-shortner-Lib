#include <stdio.h>

#include "shorter.h"



int main(){


  int shortf[5] = {11,21,13,24,5};
  
  int lengths = length(shortf);


    sort(shortf, lengths, sizeof(int), compareInt);

    for(int i = 0; i < lengths; i++) {
        printf("%d ", shortf[i]);
    }

    return 0;
}




