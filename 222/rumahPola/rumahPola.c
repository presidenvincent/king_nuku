#include <stdio.h>

// Fungsi untuk mencetak pola rumah dengan atap mengikuti lebar badan
void printHouse(int roof_height, int body_height, int body_width) {
    printf("\nPola Rumah Memanjang:\n");
    
    // Cetak cerobong asap (2 baris, di sisi kiri atas)
    printf("  **\n"); // Cerobong bagian atas
    printf("  **\n"); // Cerobong bagian bawah
    
    // Cetak atap (segitiga dengan lebar sesuai body_width)
    for (int i = 1; i <= roof_height; i++) {
        // Cetak spasi sebelum bintang
        for (int j = 1; j <= roof_height - i; j++) {
            printf(" ");
        }
        // Cetak bintang untuk atap
        // Jumlah bintang di baris ke-i = body_width * (i / roof_height)
        int stars = (i * body_width + roof_height - 1) / roof_height; // Proporsi bintang
        for (int j = 1; j <= stars; j++) {
            printf("* ");
        }
        printf("\n");
    }
    
    // Cetak badan rumah (kotak dengan pintu)
    int door_height = body_height / 2; // Tinggi pintu (setengah dari badan rumah)
    int door_width = body_width / 4;   // Lebar pintu (seperempat lebar badan)
    if (door_width < 2) door_width = 2; // Pastikan pintu minimal 2 karakter lebar
    int door_start = (body_width - door_width) / 2 + 1; // Posisi awal pintu (tengah)

    for (int i = 1; i <= body_height; i++) {
        // Cetak bintang untuk badan rumah
        for (int j = 1; j <= body_width; j++) {
            // Logika untuk pintu di tengah bawah
            if (i > body_height - door_height && j >= door_start && j < door_start + door_width) {
                printf("  "); // Spasi untuk pintu
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    int roof_height, body_height, body_width, choice;
    char continue_loop;

    do {
        // Menu utama
        printf("\n=== Program Pola Rumah Berbintang Memanjang ===\n");
        printf("1. Cetak Pola Rumah\n");
        printf("2. Keluar\n");
        printf("Masukkan pilihan (1-2): ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer

        switch (choice) {
            case 1:
                // Input tinggi atap, tinggi badan, dan lebar badan rumah
                printf("Masukkan tinggi atap rumah (min. 3): ");
                scanf("%d", &roof_height);
                getchar(); // Membersihkan buffer
                printf("Masukkan tinggi badan rumah (min. 3): ");
                scanf("%d", &body_height);
                getchar(); // Membersihkan buffer
                printf("Masukkan lebar badan rumah (min. 5): ");
                scanf("%d", &body_width);
                getchar(); // Membersihkan buffer

                // Validasi input
                if (roof_height < 3 || body_height < 3 || body_width < 5) {
                    printf("Input tidak valid! Tinggi atap dan badan minimal 3, lebar badan minimal 5.\n");
                    break;
                }
                printHouse(roof_height, body_height, body_width);
                break;

            case 2:
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