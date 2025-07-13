#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk entri kamus
struct Kamus {
    string kata;
    string arti;
};

// Fungsi untuk mencari arti kata
void cariKata(const vector<Kamus>& kamus, const string& input) {
    for (const auto& entri : kamus) {
        if (entri.kata == input) {
            cout << "Arti kata '" << input << "': " << entri.arti << endl;
            return;
        }
    }
    cout << "Maaf, kata '" << input << "' seng ada dalam kamus.\n";
}

int main() {
    // Daftar kata dalam kamus
    vector<Kamus> kamus = {
        {"sagu", "Bahan makanan pokok yang berasal dari pohon rumbia"},
        {"sinole", "Makanan tradisional dari sagu dan kelapa parut"},
        {"beta", "Saya (dialek Maluku)"},
        {"ale", "Kamu (dialek Maluku)"},
        {"cungkel", "Nama fungsi lucu di kode 😄"},
        {"informatika", "Bidang ilmu yang mempelajari pengolahan informasi secara digital"},
        {"pemrograman", "Proses menulis instruksi untuk komputer"},
        {"loop", "Perulangan dalam program"},
        {"array", "Kumpulan data dengan tipe yang sama"},
        {"fungsi", "Blok kode yang melakukan tugas tertentu"}
    };

    string input;

    cout << "=== Kamus Mini (C++) ===" << endl;
    cout << "Masukkan kata (ketik 'keluar' untuk berhenti):" << endl;

    while (true) {
        cout << "\nKata: ";
        getline(cin, input);

        if (input == "keluar") {
            cout << "Dankje su pake kamus ini!" << endl;
            break;
        }

        cariKata(kamus, input);
    }

    return 0;
}
