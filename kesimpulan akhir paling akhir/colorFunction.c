#include <stdio.h>
void printfWarna(const char *text, const char *warna) {
    printf("%s%s\033[0m\n", warna, text);
}
#define MERAH "\033[31m"
#define HIJAU "\033[32m"
#define KUNING "\033[33m"
#define BIRU "\033[34m"
#define UNGU "\033[35m"
#define CYAN "\033[36m"
#define PUTIH "\033[37m"
int mainjiroooo() {
    printfWarna("Ini teks berwarna merah.", MERAH);
    printfWarna("Ini teks berwarna hijau.", HIJAU);
    printfWarna("Ini teks berwarna kuning.", KUNING);
    printfWarna("Ini teks berwarna biru.", BIRU);
    printfWarna("Ini teks berwarna ungu.", UNGU);
    printfWarna("Ini teks berwarna cyan.", CYAN);
    printfWarna("Ini teks berwarna putih.", PUTIH);
    printf("Ini teks normal.\n");
    return 0;
}
