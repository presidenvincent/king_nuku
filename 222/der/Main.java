import java.util.Scanner;

public class Calculator {
    // Fungsi untuk kalkulator biasa
    static void basicCalculator(Scanner scanner) {
        System.out.println("\n=== Kalkulator Biasa ===");
        System.out.print("Masukkan operasi (contoh: 5 + 3): ");

        try {
            double num1 = scanner.nextDouble();
            char operator = scanner.next().charAt(0);
            double num2 = scanner.nextDouble();
            double result = 0;
            boolean valid = true;

            switch (operator) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        System.out.println("Error: Pembagian dengan nol tidak diperbolehkan!");
                        valid = false;
                    } else {
                        result = num1 / num2;
                    }
                    break;
                default:
                    System.out.println("Operator tidak valid! Gunakan +, -, *, atau /.");
                    valid = false;
                    break;
            }

            if (valid) {
                System.out.printf("Hasil: %.2f %c %.2f = %.2f\n", num1, operator, num2, result);
            }
        } catch (Exception e) {
            System.out.println("Input tidak valid! Gunakan format: angka operator angka (contoh: 5 + 3).");
            scanner.nextLine(); // Membersihkan buffer
        }
    }

    // Fungsi untuk kalkulator usia
    static void ageCalculator(Scanner scanner) {
        int currentDay = 13, currentMonth = 7, currentYear = 2025; // Tanggal saat ini
        System.out.println("\n=== Kalkulator Usia ===");
        System.out.print("Masukkan tanggal lahir (DD MM YYYY, contoh: 15 5 1990): ");

        try {
            int birthDay = scanner.nextInt();
            int birthMonth = scanner.nextInt();
            int birthYear = scanner.nextInt();

            // Validasi tanggal lahir
            if (birthYear > currentYear ||
                (birthYear == currentYear && birthMonth > currentMonth) ||
                (birthYear == currentYear && birthMonth == currentMonth && birthDay > currentDay)) {
                System.out.println("Tanggal lahir tidak valid! Harus sebelum 13 Juli 2025.");
                return;
            }
            if (birthDay < 1 || birthDay > 31 || birthMonth < 1 || birthMonth > 12 || birthYear < 1900) {
                System.out.println("Tanggal lahir tidak valid! Gunakan format DD (1-31), MM (1-12), YYYY (>=1900).");
                return;
            }

            // Hitung usia (sederhana, berdasarkan tahun dan bulan)
            int age = currentYear - birthYear;
            if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
                age--; // Kurangi usia jika ulang tahun belum lewat
            }

            System.out.println("Usia Anda: " + age + " tahun");
        } catch (Exception e) {
            System.out.println("Input tidak valid! Gunakan format: DD MM YYYY (contoh: 15 5 1990).");
            scanner.nextLine(); // Membersihkan buffer
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice;
        char continueLoop;

        do {
            // Menu utama
            System.out.println("\n=== Program Kalkulator ===");
            System.out.println("1. Kalkulator Biasa");
            System.out.println("2. Kalkulator Usia");
            System.out.println("3. Keluar");
            System.out.print("Masukkan pilihan (1-3): ");

            try {
                choice = scanner.nextInt();
                scanner.nextLine(); // Membersihkan buffer

                switch (choice) {
                    case 1:
                        basicCalculator(scanner);
                        break;

                    case 2:
                        ageCalculator(scanner);
                        break;

                    case 3:
                        System.out.println("Program selesai.");
                        scanner.close();
                        return;

                    default:
                        System.out.println("Pilihan tidak valid! Gunakan 1, 2, atau 3.");
                        break;
                }
            } catch (Exception e) {
                System.out.println("Pilihan tidak valid! Masukkan angka 1, 2, atau 3.");
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
