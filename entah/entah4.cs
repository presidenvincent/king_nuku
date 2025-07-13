using System;
using System.Collections.Generic;

class Kamus
{
    public string Kata { get; set; }
    public string Arti { get; set; }
}

class Program
{
    static void CariKata(List<Kamus> kamus, string input)
    {
        bool ditemukan = false;

        foreach (var entri in kamus)
        {
            if (entri.Kata.Equals(input, StringComparison.OrdinalIgnoreCase))
            {
                Console.WriteLine($"Arti kata '{input}': {entri.Arti}");
                ditemukan = true;
                break;
            }
        }

        if (!ditemukan)
        {
            Console.WriteLine($"Maaf, kata '{input}' seng ada dalam kamus.");
        }
    }

    static void Main()
    {
        var kamus = new List<Kamus>
        {
            new Kamus { Kata = "sagu", Arti = "Bahan makanan pokok yang berasal dari pohon rumbia" },
            new Kamus { Kata = "sinole", Arti = "Makanan tradisional dari sagu dan kelapa parut" },
            new Kamus { Kata = "beta", Arti = "Saya (dialek Maluku)" },
            new Kamus { Kata = "ale", Arti = "Kamu (dialek Maluku)" },
            new Kamus { Kata = "cungkel", Arti = "Nama fungsi lucu di kode 😄" },
            new Kamus { Kata = "informatika", Arti = "Bidang ilmu yang mempelajari pengolahan informasi secara digital" },
            new Kamus { Kata = "pemrograman", Arti = "Proses menulis instruksi untuk komputer" },
            new Kamus { Kata = "loop", Arti = "Perulangan dalam program" },
            new Kamus { Kata = "array", Arti = "Kumpulan data dengan tipe yang sama" },
            new Kamus { Kata = "fungsi", Arti = "Blok kode yang melakukan tugas tertentu" }
        };

        Console.WriteLine("=== Kamus Mini (C#) ===");
        Console.WriteLine("Ketik 'keluar' untuk mengakhiri.\n");

        while (true)
        {
            Console.Write("Kata: ");
            string input = Console.ReadLine();

            if (input.ToLower() == "keluar")
            {
                Console.WriteLine("Dankje su pake kamus ini!");
                break;
            }

            CariKata(kamus, input);
            Console.WriteLine(); // spasi baris
        }
    }
}
