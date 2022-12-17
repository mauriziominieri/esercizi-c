//
//  main.c
//  Esercizio-4.11
//
//  Created by Maurizio Minieri on 20/12/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int N = 5;
    char c = '*';
    
    printf("CASO 1\n\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++)
            putchar(c);
        printf("\n");
    }
    
    printf("\nCASO 2\n\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i==0 || i==N-1)
                putchar(c);
            else if(j==0 || j==N-1)
                putchar(c);
            else
                putchar(' ');
        }
        printf("\n");
    }
    
    printf("\nCASO 3\n\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<i+1;j++) {
            putchar(c);
        }
        printf("\n");
    }
    
    printf("\nCASO 4\n\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(i>=j)
                putchar(c);
            else
                putchar('+');
        }
        printf("\n");
    }
    
    printf("\n\n");
    return 0;
}
