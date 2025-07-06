#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void main_vbs(const char *vbsScript) {
    char tempPath[MAX_PATH];
    GetTempPathA(MAX_PATH, tempPath);
    char tempFile[MAX_PATH];
    snprintf(tempFile, sizeof(tempFile), "%s\\temp_script.vbs", tempPath);
    FILE *file = fopen(tempFile, "w");
    if (file == NULL) {
        perror("JavaUnexpectedEror:23232:56577");
        return; }
    fprintf(file, "%s", vbsScript);
    fclose(file);
    char command[MAX_PATH + 50];
    snprintf(command, sizeof(command), "wscript.exe \"%s\"", tempFile);
    system(command);
    DeleteFileA(tempFile);
}


void vbsOpeningBoss() {
    const char *script =
        "Dim message\n"
        "message = \"________________LIST KELOMPOK________________\" & vbCrLf & vbCrLf & "
        "\"<=======================================>\" & vbCrLf & "
        "\"1. NAMA : JESSICA CINDY RAHARJO\" & vbCrLf & \"   NIM : 672024030\" & vbCrLf & "
        "\"2. NAMA : BATARA DESTRA SULISTYO PRABOWO\" & vbCrLf & \"   NIM : 672024017\" & vbCrLf & "
        "\"3. NAMA : KIMTO PANGESTU\" & vbCrLf & \"   NIM : 672023148\" & vbCrLf & "
        "\"4. NAMA : NATANAEL BINTANG RENGGALIS\" & vbCrLf & \"   NIM : 672024004\" & vbCrLf & "
        "\"5. NAMA : GRATEO ALFANDO ATMOJO\" & vbCrLf & \"   NIM : 672024010\" & vbCrLf & "
        "\"6. NAMA : VINCENT DANIS LEKAHENA\" & vbCrLf & \"   NIM : 672024024\" & vbCrLf & "
        "\"<=======================================>\"\n"
        "MsgBox message, 64, \"'D://Trojan/Kelompok_5.exe', menyatakan\""; // 64 = Icon informasi
    system("color 71");
    system("color 71");
    for (int y = 1; y < 30; y++) {
        printf("\033[47m<WARNING ALERT!!!>  \033[0m");
        printf("\033[41mHARAP DIBACA TERLEBIH DAHULU YA!!!\033[0m \n", y);
    }
    main_vbs(script);
//    return 0;
}


void autoWrite(const char *filename, const char *text);
int mainerrr() {
     char buffer[256];
     for (int juju = 10; juju <= 1; juju--) {
        snprintf(buffer, sizeof(buffer), "YOUR PC WILL SHUTDOWN KALAU MENCOBA KELUAR DARI NOTEPAD INI!!\nKESEMPATAN = %d", juju);
        autoWrite("THIS IS CAN MAKE DESTROY YOUR WINDOWS", buffer);
     }
}
