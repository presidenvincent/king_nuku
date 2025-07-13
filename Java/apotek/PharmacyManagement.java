import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

class Drug {
    String code;
    String name;
    int stock;
    double price;

    public Drug(String code, String name, int stock, double price) {
        this.code = code;
        this.name = name;
        this.stock = stock;
        this.price = price;
    }
}

class PurchaseHistory {
    String code;
    String name;
    int quantity;
    double totalCost;
    String timestamp;

    public PurchaseHistory(String code, String name, int quantity, double totalCost, String timestamp) {
        this.code = code;
        this.name = name;
        this.quantity = quantity;
        this.totalCost = totalCost;
        this.timestamp = timestamp;
    }
}

public class PharmacyManagement {
    // Fungsi untuk menukar dua elemen Drug
    static void swap(Drug[] arr, int i, int j) {
        Drug temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // Fungsi bubble sort berdasarkan harga
    static void bubbleSort(Drug[] arr, boolean ascending) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (ascending) {
                    if (arr[j].price > arr[j + 1].price) {
                        swap(arr, j, j + 1);
                    }
                } else {
                    if (arr[j].price < arr[j + 1].price) {
                        swap(arr, j, j + 1);
                    }
                }
            }
        }
    }

    // Fungsi insertion sort berdasarkan harga
    static void insertionSort(Drug[] arr, boolean ascending) {
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            Drug key = arr[i];
            int j = i - 1;
            if (ascending) {
                while (j >= 0 && arr[j].price > key.price) {
                    arr[j + 1] = arr[j];
                    j--;
                }
            } else {
                while (j >= 0 && arr[j].price < key.price) {
                    arr[j + 1] = arr[j];
                    j--;
                }
            }
            arr[j + 1] = key;
        }
    }

    // Fungsi untuk menampilkan data obat
    static void displayDrugs(Drug[] drugs) {
        if (drugs.length == 0) {
            System.out.println("\nData obat kosong.");
            return;
        }
        System.out.println("\nDaftar Obat:");
        System.out.printf("%-5s | %-10s | %-22s | %-6s | %-8s\n", "No.", "Kode Obat", "Nama Obat", "Stok", "Harga");
        System.out.println("-----|------------|------------------------|--------|----------");
        for (int i = 0; i < drugs.length; i++) {
            System.out.printf("%-5d | %-10s | %-22s | %-6d | %.2f\n", 
                i + 1, drugs[i].code, drugs[i].name, drugs[i].stock, drugs[i].price);
        }
    }

    // Fungsi untuk menampilkan histori pembelian
    static void displayHistory(ArrayList<PurchaseHistory> history) {
        if (history.isEmpty()) {
            System.out.println("\nBelum ada histori pembelian.");
            return;
        }
        System.out.println("\nHistori Pembelian:");
        System.out.printf("%-5s | %-10s | %-22s | %-8s | %-12s | %-19s\n", 
            "No.", "Kode Obat", "Nama Obat", "Jumlah", "Total Biaya", "Waktu");
        System.out.println("-----|------------|------------------------|----------|--------------|---------------------");
        for (int i = 0; i < history.size(); i++) {
            PurchaseHistory h = history.get(i);
            System.out.printf("%-5d | %-10s | %-22s | %-8d | %-12.2f | %s\n", 
                i + 1, h.code, h.name, h.quantity, h.totalCost, h.timestamp);
        }
    }

    // Fungsi untuk mendapatkan waktu saat ini sebagai string
    static String getCurrentTime() {
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return now.format(formatter);
    }

    // Fungsi untuk membeli obat
    static void buyDrug(Drug[] drugs, ArrayList<PurchaseHistory> history, Scanner scanner) {
        System.out.println("\n=== Beli Obat ===");
        displayDrugs(drugs);

        System.out.print("\nMasukkan Kode Obat yang ingin dibeli: ");
        String code = scanner.nextLine().trim();

        System.out.print("Masukkan jumlah yang ingin dibeli: ");
        int quantity;
        try {
            quantity = scanner.nextInt();
        } catch (Exception e) {
            System.out.println("Jumlah tidak valid! Harus angka.");
            scanner.nextLine(); // Membersihkan buffer
            return;
        }

        System.out.print("Masukkan jumlah uang Anda: ");
        double money;
        try {
            money = scanner.nextDouble();
        } catch (Exception e) {
            System.out.println("Jumlah uang tidak valid! Harus angka.");
            scanner.nextLine(); // Membersihkan buffer
            return;
        }
        scanner.nextLine(); // Membersihkan buffer

        // Cari obat berdasarkan kode
        int found = -1;
        for (int i = 0; i < drugs.length; i++) {
            if (drugs[i].code.equals(code)) {
                found = i;
                break;
            }
        }

        // Validasi pembelian
        if (found == -1) {
            System.out.println("Kode obat tidak ditemukan!");
            return;
        }
        if (quantity <= 0) {
            System.out.println("Jumlah pembelian tidak valid!");
            return;
        }
        if (quantity > drugs[found].stock) {
            System.out.println("Stok tidak cukup! Stok tersedia: " + drugs[found].stock);
            return;
        }
        double totalCost = quantity * drugs[found].price;
        if (money < totalCost) {
            System.out.printf("Uang tidak cukup! Total biaya: %.2f, Uang Anda: %.2f\n", totalCost, money);
            return;
        }

        // Proses pembelian
        drugs[found].stock -= quantity;
        history.add(new PurchaseHistory(drugs[found].code, drugs[found].name, quantity, totalCost, getCurrentTime()));

        // Tampilkan rincian pembelian
        System.out.println("\nPembelian berhasil!");
        System.out.println("Obat: " + drugs[found].name);
        System.out.println("Jumlah: " + quantity);
        System.out.printf("Total biaya: %.2f\n", totalCost);
        System.out.printf("Kembalian: %.2f\n", money - totalCost);
        System.out.println("Stok tersisa: " + drugs[found].stock);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Inisialisasi data obat awal (5 obat)
        Drug[] drugs = {
            new Drug("OBT001", "Paracetamol", 100, 5000.00),
            new Drug("OBT002", "Amoxicillin", 50, 15000.00),
            new Drug("OBT003", "Ibuprofen", 75, 8000.00),
            new Drug("OBT004", "Cetirizine", 60, 12000.00),
            new Drug("OBT005", "Omeprazole", 40, 20000.00)
        };

        // Inisialisasi histori pembelian
        ArrayList<PurchaseHistory> history = new ArrayList<>();

        int choice, sortChoice, orderChoice;
        char continueLoop;

        do {
            // Menu utama
            System.out.println("\n=== Sistem Manajemen Apotek ===");
            System.out.println("1. Beli Obat");
            System.out.println("2. Urutkan Data Obat");
            System.out.println("3. Tampilkan Data Obat");
            System.out.println("4. Tampilkan Histori Pembelian");
            System.out.println("5. Keluar");
            System.out.print("Masukkan pilihan (1-5): ");

            try {
                choice = scanner.nextInt();
                scanner.nextLine(); // Membersihkan buffer

                switch (choice) {
                    case 1:
                        buyDrug(drugs, history, scanner);
                        break;

                    case 2:
                        if (drugs.length == 0) {
                            System.out.println("Data obat kosong!");
                            break;
                        }
                        System.out.println("\nPilih metode pengurutan (berdasarkan harga):");
                        System.out.println("1. Bubble Sort");
                        System.out.println("2. Insertion Sort");
                        System.out.print("Masukkan pilihan (1-2): ");
                        sortChoice = scanner.nextInt();
                        scanner.nextLine(); // Membersihkan buffer

                        System.out.println("Pilih urutan:");
                        System.out.println("1. Ascending");
                        System.out.println("2. Descending");
                        System.out.print("Masukkan pilihan (1-2): ");
                        orderChoice = scanner.nextInt();
                        scanner.nextLine(); // Membersihkan buffer

                        // Tampilkan data sebelum sorting
                        System.out.println("\nSebelum pengurutan:");
                        displayDrugs(drugs);

                        // Proses pengurutan
                        switch (sortChoice) {
                            case 1:
                                bubbleSort(drugs, orderChoice == 1);
                                System.out.println("\nSetelah pengurutan dengan Bubble Sort (berdasarkan harga, " + 
                                    (orderChoice == 1 ? "ascending" : "descending") + "):");
                                displayDrugs(drugs);
                                break;
                            case 2:
                                insertionSort(drugs, orderChoice == 1);
                                System.out.println("\nSetelah pengurutan dengan Insertion Sort (berdasarkan harga, " + 
                                    (orderChoice == 1 ? "ascending" : "descending") + "):");
                                displayDrugs(drugs);
                                break;
                            default:
                                System.out.println("Pilihan tidak valid!");
                                break;
                        }
                        break;

                    case 3:
                        displayDrugs(drugs);
                        break;

                    case 4:
                        displayHistory(history);
                        break;

                    case 5:
                        System.out.println("Program selesai.");
                        scanner.close();
                        return;

                    default:
                        System.out.println("Pilihan tidak valid!");
                        break;
                }
            } catch (Exception e) {
                System.out.println("Pilihan tidak valid! Masukkan angka 1-5.");
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