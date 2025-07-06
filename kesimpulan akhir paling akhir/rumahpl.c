
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
//#include "warnaBGFunction.c"


void atap(int height, char houseChar) {
    int width = 20 + (2 * (height - 1));
    for (int i = 0; i < height; i++) {

        int spaces = height - i - 1;
        int stars = 20 + (2 * i);

        //spasi
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        // atap salatiga
        for (int j = 0; j < stars; j++) {
            if (j < stars / 2) {
                printf("\033[1;33m%c\033[0m", houseChar);
            } else {
                printf("\033[1;31m%c\033[0m", houseChar);
            }
        }
        usleep(35000);
        printf("\n");
    }
}
void tembok(int height, char houseChar) {
    int width = 20 + (2 * (height - 1)); // LEBAR DINDING
    for (int i = 0; i < height; i++) {
        if (i == height - 1) {
            for (int j = 0; j < width; j++) {
                printf("\033[1;32m%c\033[0m", houseChar);
            }
        } else {
            for (int j = 0; j < width; j++) {
                printf("\033[1;37m%c\033[0m", houseChar);
            }
        }
        usleep(35000);
        printf("\n");
    }
}

void rumplamain() {
    //int printfWarna;
    tlis("SELAMAT DATANG DI PROYEK PEMBANGUNAN RUMAH"); printf(">>>>>\n\n\n\n\n");
    int tinggiAtp;
    char TheCharKWKWKW;
    printf("\t\t\t\t INPUT TINGGI ATAP RUMAH IMPIAN ANDA>>> ");
    scanf("%d", &tinggiAtp);

    printf("\t\t\t\t       MASUKAN BAHAN BANGUNAN>>> ");
    scanf(" %c", &TheCharKWKWKW); // Karakter untuk rumah
    printfBackground("\n\nTHIS IS RUMAH YOU MASBRO!\n", BG_MERAH);

    //ATAP
    atap(tinggiAtp, TheCharKWKWKW); printf("\n");
    //DINDING
    tembok(tinggiAtp, TheCharKWKWKW);



}

int main_pollaku();
void opsion();

int main_pollaku() {
    rumplamain();
    opsion();
    return 0;
}


void opsion() {
    char key;
    printfBackground("\n\n\n\nU = BELUM PUAS\nQ= MENU_UTAMA()\n", BG_MERAH);
    while (1) {
        if (kbhit()) {  //BUAT CHECK TOMBOL WHERE TOUCH
            key = getch();  //AMBIL TOMBOL
            printf("Tombol yang ditekan: %c\n", key);

            if (key == 'U' || key == 'u') {
                system("cls");
                //tlis("Mengulang program...\n");
                main_pollaku();
                return;
            }
            else if (key == 'q' || key == 'Q') {
                system("cls");
                tlis("Keluar dari program.\n");
                break;
                //exit(0);
            }
        }
    }
}

