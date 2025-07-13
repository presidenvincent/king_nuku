#include <stdio.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_STUDENTS 100

// Struktur untuk data mahasiswa
struct Mahasiswa {
    char nim[15];
    char nama[MAX_NAME];
    float ipk;
};

// Fungsi untuk menukar dua elemen struct Mahasiswa
void swap(struct Mahasiswa *a, struct Mahasiswa *b) {
    struct Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi bubble sort berdasarkan IPK (ascending)
void bubbleSort(struct Mahasiswa arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ipk > arr[j + 1].ipk) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Fungsi insertion sort berdasarkan IPK (ascending)
void insertionSort(struct Mahasiswa arr[], int n) {
    for (int i = 1; i < n; i++) {
        struct Mahasiswa key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].ipk > key.ipk) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk menampilkan data mahasiswa
void displayStudents(struct Mahasiswa arr[], int n) {
    if (n == 0) {
        printf("\nData mahasiswa kosong.\n");
        return;
    }
    printf("\nDaftar Mahasiswa:\n");
    printf("No. | NIM           | Nama                  | IPK\n");
    printf("----|---------------|-----------------------|------\n");
    for (int i = 0; i < n; i++) {
        printf("%-3d | %-13s | %-21s | %.2f\n", i + 1, arr[i].nim, arr[i].nama, arr[i].ipk);
    }
}

// Fungsi untuk menambah data mahasiswa
int addStudent(struct Mahasiswa arr[], int *n) {
    if (*n >= MAX_STUDENTS) {
        printf("Kapasitas penuh! Tidak bisa menambah data.\n");
        return *n;
    }

    printf("\nMasukkan Data Mahasiswa Baru:\n");
    printf("Masukkan NIM: ");
    fgets(arr[*n].nim, 15, stdin);
    arr[*n].nim[strcspn(arr[*n].nim, "\n")] = 0; // Menghapus newline

    printf("Masukkan Nama: ");
    fgets(arr[*n].nama, MAX_NAME, stdin);
    arr[*n].nama[strcspn(arr[*n].nama, "\n")] = 0; // Menghapus newline

    printf("Masukkan IPK (0.0 - 4.0): ");
    scanf("%f", &arr[*n].ipk);
    getchar(); // Membersihkan buffer

    // Validasi IPK
    if (arr[*n].ipk < 0.0 || arr[*n].ipk > 4.0) {
        printf("IPK tidak valid! Harus antara 0.0 dan 4.0\n");
        return *n;
    }

    (*n)++; // Increment jumlah mahasiswa
    printf("Data mahasiswa berhasil ditambahkan.\n");
    return *n;
}

int main() {
    struct Mahasiswa students[MAX_STUDENTS];
    int n = 0; // Jumlah mahasiswa saat ini
    int choice, sort_choice;
    char continue_loop;

    do {
        // Menu utama
        printf("\n=== Program Pengelolaan Data Mahasiswa ===\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Urutkan Data Mahasiswa\n");
        printf("3. Tampilkan Data Mahasiswa\n");
        printf("4. Keluar\n");
        printf("Masukkan pilihan (1-4): ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer

        switch (choice) {
            case 1:
                // Tambah data mahasiswa
                n = addStudent(students, &n);
                break;

            case 2:
                // Pilih metode sorting
                if (n == 0) {
                    printf("Data mahasiswa kosong. Tambahkan data terlebih dahulu.\n");
                    break;
                }
                printf("\nPilih metode pengurutan:\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                printf("Masukkan pilihan (1-2): ");
                scanf("%d", &sort_choice);
                getchar(); // Membersihkan buffer

                // Tampilkan data sebelum sorting
                printf("\nSebelum pengurutan:\n");
                displayStudents(students, n);

                // Proses pengurutan
                switch (sort_choice) {
                    case 1:
                        bubbleSort(students, n);
                        printf("\nSetelah pengurutan dengan Bubble Sort (berdasarkan IPK, ascending):\n");
                        displayStudents(students, n);
                        break;
                    case 2:
                        insertionSort(students, n);
                        printf("\nSetelah pengurutan dengan Insertion Sort (berdasarkan IPK, ascending):\n");
                        displayStudents(students, n);
                        break;
                    default:
                        printf("Pilihan tidak valid!\n");
                        break;
                }
                break;

            case 3:
                // Tampilkan data mahasiswa
                displayStudents(students, n);
                break;

            case 4:
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