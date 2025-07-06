#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void garisKeren() {
    printf("\n");
    printf("\t\t\t\t");
    for (int asyu = 0; asyu <= 50; asyu++){
        printf("=", asyu);
        usleep(10000);
    }
}

void tlis(const char *str) {
    while (*str) {
        putchar(*str);
        fflush(stdout);
        usleep(15000);
        str++;
    }
}



void stop () {
    //system("cls");
    printf("\n\n\n\n\n\n");
    garisKeren(); printf("\n\n\n");
    tlis("\t\t\t\t\t TERIMAKASIH UNTUK BIMBINGANYA\n"); //sleep(1);
    tlis("\t\t\t\t\t          SELAMA INI\n");
    tlis("\t\t\t\t\t          @ftiuksw\n\n\n");
    garisKeren();
    printf("\n\n\n\n");
}

void Keluar() {
    printf("\t\t\t\t\t PROGRAM AKAN KELUAR DALAM 3\n");
    sleep(1);
        printf("\t\t\t\t\t PROGRAM AKAN KELUAR DALAM 2\n");
    sleep(1);
        printf("\t\t\t\t\t PROGRAM AKAN KELUAR DALAM 1\n");
    sleep(1);
    exit(0);

}

int main_exittt() {
    stop();
    Keluar();
}
