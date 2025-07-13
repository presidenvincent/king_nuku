#include <stdio.h>

// Fungsi ucapan kasih
void tacungkel()
{
    printf("menurut se?\n");
    printf("beta sayang se\n");
}

// Fungsi tambahan
void kasihTau()
{
    printf("Jang lupa makan dulu baru coding\n");
}

void salam()
{
    printf("Halo e! Selamat datang di program cungkel!\n");
}

void pamit()
{
    printf("Beta pamit dolo e, sampe jumpa lai!\n");
}

void hias()
{
    printf("===============================\n");
}

void menu()
{
    hias();
    printf("         MENU UTAMA\n");
    hias();
    printf("1. Perulangan tacungkel 10x\n");
    printf("2. Perulangan custom\n");
    printf("3. Kasih tau\n");
    printf("4. Cetak bintang\n");
    printf("5. Tampilkan bilangan genap 1-20\n");
    printf("6. Tampilkan bilangan ganjil 1-20\n");
    printf("7. Tampilkan angka mundur dari 10\n");
    printf("8. Tampilkan nama 5x\n");
    printf("9. Ulang menu ini\n");
    printf("10. Keluar\n");
    hias();
    printf("Pilihanmu: ");
}

// Fungsi perulangan tacungkel 10x
void tacungkel10()
{
    for (int i = 0; i < 10; i++)
    {
        tacungkel();
    }
}

// Fungsi perulangan tacungkel custom
void tacungkelCustom()
{
    int n;
    printf("Berapa kali beta bilang sayang?: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        tacungkel();
    }
}

// Fungsi cetak bintang
void cetakBintang()
{
    int i, j;
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

// Fungsi bilangan genap
void bilanganGenap()
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 2 == 0)
            printf("%d ", i);
    }
    printf("\n");
}

// Fungsi bilangan ganjil
void bilanganGanjil()
{
    for (int i = 1; i <= 20; i++)
    {
        if (i % 2 != 0)
            printf("%d ", i);
    }
    printf("\n");
}

// Fungsi angka mundur
void angkaMundur()
{
    for (int i = 10; i >= 1; i--)
    {
        printf("%d ", i);
    }
    printf("\n");
}

// Fungsi nama
void cetakNama()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Vincent Danis Lekahena\n");
    }
}

int main()
{
    int pilihan;
    salam();

    while (1)
    {
        menu();
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tacungkel10();
            break;
        case 2:
            tacungkelCustom();
            break;
        case 3:
            kasihTau();
            break;
        case 4:
            cetakBintang();
            break;
        case 5:
            bilanganGenap();
            break;
        case 6:
            bilanganGanjil();
            break;
        case 7:
            angkaMundur();
            break;
        case 8:
            cetakNama();
            break;
        case 9:
            continue;
        case 10:
            pamit();
            return 0;
        default:
            printf("Yaolo, pilih yang bener e!\n");
        }

        printf("\nTekan ENTER untuk lanjut...\n");
        getchar();
        getchar();
    }

    return 0;
}
