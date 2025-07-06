#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Untuk usleep
#include <string.h>  // Untuk Text
#include <conio.h> // Untuk getch()

    void loadingBar(int duration) {
    system("color 71"); //INI UNTUK WARNA, 7=BIRU, 1=PUTIH
    int w;
    int barLengthBar = 50; // Panjang loading bar
    printf("\n\n\n\n\n\t\t\t\t\t\t      BENTARR\n\n\n\n\t\t\t\t [");
    for (w = 0; w < barLengthBar; w++) {
        fflush(stdout); // Pastikan output segera ditampilkan
        printf(">");    // Menambahkan karakter ke loading bar
        usleep(duration * 900); // Jeda dalam milidetik
    }
    printf("]\n\n");
    system("cls"); //ini buat ngilangin void atau definisi loading barnya, setelah selesai bakal langsung ilang
    }

    void selamatBarAwal(int sduration){
    int d;
    int barLengthSlmt = 50;
    printf("\n\n\n\n\n\n\n\t\t\t\t<");
    for (d = 0;d < barLengthSlmt; d++){
        fflush(stdout);
        printf("=");
        usleep(sduration * 1300);
    }
    printf(">\n");
    }

    void selamatBarAkhir(int dduration){
    int y;
    int barLengthSLMT = 50;
    printf("\n\t\t\t\t<");
    for(y = 0; y < barLengthSLMT; y++){
        fflush(stdout);
        printf("=");
        usleep(dduration * 1300);
    }
    printf(">\n");
    }


int main_loading(){
    system("color 17");
    loadingBar(50); // 50 ms per unit
    selamatBarAwal(50);
    //BUAT UNTUK SELAMAT DATANG
    const char *selamat = "SELAMAT DATANG DI TUGAS RANCANG\n";
    int screenWidthWelcome = 90;
    int screenHeightWelcome = 5;
    int textLengthWelcome = strlen(selamat);
    int horizontalPaddingWelcome = (screenWidthWelcome - screenHeightWelcome)/2;
    int verticalPaddingWelcome = screenHeightWelcome/2;

    for (int o = 0; o < verticalPaddingWelcome; o++) {
        printf("\n");
    }

    // Cetak spasi untuk memposisikan teks di tengah horizontal
    for (int o = 0; o < horizontalPaddingWelcome; o++) {
        printf(" ");
    }
    printf("%s\n", selamat);
    selamatBarAkhir(50);


    //INI UNTUK INFO LOGIN
    const char *login = " SILAHKAN lOGIN TERLEBIH DAHULU\n";
    int screenWidthLogin = 90;
    int screenHeightLogin = 5;
    int textLengthLogin = strlen(login);
    int horizontalPaddingLogin = (screenWidthLogin - screenHeightLogin)/2;
    int verticalPaddingLogin = screenHeightLogin/2;

    for (int l = 0; l < verticalPaddingLogin; l++) {
        printf("\n");
    }

    // Cetak spasi untuk memposisikan teks di tengah horizontal
    for (int l = 0; l < horizontalPaddingLogin; l++) {
        printf(" ");
    }

    printf("%s\n", login);

    char username[20];
    char password[20];
    char ch;
    int q = 0;

    // Username dan password yang sudah ditentukan
    char correctUsername[] = "admin";
    char correctPassword[] = "123";

    // Minta input dari pengguna
    printf("\t\t\t\t\t\tusername: ");
    scanf("%s", username);

    printf("\t\t\t\t\t\tpassword: ");
    while(1){
        ch = getch();  // Membaca karakter tanpa menampilkan di layar
        // Periksa jika 'Enter' ditekan
        if (ch == '\r') {
            password[q] = '\0'; // Akhiri string
            break;
        } else if (ch == '\b') { // Jika 'Backspace' ditekan
            if (q > 0) {
                q--;
                printf("\b \b"); // Hapus karakter terakhir di layar
            }
        } else {
            password[q++] = ch;
            printf("*"); // Tampilkan '' di layar
        }
    }

    // Cek apakah username dan password cocok
    if (strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) {
        printf("\n\t\t\t\t\t\tLogin berhasil!\n");
    } else {
        printf("\n\t\t\t\t\t   username atau password salah.\n");
        printf("\n\t\t\t\t     TEKAN TOMBOL APA SAJA UNTUK LOGIN KEMBALI\n");
        getch();
        system("cls"); //menghilangkan program
        main_loading(); //kembali memanggil dari awal karena mensummon int main
    }
    int bintang, spasi, keluar; // INI LOADING
    int i;
    int barLength = 4;

    const char *text = "Loading";
    int screenWidth = 110;  // Lebar layar atau konsol
    int screenHeight = 15;
    int textLength = strlen(text);
    int horizontalPadding = (screenWidth - textLength) / 2;
    int verticalPadding = screenHeight / 2;

    // Tambahkan spasi di depan untuk membuat teks berada di tengah
    for (int i = 0; i < verticalPadding; i++) {
        printf("\n");
    }
    for(int i=0;i<horizontalPadding;i++){
        printf(" ");
    }
    printf("%s", text);

    for(i=0;i <= barLength;i++){
        printf(".");
        _beep (1000, 500);
        fflush(stdout);
        usleep(1000000);
    }
    // Memberikan spasi di awal output
    for(spasi = 0; spasi < 5; spasi++){
        printf(" ");
    }
    //cihuy();
return 0;
}
