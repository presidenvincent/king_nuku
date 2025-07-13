public class Array2DExample {
    public static void main(String[] args) {
        // Deklarasi dan inisialisasi array 2 dimensi
        int[][] nilaiMahasiswa = {
            {85, 90, 88}, // Nilai mahasiswa 1 (Matematika, Fisika, Kimia)
            {78, 82, 80}, // Nilai mahasiswa 2
            {92, 87, 95}, // Nilai mahasiswa 3
            {70, 75, 73}  // Nilai mahasiswa 4
        };

        // Array untuk nama mahasiswa
        String[] namaMahasiswa = {"Ali", "Budi", "Cici", "Dedi"};
        String[] mataPelajaran = {"Matematika", "Fisika", "Kimia"};

        // Menampilkan isi array 2 dimensi
        System.out.println("Daftar Nilai Mahasiswa:");
        System.out.println("-----------------------");
        System.out.printf("%-10s", "Nama");
        for (String matpel : mataPelajaran) {
            System.out.printf("%-12s", matpel);
        }
        System.out.println();

        for (int i = 0; i < nilaiMahasiswa.length; i++) {
            System.out.printf("%-10s", namaMahasiswa[i]);
            for (int j = 0; j < nilaiMahasiswa[i].length; j++) {
                System.out.printf("%-12d", nilaiMahasiswa[i][j]);
            }
            System.out.println();
        }

        // Menghitung rata-rata nilai per mahasiswa
        System.out.println("\nRata-rata Nilai per Mahasiswa:");
        System.out.println("-----------------------------");
        for (int i = 0; i < nilaiMahasiswa.length; i++) {
            double total = 0;
            for (int j = 0; j < nilaiMahasiswa[i].length; j++) {
                total += nilaiMahasiswa[i][j];
            }
            double rataRata = total / nilaiMahasiswa[i].length;
            System.out.printf("Rata-rata %s: %.2f\n", namaMahasiswa[i], rataRata);
        }
    }
}