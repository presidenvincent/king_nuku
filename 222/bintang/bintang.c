#include <stdio.h>

// Fungsi untuk mencetak segitiga bintang
void printTriangle(int height) {
    printf("\nSegitiga Bintang:\n");
    for (int i = 1; i <= height; i++) {
        // Cetak spasi sebelum bintang
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        // Cetak bintang
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Fungsi untuk mencetak segitiga bintang terbalik
void printInvertedTriangle(int height) {
    printf("\nSegitiga Bintang Terbalik:\n");
    for (int i = height; i >= 1; i--) {
        // Cetak spasi sebelum bintang
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        // Cetak bintang
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Fungsi untuk mencetak kotak bintang
void printSquare(int side) {
    printf("\nKotak Bintang:\n");
    for (int i = 1; i <= side; i++) {
        // Cetak bintang sebanyak sisi
        for (int j = 1; j <= side; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

// Fungsi untuk mencetak trapesium bintang
void printTrapezoid(int height, int base) {
    printf("\nTrapesium Bintang:\n");
    for (int i = 1; i <= height; i++) {
        // Cetak spasi sebelum bintang
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        // Cetak bintang (basis + tambahan per baris)
        for (int j = 1; j <= base + (i - 1) * 2; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Fungsi untuk mencetak jajar genjang bintang
void printParallelogram(int base, int height) {
    printf("\nJajar Genjang Bintang:\n");
    for (int i = 1; i <= height; i++) {
        // Cetak spasi sebelum bintang
        for (int j = 1; j <= height - i; j++) {
            printf(" ");
        }
        // Cetak bintang sebanyak basis
        for (int j = 1; j <= base; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int height, side, base, choice;
    char continue_loop;

    do {
        // Menu utama
        printf("\n=== Program Pola Bintang ===\n");
        printf("1. Segitiga Bintang\n");
        printf("2. Segitiga Bintang Terbalik\n");
        printf("3. Kotak Bintang\n");
        printf("4. Trapesium Bintang\n");
        printf("5. Jajar Genjang Bintang\n");
        printf("6. Keluar\n");
        printf("Masukkan pilihan (1-6): ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer

        switch (choice) {
            case 1:
                // Input tinggi untuk segitiga
                printf("Masukkan tinggi segitiga (min. 1): ");
                scanf("%d", &height);
                getchar(); // Membersihkan buffer
                if (height < 1) {
                    printf("Tinggi tidak valid! Harus minimal 1.\n");
                    break;
                }
                printTriangle(height);
                break;

            case 2:
                // Input tinggi untuk segitiga terbalik
                printf("Masukkan tinggi segitiga (min. 1): ");
                scanf("%d", &height);
                getchar(); // Membersihkan buffer
                if (height < 1) {
                    printf("Tinggi tidak valid! Harus minimal 1.\n");
                    break;
                }
                printInvertedTriangle(height);
                break;

            case 3:
                // Input sisi untuk kotak
                printf("Masukkan panjang sisi kotak (min. 1): ");
                scanf("%d", &side);
                getchar(); // Membersihkan buffer
                if (side < 1) {
                    printf("Panjang sisi tidak valid! Harus minimal 1.\n");
                    break;
                }
                printSquare(side);
                break;

            case 4:
                // Input tinggi dan basis untuk trapesium
                printf("Masukkan tinggi trapesium (min. 1): ");
                scanf("%d", &height);
                getchar(); // Membersihkan buffer
                printf("Masukkan panjang sisi bawah (basis, min. 3): ");
                scanf("%d", &base);
                getchar(); // Membersihkan buffer
                if (height < 1 || base < 3) {
                    printf("Tinggi atau basis tidak valid! Tinggi minimal 1, basis minimal 3.\n");
                    break;
                }
                printTrapezoid(height, base);
                break;

            case 5:
                // Input basis dan tinggi untuk jajar genjang
                printf("Masukkan panjang sisi bawah (basis, min. 3): ");
                scanf("%d", &base);
                getchar(); // Membersihkan buffer
                printf("Masukkan tinggi jajar genjang (min. 1): ");
                scanf("%d", &height);
                getchar(); // Membersihkan buffer
                if (base < 3 || height < 1) {
                    printf("Basis atau tinggi tidak valid! Basis minimal 3, tinggi minimal 1.\n");
                    break;
                }
                printParallelogram(base, height);
                break;

            case 6:
                // Keluar dari program
                printf("Program selesai.\n");
                return 0;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }

        // Tanya apakah ingin melanjutkan
        printf("\nApakah ingin melanjutkan? (y/n): ");
        scanf(" %c", &continue_loop);
    } while (continue_loop == 'y' || continue_loop == 'Y');

    printf("Program selesai.\n");
    return 0;
}