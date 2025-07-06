#include <stdio.h>
#include <unistd.h>


#define RED "\033[41m"
#define WHITE "\033[47m"
#define RESET "\033[0m"

void BenderaIndonesia(int tinggi) {
    int tinggiPerBagian = tinggi;
    int lebar = tinggi*4;

    for (int i = 0; i < tinggi*2; i++) {
        if (i < tinggiPerBagian) {
            printf(RED);
        } else {
            printf(WHITE);
        };

        for (int j = 0; j < lebar; j++) {
            printf(" ");
            usleep(10000);
        }
        printf(RESET "\n");
    }
}

int main_bendera() {
    int tinggi;
    char pilihan;
    do {
        printf("===================================\n");
        printf("=             Bendera             =\n");
        printf("===================================\n");
        printf("Masukkan tinggi bendera: ");
        scanf("%d", &tinggi);

        printf("\nBendera Indonesia:\n");
        BenderaIndonesia(tinggi);

        printf("\n===================================\n");
        printf("Pilihan:\n");
        printf("1. Ulang\n");
        printf("2. Exit\n");
        printf("Pilihan Anda: ");
        scanf(" %c", &pilihan);

    } while (pilihan == '1');
    printf("Keluar dari program.\n");

    return 0;
}
