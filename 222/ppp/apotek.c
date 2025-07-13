#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_NAME 50
#define MAX_DRUGS 100
#define MAX_HISTORY 100

// Struktur untuk data obat
struct Drug {
    char code[10];    // Kode obat
    char name[MAX_NAME]; // Nama obat
    int stock;        // Jumlah stok
    float price;      // Harga obat
};

// Struktur untuk histori pembelian
struct PurchaseHistory {
    char code[10];    // Kode obat
    char name[MAX_NAME]; // Nama obat
    int quantity;     // Jumlah dibeli
    float total_cost; // Total biaya
    char timestamp[20]; // Waktu transaksi
};

// Fungsi untuk menukar dua elemen struct Drug
void swap(struct Drug *a, struct Drug *b) {
    struct Drug temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi bubble sort berdasarkan harga
void bubbleSort(struct Drug arr[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascending) {
                if (arr[j].price > arr[j + 1].price) {
                    swap(&arr[j], &arr[j + 1]);
                }
            } else {
                if (arr[j].price < arr[j + 1].price) {
                    swap(&arr[j], &arr[j + 1]);
                }
            }
        }
    }
}

// Fungsi insertion sort berdasarkan harga
void insertionSort(struct Drug arr[], int n, int ascending) {
    for (int i = 1; i < n; i++) {
        struct Drug key = arr[i];
        int j = i - 1;
        if (ascending) {
            while (j >= 0 && arr[j].price > key.price) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            while (j >= 0 && arr[j].price < key.price) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

// Fungsi untuk menampilkan data obat
void displayDrugs(struct Drug arr[], int n) {
    if (n == 0) {
        printf("\nData obat kosong.\n");
        return;
    }
    printf("\nDaftar Obat:\n");
    printf("No. | Kode Obat | Nama Obat             | Stok | Harga\n");
    printf("----|-----------|-----------------------|------|--------\n");
    for (int i = 0; i < n; i++) {
        printf("%-3d | %-9s | %-21s | %-4d | %.2f\n", i + 1, arr[i].code, arr[i].name, arr[i].stock, arr[i].price);
    }
}

// Fungsi untuk menampilkan histori pembelian
void displayHistory(struct PurchaseHistory history[], int n) {
    if (n == 0) {
        printf("\nBelum ada histori pembelian.\n");
        return;
    }
    printf("\nHistori Pembelian:\n");
    printf("No. | Kode Obat | Nama Obat             | Jumlah | Total Biaya | Waktu\n");
    printf("----|-----------|-----------------------|--------|-------------|-------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-3d | %-9s | %-21s | %-6d | %-11.2f | %s\n", i + 1, history[i].code, history[i].name, 
               history[i].quantity, history[i].total_cost, history[i].timestamp);
    }
}

// Fungsi untuk mendapatkan waktu saat ini sebagai string
void getCurrentTime(char *buffer) {
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", timeinfo);
}

// Fungsi untuk membeli obat
void buyDrug(struct Drug arr[], int n, struct PurchaseHistory history[], int *history_count) {
    char code[10];
    int quantity;
    float money;

    // Tampilkan daftar obat
    displayDrugs(arr, n);

    // Input kode obat
    printf("\nMasukkan Kode Obat yang ingin dibeli: ");
    fgets(code, 10, stdin);
    code[strcspn(code, "\n")] = 0; // Menghapus newline

    // Input jumlah obat
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", &quantity);
    getchar(); // Membersihkan buffer

    // Input jumlah uang
    printf("Masukkan jumlah uang Anda: ");
    scanf("%f", &money);
    getchar(); // Membersihkan buffer

    // Cari obat berdasarkan kode
    int found = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].code, code) == 0) {
            found = i;
            break;
        }
    }

    // Validasi pembelian
    if (found == -1) {
        printf("Kode obat tidak ditemukan!\n");
        return;
    }
    if (quantity <= 0) {
        printf("Jumlah pembelian tidak valid!\n");
        return;
    }
    if (quantity > arr[found].stock) {
        printf("Stok tidak cukup! Stok tersedia: %d\n", arr[found].stock);
        return;
    }
    float total_cost = quantity * arr[found].price;
    if (money < total_cost) {
        printf("Uang tidak cukup! Total biaya: %.2f, Uang Anda: %.2f\n", total_cost, money);
        return;
    }
    if (*history_count >= MAX_HISTORY) {
        printf("Kapasitas histori penuh! Tidak bisa mencatat pembelian.\n");
        return;
    }

    // Proses pembelian
    arr[found].stock -= quantity;

    // Catat ke histori
    strcpy(history[*history_count].code, arr[found].code);
    strcpy(history[*history_count].name, arr[found].name);
    history[*history_count].quantity = quantity;
    history[*history_count].total_cost = total_cost;
    getCurrentTime(history[*history_count].timestamp);
    (*history_count)++;

    // Tampilkan rincian pembelian
    printf("\nPembelian berhasil!\n");
    printf("Obat: %s\n", arr[found].name);
    printf("Jumlah: %d\n", quantity);
    printf("Total biaya: %.2f\n", total_cost);
    printf("Kembalian: %.2f\n", money - total_cost);
    printf("Stok tersisa: %d\n", arr[found].stock);
}

