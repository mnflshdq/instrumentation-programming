/*
 * =====================================================================================
 *
 *       Filename:  gerbang-logika-uts.c
 *
 *    Description:  Sistem instrumen dengan 2 input A dan B dengan keluaran Y
 *
 *        Version:  1.0
 *        Created:  10/27/2018 06:14:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
char line[100];

int main ()
{
    int A, B, Y;
    
    printf("Masukkan nilai A (0/1)\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &A);
    
    printf("Masukkan nilai B (0/1)\n");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &B);

    printf("%s", line);
    
    Y = A || B;
    printf("%d or %d adalah %d", A, B, Y);
    
    getchar();
    return(0);
}

