#include <stdio.h>
#include <windows.h>


/*int mainmmm() {
    SYSTEM_INFO sysInfo;
    MEMORYSTATUSEX memInfo;

    // Dapatkan info prosesor
    GetSystemInfo(&sysInfo);
    printf("Prosesor Architecture: %u\n", sysInfo.wProcessorArchitecture);
    printf("Jumlah Prosesor: %u\n", sysInfo.dwNumberOfProcessors);

    // Dapatkan info RAM
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    printf("Total RAM: %llu MB\n", memInfo.ullTotalPhys / 1024 / 1024);
    printf("Available RAM: %llu MB\n", memInfo.ullAvailPhys / 1024 / 1024);

    return 0;
}

======================================== DONT COPY THIS PROGRAM ANY MORE=======================================*/




void autoWrite(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuat file %s\n", filename);
        return;
    }
    fprintf(file, "%s", text);
    fclose(file);
    //printf("File %s berhasil dibuat!\n", filename);
    char command[256];
    snprintf(command, sizeof(command), "notepad %s", filename);
    system(command);
}

int mainNotepadd() {
        const char *watermark =
        //"=====================================================================================================================================================================================================================================================================================\n"
        "Software License Agreement\n"
        "Copyright (C) 2024 by Kelompok 5. All Rights Reserved.\n"

        "This software and its associated documentation files (the Software) are the exclusive intellectual property of Team 5 and are provided under the terms and conditions set forth in this license agreement. By using this Software, you agree to comply with the terms outlined below.\n"

"1. Grant of License:\n"
"   - Permission is hereby granted to use the Software for educational, personal, and non-commercial purposes only.\n"
"   - Redistribution, modification, or incorporation of this Software, in part or whole, into other projects or systems requires explicit prior written consent from Team 5.\n"
"   - Unauthorized commercial use, reproduction, or sublicensing of the Software is strictly prohibited.\n\n"

"2. Restrictions:\n"
"   - You may not reverse engineer, decompile, or disassemble the Software, except as expressly permitted by applicable law.\n"
"   - You may not claim ownership or authorship of the Software or any derivative work based on it.\n\n"

"3. Warranty Disclaimer:\n"
"   - The Software is provided 'AS IS,' without warranty of any kind, express or implied, including but not limited to warranties of merchantability, fitness for a particular purpose, or non-infringement.\n"
"   - In no event shall Team 5 be held liable for any damages, including but not limited to direct, indirect, incidental, or consequential damages arising out of the use of or inability to use the Software.\n\n"

"4. Limitation of Liability:\n"
"   - Team 5 shall not be responsible for any loss or damage caused by errors, bugs, or misuse of the Software.\n\n"

"5. Termination:\n"
"   - This license will terminate automatically if you fail to comply with its terms and conditions. Upon termination, you must destroy all copies of the Software in your possession.\n\n"

"6. Governing Law:\n"
"   - This license shall be governed by and construed in accordance with the laws of [Your Country/Region], without regard to its conflict of law principles.\n\n"

"By using this Software, you acknowledge that you have read, understood, and agree to be bound by the terms and conditions of this license.\n\n"

"For inquiries or permissions, please contact Team 5 at grateoalfandoatmojo@gmail.com.\n\n"

"---\n\n"

"Thank you for respecting our work and intellectual property. Your support encourages us to continue creating meaningful and impactful software.\n\n"
"Sincerely,"
"**Kelompok 5**"
;


    autoWrite("lisesni.txt", watermark);
   /* for (int yukimono = 0; yukimono < 55; yukimono++) {
        autoWrite("VIRUSTROJAN", "LOSS DOLL AKU ORA NGURUS\n085764175824");
    }*/

    return 0;
}