int main() {
    // Inisialisasi data obat awal (5 obat)
    struct Drug drugs[MAX_DRUGS] = {
        {"OBT001", "Paracetamol", 100, 5000.00},
        {"OBT002", "Amoxicillin", 50, 15000.00},
        {"OBT003", "Ibuprofen", 75, 8000.00},
        {"OBT004", "Cetirizine", 60, 12000.00},
        {"OBT005", "Omeprazole", 40, 20000.00}
    };
    int n = 5; // Jumlah obat awal

    // Inisialisasi histori pembelian
    struct PurchaseHistory history[MAX_HISTORY];
    int history_count = 0;

    int choice, sort_choice, order_choice;
    char continue_loop;

    do {
        // Menu utama
        printf("\n=== Sistem Manajemen Apotek ===\n");
        printf("1. Beli Obat\n");
        printf("2. Urutkan Data Obat\n");
        printf("3. Tampilkan Data Obat\n");
        printf("4. Tampilkan Histori Pembelian\n");
        printf("5. Keluar\n");
        printf("Masukkan pilihan (1-5): ");
        scanf("%d", &choice);
        getchar(); // Membersihkan buffer

        switch (choice) {
            case 1:
                // Beli obat
                if (n == 0) {
                    printf("Data obat kosong!\n");
                    break;
                }
                buyDrug(drugs, n, history, &history_count);
                break;

            case 2:
                // Pilih metode sorting
                if (n == 0) {
                    printf("Data obat kosong!\n");
                    break;
                }
                printf("\nPilih metode pengurutan (berdasarkan harga):\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                printf("Masukkan pilihan (1-2): ");
                scanf("%d", &sort_choice);
                getchar(); // Membersihkan buffer

                printf("Pilih urutan:\n");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Masukkan pilihan (1-2): ");
                scanf("%d", &order_choice);
                getchar(); // Membersihkan buffer

                // Tampilkan data sebelum sorting
                printf("\nSebelum pengurutan:\n");
                displayDrugs(drugs, n);

                // Proses pengurutan
                switch (sort_choice) {
                    case 1:
                        bubbleSort(drugs, n, order_choice == 1);
                        printf("\nSetelah pengurutan dengan Bubble Sort (berdasarkan harga, %s):\n", 
                               order_choice == 1 ? "ascending" : "descending");
                        displayDrugs(drugs, n);
                        break;
                    case 2:
                        insertionSort(drugs, n, order_choice == 1);
                        printf("\nSetelah pengurutan dengan Insertion Sort (berdasarkan harga, %s):\n", 
                               order_choice == 1 ? "ascending" : "descending");
                        displayDrugs(drugs, n);
                        break;
                    default:
                        printf("Pilihan tidak valid!\n");
                        break;
                }
                break;

            case 3:
                // Tampilkan data obat
                displayDrugs(drugs, n);
                break;

            case 4:
                // Tampilkan histori pembelian
                displayHistory(history, history_count);
                break;

            case 5:
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