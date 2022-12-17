//
//  main.c
//  Esercizio-4.12
//
//  Created by Maurizio Minieri on 20/12/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int N=5,n=0;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<i+1;j++)
            printf("%d ",++n);
        printf("\n");
    }
    
    printf("\n\n");
    return 0;
}
