#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main_apotek() {
    int pilihan, jumlah, uang, total = 0, total_sementara;
    char barang[50][100];
    int harga[50];
    int count = 0;

    printf("                             Selamat datang di Apotik Laras Baru                                 \n");
    printf("                            Silahkan pilih obat yang Anda butuhkan                               \n");
    printf("=================================================================================================\n");
    printf("|No. | Obat Dewasa        | Harga     |               |No.  | Obat Anak             |Harga      |\n");
    printf("=================================================================================================\n");
    printf("|1.  | Paramex            |Rp 20000   |               |6.   | Holistic Care         |Rp 45000   |\n");
    printf("|2.  | Panadol            |Rp 15000   |               |7.   | Ibuprofen             |Rp 35000   |\n");
    printf("|3.  | Insulin            |Rp 10000   |               |8.   | OBH                   |Rp 25000   |\n");
    printf("|4.  | Decolgen           |Rp 30000   |               |9.   | Paracetamol           |Rp 8000    |\n");
    printf("|5.  | Decolsin           |Rp 30000   |               |10.  | Rhinoz                |Rp 6000    |\n");
    printf("=================================================================================================\n");
    printf("(99) Struk Pembayaran\n");
    printf("(55) Reset Pilihan\n");
    printf("(0) keluar\n");

    while (1) {
        printf("\nObat yang anda mau beli/opsi lain: >> ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            printf("PARAMEX\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 20000 * jumlah;
            total += total_sementara;
            strcpy(barang[count], "Paramex");
            harga[count] = total_sementara;
            count++;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 2:
            printf("PANADOL\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 15000 * jumlah;
            total += total_sementara;
            strcpy(barang[count], "Panadol");
            harga[count] = total_sementara;
            count++;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
         case 3:
            printf("INSULIN\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 10000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 4:
            printf("DECOLGEN\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 30000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 5:
            printf("DECOLSIN\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 30000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 6:
            printf("HOLISTIC CARE\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 45000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 7:
            printf("IBUPROFEN\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 35000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 8:
            printf("OBH\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 25000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 9:
            printf("PARACETAMOL\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 8000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;
        case 10:
            printf("RHINOZ\n");
            printf("JUMLAH YANG ANDA INGINKAN>> ");
            scanf("%d", &jumlah);
            total_sementara = 6000 * jumlah;
            total += total_sementara;
            printf("Menambah Ke Nota sejumlah: Rp %d\n", total_sementara);
            break;

        case 99:
            printf("\n===== STRUK PEMBAYARAN =====\n");
            for (int i = 0; i < count; i++) {
                printf("%d. %s - Rp %d\n", i + 1, barang[i], harga[i]);
            }
            printf("Total Belanja: Rp %d\n", total);
            printf("MASUKKAN UANG PEMBAYARAN >> ");
            scanf("%d", &uang);
            if (uang < total) {
                printf("Uang Anda tidak cukup. Harap bayar minimal Rp %d\n", total);
            } else {
                printf("Kembalian Anda: Rp %d\n", uang - total);
                printf("Terima kasih telah berbelanja!\n");
                total = 0; // Reset total setelah pembayaran
                count = 0; // Reset jumlah barang
            }
            break;
        case 55:
            total = 0;
            count = 0; // Reset jumlah barang
            printf("Pilihan telah di-reset. Total belanja sekarang: Rp %d\n", total);
            break;
        case 0:
            printf("Terima Kasih\n");
            return;
        default:
            printf("PILIHAN YANG ANDA MASUKKAN TIDAK TERSEDIA.\n");
        }
    }
}
