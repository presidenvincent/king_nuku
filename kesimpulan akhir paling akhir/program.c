//==================================================== MAIN PROGRAM KELOMPOK 5 ======================================================//
//------------------------------------------------FOLLOW ME ON GITHUB>> Alfando345--------------------------------------------------//
#include "warnaBGFunction.c"
#include "vbs.c"
#include "LICENCIES.c"

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include "login.c"
#include "kamus.c"
#include "exit.c"
#include "rumahpl.c"
#include "guntingBatuKertas.c"
#include "apotek.c"
#include "BENDERA.c"
#include "auth.c"
#include "colorFunction.c"




void rammmm() {
    //https://github.com/Alfando345
    SYSTEM_INFO sysInfo;
    MEMORYSTATUSEX memInfo;
    GetSystemInfo(&sysInfo);
    printf("\n");
    printf("Arch             >> %u_core\n", sysInfo.wProcessorArchitecture);
    printf("CORE OF PROCCESOR>> %u\n", sysInfo.dwNumberOfProcessors);
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    printf("DEVICE RAM       >> %llu MB\n", memInfo.ullTotalPhys / 1024 / 1024);
    printf("RAM TERSEEDIA    >> %llu MB\n", memInfo.ullAvailPhys / 1024 / 1024);
}






void clear() {
    system("cls");
    printfBackground("THIS APP POWERD BY KELOMPOK 5         \n", BG_MERAH); printf("\033[31mINSTAGRAM: <@grteo_alfndd21, @nguyenngab_, @jeessii.caa, @btradestraa_, @presidentvincent>  undefinedd \033[0m"); rammmm();
    printf("\n");
}


void loading() {
    clear();
    printfWarna("\n\n\n\n\n\n\n\n\t\t\t\t\t    \tLOADING.", MERAH);
    sleep(1);
    clear();
    printfWarna("\n\n\n\n\n\n\n\n\t\t\t\t\t    \tLOADING..", MERAH);
    sleep(1);
    clear();
    printfWarna("\n\n\n\n\n\n\n\n\t\t\t\t\t    \tLOADING...", MERAH);

}

void daftarMenu() {
    printfWarna("\t\t\t\t                       KELOMPOK 5\n\n\n", HIJAU);
    printf("\t\t\t\t <====================================================>\n\n\n");
    tlis("\t\t\t\t               1. RUMAH POLA__________>\n");
    tlis("\t\t\t\t               2. APOTEK______________>\n");
    tlis("\t\t\t\t               3. BATU GUNTING KERTAS_>\n");
    tlis("\t\t\t\t               4. BENDERA_____________>\n");
    tlis("\t\t\t\t               5. KAMUS_______________>\n");
    tlis("\t\t\t\t               6. AUTHOR______________>\n");
    tlis("\t\t\t\t               7. EXIT()______________>\n");
    printf("\n\n\n\t\t\t\t <====================================================>\n\n");

}





int main() {
    int Kryss;
    // erormain();
    //clear();
    // mainNotepadd();
    vbsOpeningBoss();
    clear();
    int coise;
    main_loading();
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t     SEDANG MERESET WARNA MENJADI HITAM\n");
    printf("\t\t\t\t\t\t  "); printfBackground("SABAR BANG", BG_MERAH);
    sleep(3);
    system("color 07");
    while (1) {
        clear();
        daftarMenu();
        printfBackground("ENTER YOUR PILIHAN>>>  ", BG_UNGU); scanf("%d", &coise); //printf("<<<<<<< ")
        switch (coise) {
    case 1:
        loading();
        clear();
        main_pollaku();
        mainNotepadd();
        break;
    case 2:
        loading();
        clear();
        main_apotek();
        mainNotepadd();
        break;
    case 3:
        loading();
        clear();
        main_bbg();
        mainNotepadd();
        break;
    case 4:
        loading();
        clear();
        main_bendera();
        mainNotepadd();
        break;
    case 5:
        loading();
        clear();
        main_kamus();
        mainNotepadd();
        break;
    case 6:
        loading();
        clear();
        main_aoth();
        mainNotepadd();
        break;
    case 7:
        //loading();
        printfBackground("DO YOU REALLY WANT TO EXIT(0/1)>> ", BG_MERAH);
        scanf("%d", &Kryss);
        if (Kryss == 1) {
        clear();
        main_exittt();
        clear();
        break;
        } else { break;
        }

    default:
        clear();
        printfBackground("\t\t\t\t\t\t        MOHON MAAF       \n", BG_MERAH);
        printfBackground("\t\t\t\t\t\t      BELUM TERSEDIA      ", BG_MERAH);
        sleep(0); mainNotepadd();
        break;
        }
    }
}
