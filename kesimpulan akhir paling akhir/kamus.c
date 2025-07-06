#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KATA 50 //definisi/konstanta
#define MAX_DEFINISI 200


//Ini merujuk pada struktur data yang telah didefinisikan sebelumnya untuk menyimpan informasi kata dan definisinya.
struct Kamus {
    char kata[MAX_KATA];
    char definisi[MAX_DEFINISI];
};

//Fungsi untuk menambahkan kata baru
void tambahKata(struct Kamus kamus[], int *jumlah_kata) {
    if (*jumlah_kata >= MAX_KATA) {                                 //Ini adalah cara untuk mengakses nilai yang ditunjuk oleh pointer jumlah_kata
        printf("\t\t\t\tKamus penuh! Tidak bisa menambahkan kata baru.\n");
        return;
                                                                    //Tanda bintang ini menunjukkan bahwa jumlah_kata adalah pointer.
                            //Pointer ini menunjuk ke alamat memori dari sebuah variabel integer yang menyimpan jumlah kata yang sudah ada dalam kamus.
    }


    printf("\n\t\t\t\tMasukkan kata baru: ");
    scanf("%s", kamus[*jumlah_kata].kata);

    printf("\t\t\t\tMasukkan definisi kata: ");
    scanf(" %[^\n]", kamus[*jumlah_kata].definisi);


    //Baris ini digunakan untuk menginkremen nilai variabel jumlah_kata.
    //Variabel ini digunakan untuk melacak jumlah kata yang sudah ada dalam kamus.
    (*jumlah_kata)++;
    printf("\t\t\t\tKata berhasil ditambahkan!\n");
}

// Fungsi untuk mencari definisi kata
void cariDefinisi(struct Kamus kamus[], int jumlah_kata) {
    char cari_kata[MAX_KATA];
    int i, found = 0;

    printf("\n\t\t\t\tMasukkan kata yang ingin dicari: ");
    scanf("%s", cari_kata);

    for (i = 0; i < jumlah_kata; i++) {
        if (strcmp(kamus[i].kata, cari_kata) == 0) {
            printf("\t\t\t\tDefinisi %s: %s\n", kamus[i].kata, kamus[i].definisi);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\t\t\t\tKata tidak ditemukan dalam kamus.\n");
    }
}

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    printf("\t\t\t\tMenu:\n");
    printf("\t\t\t\t1. Cari definisi kata\n");
    printf("\t\t\t\t2. Tambah kata baru\n");
    printf("\t\t\t\t0. Keluar\n");
    printf("\t\t\t\tPilih menu: ");
}

void gaf(){
    printf("\n\t\t\t\tSelamat Natal");
}

int main_kamus() {
    int jumlah_kata = 0, i, pilihan;
    struct Kamus kamus[MAX_KATA];

    printf("\t\t\t\tMasukkan jumlah kata awal dalam kamus: ");
    scanf("%d", &jumlah_kata);

    // Input data awal untuk kamus
    for (i = 0; i < jumlah_kata; i++) {
        printf("\n\t\t\t\tMasukkan kata ke-%d: ", i + 1);
        scanf("%s", kamus[i].kata);

        printf("\t\t\t\tMasukkan definisi kata: ");
        scanf(" %[^\n]", kamus[i].definisi);
    }



    // Menu utama
    do {
        system("cls");  // Membersihkan layar
        tampilkanMenu();
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                cariDefinisi(kamus, jumlah_kata);
                break;
            case 2:
                tambahKata(kamus, &jumlah_kata);
                break;
            case 0:
                printf("\n\t\t\t\tKeluar dari program.\n");
                break;
            case 25:
                gaf();
                printf("\n\t\t\t\tini adalah easter egg\n");
                break;
            default:
                printf("\n\t\t\t\tWIHH. Silakan coba lagi.\n");
        }

        if (pilihan != 0) {
            printf("\n\t\t\t\tTekan enter untuk kembali ke menu...");
            getchar();
            getchar();
        }
    } while (pilihan != 0);

    return 0;
}
