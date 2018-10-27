/*
 * =====================================================================================
 *
 *       Filename:  tumbukan-uts.c
 *
 *    Description:  Menghitung berbagai jenis tumbukan antara dua benda
 *
 *        Version:  1.0
 *        Created:  10/26/2018 08:10:19 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Muhammad Naufal Shidqi (), mhmmdnflshdq@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
char line[100];

/* Fungsi untuk menghitung V1akhir dan V2akhir pada lenting sempurna */
void lenting_sempurna(float m1, float m2, float V1awal, float V2awal)
{
    float V1akhir, V2akhir;
    V2akhir = (m1 * (2 * V1awal - V2awal) + m2 * V2awal) / (m1 + m2);
    V1akhir = V2awal - V1awal + V2akhir;

    printf("Arah dan kecepatan benda pertama setelah tumbukan adalah %.3f m/s\n", V1akhir);
    printf("Arah dan kecepatan benda kedua setelah tumbukan adalah %.3f m/s\n", V2akhir);
    return;
}

/* Fungsi untuk menghitung lenting sebagian */
void lenting_sebagian(float e, float m1, float m2, float V1awal, float V2awal)
{
    float V2akhir, V1akhir;
    V2akhir = (m1 * (V1awal - e * (V2awal - V1awal)) + m2 * V2awal) / (m1 + m2);
    V1akhir = e * (V2awal - V1awal) + V2akhir;
    
    printf("Arah dan kecepatan benda pertama setelah tumbukan adalah %.3f m/s\n", V1akhir);
    printf("Arah dan kecepatan benda kedua setelah tumbukan adalah %.3f m/s\n", V2akhir);
    return;
}

/* Fungsi untuk menghitung tidak lenting sama sekali */
void tidak_lenting(float m1, float m2, float V1awal, float V2awal)
{
    float Vakhir;
    Vakhir = (m1 * V1awal + m2 * V2awal) / (m1 + m2);

    printf("Arah dan kecepatan benda pertama dan kedua setelah tumbukan adalah %.2f\n", Vakhir);
    return;
}

int main ()
{
    /* Variabel bagian dari rumus tumbukan */
    float m1, m2, V1awal, V2awal, e;
    /* Variabel untuk pilihan tumbukan */
    int o;
    /* Variabel untuk pengulangan */
    char r;

    r = 'y';
    while(r == 'y' || r == 'Y')
    {

        printf("Masukkan massa (kg) dan kecepatan awal benda pertama (m/s) dipisah dengan spasi: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f %f\n", &m1, &V1awal);

        printf("Masukkan massa (kg) dan kecepatan awal benda kedua (m/s) dipisah dengan spasi: ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%f %f\n", &m2, &V2awal);

        printf("\n"); 

        printf("1. Tumbukan Lenting Sempurna\n");
        printf("2. Tumbukan Lenting Sebagian\n");
        printf("3. Tumbukan Tidak Lenting Sama Sekali\n");
        printf("Pilih tumbukan yang ingin anda hitung: \n");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d\n", &o);
        
        if(o == 1)
        {
            printf("\n");
            lenting_sempurna(m1, m2, V1awal, V2awal);
            printf("\n");
        }
        if(o == 2)
        {
            printf("\n");
            printf("Masukkan nilai koefisen restitusi (e): ");
            fgets(line, sizeof(line), stdin);
            sscanf(line, "%f", &e);

            printf("\n");
            lenting_sebagian(e, m1, m2, V1awal, V2awal);
            printf("\n");
        }
        if(o == 3)
        {
            printf("\n");
            tidak_lenting(m1, m2, V1awal, V2awal);
            printf("\n");
        }

        printf("Apakah anda ingin mengulang program? (y/n)\n");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%c", &r);
    }

    return(0);

}

