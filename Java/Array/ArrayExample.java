public class ArrayExample {
    public static void main(String[] args) {
        // Deklarasi dan inisialisasi array
        String[] namaMahasiswa = {"Ali", "Budi", "Cici", "Dedi"};
        int[] nilaiMahasiswa = {85, 90, 78, 92};
        
        // Menampilkan daftar mahasiswa dan nilai
        System.out.println("Daftar Mahasiswa dan Nilai:");
        System.out.println("--------------------------");
        
        // Menggunakan loop untuk menampilkan isi array
        for (int i = 0; i < namaMahasiswa.length; i++) {
            System.out.println("Nama: " + namaMahasiswa[i] + ", Nilai: " + nilaiMahasiswa[i]);
        }
        
        // Menghitung rata-rata nilai
        double total = 0;
        for (int nilai : nilaiMahasiswa) {
            total += nilai;
        }
        double rataRata = total / nilaiMahasiswa.length;
        
        System.out.println("\nRata-rata nilai: " + rataRata);
        
        // Mencari nilai tertinggi
        int nilaiTertinggi = nilaiMahasiswa[0];
        String topStudent = namaMahasiswa[0];
        
        for (int i = 1; i < nilaiMahasiswa.length; i++) {
            if (nilaiMahasiswa[i] > nilaiTertinggi) {
                nilaiTertinggi = nilaiMahasiswa[i];
                topStudent = namaMahasiswa[i];
            }
        }
        
        System.out.println("Mahasiswa dengan nilai tertinggi: " + topStudent + " (" + nilaiTertinggi + ")");
    }
}