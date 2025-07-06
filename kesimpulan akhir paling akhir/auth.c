#include <stdio.h>
#include <unistd.h>
#define NAMA 6
#define NIM 6

void printWithTypingEffect(const char* text, int delay) {
    for (int i = 0; text[i] != '\0'; i++) {
        putchar(text[i]);
        fflush(stdout);
        usleep(delay);
    }
    putchar('\n');
}

int main_aoth() {
    char authors[NAMA][100] = {
        "JESSICA CINDY RAHARJO",
        "BATARA DESTRA SULISTYO PRABOWO",
        "KIMTO PANGESTU",
        "NATANAEL BINTANG RENGGALIS",
        "GRATEO ALFANDO ATMOJO",
        "VINCENT DANIS LEKAHENA"
    };

    char kode[NIM][20] = {
        "672024030",
        "672024017",
        "672023148",
        "672024004",
        "672024010",
        "672024024"
    };

    printWithTypingEffect("CREATOR\n\n", 10000);

    for (int i = 0; i < NAMA; i++) {
        printf("%d. NAMA : ", i + 1);
        printWithTypingEffect(authors[i], 10000);

        printf("   NIM : ");
        printWithTypingEffect(kode[i], 10000);
        usleep(10000);
        printf("\n");
    }


     char key;
    printfBackground("\n\n\n\nU = BELUM PUAS\nQ= MENU_UTAMA()\n", BG_MERAH);
    while (1) {
        if (kbhit()) {
            key = getch();
            printf("Tombol yang ditekan: %c\n", key);

            if (key == 'U' || key == 'u') {
                system("cls");

                main_aoth();
                return 0;
            }
            else if (key == 'q' || key == 'Q') {
                system("cls");
                tlis("Keluar dari program.\n");
                break;

            }
        }
    }

    return 0;
}
