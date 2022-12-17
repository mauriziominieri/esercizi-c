//
//  main.c
//  Esame_21-02-26
//
//  Created by Maurizio Minieri on 02/04/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct record {
    int n;
    int *d;
} digit;

void Det2Dig(int val, digit *dval) {
    int x = val,n = 0, k = 0;
    while(x > 0) {
        x /= 2;
        n++;
    }
    x = val;
    dval->n = n;
    dval->d = malloc(dval->n * sizeof(int));

    while(x > 0) {
        dval->d[k++] = x % 2;
        x /= 2;
    }
    
    printf("La rappresentazione binaria di %d è: ",val);
    for(int i=dval->n-1;i>=0;i--)
        printf("%d ",dval->d[i]);
}

int main(int argc, const char * argv[]) {
    digit* dval = malloc(sizeof(struct record));
    Det2Dig(57,dval);
    printf("\n\n");
    return 0;
}
