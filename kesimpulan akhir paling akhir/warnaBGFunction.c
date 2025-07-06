
/*THIS FUNCTION WAS MADE BY AKFANDO_XEONN */

#include <stdio.h>
void printfBackground(const char *text, const char *background) {
    printf("%s%s\033[0m", background, text);
}
#define BG_MERAH "\033[41m"
#define BG_HIJAU "\033[42m"
#define BG_KUNING "\033[43m"
#define BG_BIRU "\033[44m"
#define BG_UNGU "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_PUTIH "\033[47m"
#define BG_HITAM "\033[40m"

int mainjj() {
    printfBackground("Ini teks dengan background merah.", BG_MERAH);
    printfBackground("Ini teks dengan background hijau.", BG_HIJAU);
    printfBackground("Ini teks dengan background kuning.", BG_KUNING);
    printfBackground("Ini teks dengan background biru.", BG_BIRU);
    printfBackground("Ini teks dengan background ungu.", BG_UNGU);
    printfBackground("Ini teks dengan background cyan.", BG_CYAN);
    printfBackground("Ini teks dengan background putih.", BG_PUTIH);
    printfBackground("Ini teks dengan background hitam.", BG_HITAM);
    printf("Ini teks normal tanpa background.\n");
    return 0;
}

