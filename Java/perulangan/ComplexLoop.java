import java.util.ArrayList;
import java.util.Scanner;

public class ComplexLoop {
    // Fungsi untuk mencetak pola belah ketupat berlubang
    static void printDiamond(int size) {
        System.out.println("\n=== Pola Belah Ketupat Berlubang ===");
        if (size < 3) {
            System.out.println("Ukuran minimal 3 untuk pola yang jelas.");
            return;
        }

        // Bagian atas belah ketupat
        for (int i = 0; i < size; i++) {
            // Cetak spasi awal
            for (int j = 0; j < size - i - 1; j++) {
                System.out.print("  ");
            }
            // Cetak bintang dan spasi dalam
            for (int j = 0; j < 2 * i + 1; j++) {
                if (j == 0 || j == 2 * i) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }

        // Bagian bawah belah ketupat
        for (int i = size - 2; i >= 0; i--) {
            // Cetak spasi awal
            for (int j = 0; j < size - i - 1; j++) {
                System.out.print("  ");
            }
            // Cetak bintang dan spasi dalam
            for (int j = 0; j < 2 * i + 1; j++) {
                if (j == 0 || j == 2 * i) {
                    System.out.print("* ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }

    // Fungsi untuk menghasilkan deret Fibonacci
    static ArrayList<Long> generateFibonacci(int n) {
        ArrayList<Long> fib = new ArrayList<>();
        fib.add(0L); // Fibonacci suku pertama
        if (n == 1) return fib;
        fib.add(1L); // Fibonacci suku kedua
        for (int i = 2; i < n; i++) {
            fib.add(fib.get(i - 1) + fib.get(i - 2));
        }
        return fib;
    }

    // Fungsi untuk mencetak matriks spiral dari deret Fibonacci
    static void printFibonacciSpiral(int n) {
        System.out.println("\n=== Deret Fibonacci dalam Matriks Spiral ===");
        if (n < 1) {
            System.out.println("Jumlah suku minimal 1.");
            return;
        }

        ArrayList<Long> fib = generateFibonacci(n);
        System.out.println("Deret Fibonacci (" + n + " suku):");
        for (long num : fib) {
            System.out.print(num + " ");
        }
        System.out.println();

        // Tentukan ukuran matriks (persegi terdekat yang muat n elemen)
        int size = (int) Math.ceil(Math.sqrt(n));
        long[][] matrix = new long[size][size];
        int top = 0, bottom = size - 1, left = 0, right = size - 1;
        int index = 0;

        // Isi matriks secara spiral
        while (top <= bottom && left <= right && index < n) {
            // Isi baris atas
            for (int i = left; i <= right && index < n; i++) {
                matrix[top][i] = fib.get(index++);
            }
            top++;
            // Isi kolom kanan
            for (int i = top; i <= bottom && index < n; i++) {
                matrix[i][right] = fib.get(index++);
            }
            right--;
            // Isi baris bawah
            for (int i = right; i >= left && index < n; i--) {
                matrix[bottom][i] = fib.get(index++);
            }
            bottom--;
            // Isi kolom kiri
            for (int i = bottom; i >= top && index < n; i--) {
                matrix[i][left] = fib.get(index++);
            }
            left++;
        }

        // Cetak matriks
        System.out.println("Matriks Spiral Fibonacci:");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                System.out.printf("%-10d", matrix[i][j]);
            }
            System.out.println();
        }
    }

    // Fungsi untuk menghasilkan permutasi string
    static void permute(String str, int left, int right, ArrayList<String> results) {
        if (left == right) {
            results.add(str);
        } else {
            for (int i = left; i <= right; i++) {
                str = swapChars(str, left, i);
                permute(str, left + 1, right, results);
                str = swapChars(str, left, i); // Swap kembali untuk backtracking
            }
        }
    }

    // Fungsi untuk menukar karakter dalam string
    static String swapChars(String str, int i, int j) {
        char[] charArray = str.toCharArray();
        char temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return new String(charArray);
    }

    // Fungsi untuk mencetak semua permutasi
    static void printPermutations(String input) {
        System.out.println("\n=== Permutasi String ===");
        if (input == null || input.isEmpty()) {
            System.out.println("String tidak boleh kosong.");
            return;
        }
        ArrayList<String> results = new ArrayList<>();
        permute(input, 0, input.length() - 1, results);
        System.out.println("Permutasi dari \"" + input + "\":");
        for (int i = 0; i < results.size(); i++) {
            System.out.println((i + 1) + ". " + results.get(i));
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        char continueLoop;

        do {
            // Menu utama
            System.out.println("\n=== Program Perulangan Kompleks ===");
            System.out.println("1. Pola Belah Ketupat Berlubang");
            System.out.println("2. Deret Fibonacci dalam Matriks Spiral");
            System.out.println("3. Permutasi String");
            System.out.println("4. Keluar");
            System.out.print("Masukkan pilihan (1-4): ");

            try {
                choice = scanner.nextInt();
                scanner.nextLine(); // Membersihkan buffer

                switch (choice) {
                    case 1:
                        System.out.print("Masukkan ukuran sisi belah ketupat (min. 3): ");
                        try {
                            int size = scanner.nextInt();
                            scanner.nextLine(); // Membersihkan buffer
                            printDiamond(size);
                        } catch (Exception e) {
                            System.out.println("Input tidak valid! Masukkan angka.");
                            scanner.nextLine();
                        }
                        break;

                    case 2:
                        System.out.print("Masukkan jumlah suku Fibonacci (min. 1): ");
                        try {
                            int n = scanner.nextInt();
                            scanner.nextLine(); // Membersihkan buffer
                            printFibonacciSpiral(n);
                        } catch (Exception e) {
                            System.out.println("Input tidak valid! Masukkan angka.");
                            scanner.nextLine();
                        }
                        break;

                    case 3:
                        System.out.print("Masukkan string untuk permutasi (contoh: ABC): ");
                        String input = scanner.nextLine().trim();
                        printPermutations(input);
                        break;

                    case 4:
                        System.out.println("Program selesai.");
                        scanner.close();
                        return;

                    default:
                        System.out.println("Pilihan tidak valid! Gunakan 1, 2, 3, atau 4.");
                        break;
                }
            } catch (Exception e) {
                System.out.println("Pilihan tidak valid! Masukkan angka 1-4.");
                scanner.nextLine(); // Membersihkan buffer
            }

            // Tanya apakah ingin melanjutkan
            System.out.print("\nApakah ingin melanjutkan? (y/n): ");
            continueLoop = scanner.next().charAt(0);
            scanner.nextLine(); // Membersihkan buffer
        } while (continueLoop == 'y' || continueLoop == 'Y');

        System.out.println("Program selesai.");
        scanner.close();
    }
}