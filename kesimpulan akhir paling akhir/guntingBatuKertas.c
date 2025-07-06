#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main_bbg() {
    int pilihan_pengguna, pilihan_komputer, hasil;

    // Inisialisasi random pembuat nomor
    srand(time(NULL));

    printf("Permainan Kertas Batu Gunting\n");
    printf("\n1. BATU\n");
    printf("2. KERTAS\n");
    printf("3. GUNTING\n");
    printf("\nMasukkan Pilihan: ");
    scanf("%d", &pilihan_pengguna);

    // Validasi input pengguna
    if (pilihan_pengguna < 1 || pilihan_pengguna > 3) {
        printf("Pilihan tidak valid! Harap pilih 1, 2, atau 3.\n");
        return 1;
    }

    pilihan_komputer = rand() % 3 + 1;

    printf("Pilihan Anda: ");
    switch(pilihan_pengguna) {
        case 1:
            printf("BATU\n");
            break;
        case 2:
            printf("KERTAS\n");
            break;
        case 3:
            printf("GUNTING\n");
            break;
    }
     printf("Pilihan Komputer: ");
     switch(pilihan_komputer) {
        case 1:
            printf("BATU\n");
            break;
        case 2:
            printf("KERTAS\n");
            break;
        case 3:
            printf("GUNTING\n");
            break;
    }


    if (pilihan_pengguna == pilihan_komputer) {
        hasil = 0; // Seri
    } else if ((pilihan_pengguna == 1 && pilihan_komputer == 3) ||
               (pilihan_pengguna == 2 && pilihan_komputer == 1) ||
               (pilihan_pengguna == 3 && pilihan_komputer == 2)) {
        hasil = 1;
    } else {
        hasil = -1;
    }


    if (hasil == 0) {
        printf("\nHasil: Seri\n");
    } else if (hasil == 1) {
        printf("\nHasil: Anda menang!\n");
    } else {
        printf("\nHasil: Anda kalah!\n");
    }


    char key;
    printfBackground("\n\n\n\nU = BELUM PUAS\nQ= MENU_UTAMA()\n", BG_MERAH);
    while (1) {
        if (kbhit()) {  //BUAT CHECK TOMBOL WHERE TOUCH
            key = getch();  //AMBIL TOMBOL
            printf("Tombol yang ditekan: %c\n", key);

            if (key == 'U' || key == 'u') {
                system("cls");
                //tlis("Mengulang program...\n");
                main_bbg();
                return 0;
            }
            else if (key == 'q' || key == 'Q') {
                system("cls");
                tlis("Keluar dari program.\n");
                break;
                //exit(0);
            }
        }
    }


    return 0;
}
