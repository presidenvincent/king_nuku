#include <stdio.h>

// Fungsi untuk kalkulator biasa
void basicCalculator() {
    double num1, num2, result;
    char operator;
    int valid = 1;

    printf("\n=== Kalkulator Biasa ===\n");
    printf("Masukkan operasi (contoh: 5 + 3): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    getchar(); // Membersihkan buffer

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Pembagian dengan nol tidak diperbolehkan!\n");
                valid = 0;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            printf("Operator tidak valid! Gunakan +, -, *, atau /.\n");
            valid = 0;
            break;
    }

    if (valid) {
        printf("Hasil: %.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
    }
}

// Fungsi untuk kalkulator usia
void ageCalculator() {
    int birth_day, birth_month, birth_year;
    int current_day = 13, current_month = 7, current_year = 2025; // Tanggal saat ini
    int age;

    printf("\n=== Kalkulator Usia ===\n");
    printf("Masukkan tanggal lahir (DD MM YYYY, contoh: 15 5 1990): ");
    scanf("%d %d %d", &birth_day, &birth_month, &birth_year);
    getchar(); // Membersihkan buffer

    // Validasi tanggal lahir
    if (birth_year > current_year || 
        (birth_year == current_year && birth_month > current_month) ||
        (birth_year == current_year && birth_month == current_month && birth_day > current_day)) {
        printf("Tanggal lahir tidak valid! Harus sebelum 13 Juli 2025.\n");
        return;
    }
    if (birth_day < 1 || birth_day > 31 || birth_month < 1 || birth_month > 12 || birth_year < 1900) {
        printf("Tanggal lahir tidak valid! Gunakan format DD (1-31), MM (1-12), YYYY (>=1900).\n");
        return;
    }

    // Hitung usia (sederhana, berdasarkan tahun dan bulan)
    age = current_year - birth_year;
    if (current_month < birth_month || (current_month == birth_month && current_day < birth_day)) {
        age--; // Kurangi usia jika ulang tahun belum lewat
    }

    printf("Usia Anda: %d tahun\n", age);
}

int main() {
    int choice;
    char continue_loop;

    do {
        // Menu utama
        printf("\n=== Program Kalkulator ===\n");
        printf("1. Kalkulator Biasa\n");
        printf("2. Kalkulator Usia\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan (1-3): ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer

        switch (choice) {
            case 1:
                basicCalculator();
                break;

            case 2:
                ageCalculator();
                break;

            case 3:
                printf("Program selesai.\n");
                return 0;

            default:
                printf("Pilihan tidak valid! Gunakan 1, 2, atau 3.\n");
                break;
        }

        // Tanya apakah ingin melanjutkan
        printf("\nApakah ingin melanjutkan? (y/n): ");
        scanf(" %c", &continue_loop);
    } while (continue_loop == 'y' || continue_loop == 'Y');

    printf("Program selesai.\n");
    return 0;
}