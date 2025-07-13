import java.io.*;
import java.util.*;

public class TokoHP {
    static class Item {
        int id;
        String name;
        String brand;
        long price;

        Item(int id, String name, String brand, long price) {
            this.id = id;
            this.name = name;
            this.brand = brand;
            this.price = price;
        }
    }

    static final Scanner sc = new Scanner(System.in);
    static final ArrayList<Item> items = new ArrayList<>();
    static final String FILENAME = "items.txt";

    public static void main(String[] args) throws InterruptedException {
        login();
        loadItems();

        while (true) {
            clearScreen();
            System.out.println("\n******************************************");
            System.out.println("*          Kelompok 4 - Toko HP          *");
            System.out.println("******************************************");
            System.out.println("*   Menu :                               *");
            System.out.println("*   1. Tambah Item                       *");
            System.out.println("*   2. Hapus Item                        *");
            System.out.println("*   3. Edit Item                         *");
            System.out.println("*   4. List Item                         *");
            System.out.println("*   5. Sorting Harga (Ascending)         *");
            System.out.println("*   6. Sorting Harga (Descending)        *");
            System.out.println("*   7. Author                            *");
            System.out.println("*   8. Exit                              *");
            System.out.println("******************************************");
            System.out.print("Pilihan: ");
            String choice = sc.nextLine();

            switch (choice) {
                case "1": tambahItem(); break;
                case "2": hapusItem(); break;
                case "3": editItem(); break;
                case "4": listItems(); break;
                case "5": sortItems(true); break;
                case "6": sortItems(false); break;
                case "7": author(); break;
                case "8":
                    System.out.println("Terima kasih telah menggunakan aplikasi Toko HP!");
                    System.exit(0);
                default:
                    System.out.println("Pilihan tidak valid!");
            }
            System.out.println("\nTekan Enter untuk kembali ke menu...");
            sc.nextLine();
        }
    }

    static void login() throws InterruptedException {
        System.out.println("=== Login ===");
        System.out.print("Username: ");
        String username = sc.nextLine();
        System.out.print("Password: ");
        String password = sc.nextLine();

        if (!username.equals("admin") || !password.equals("12345")) {
            System.out.println("Login gagal! Program akan keluar.");
            Thread.sleep(1000);
            System.exit(1);
        }
        System.out.println("Login berhasil!");
        System.out.print("Loading");
        for (int i = 0; i < 3; i++) {
            System.out.print(".");
            Thread.sleep(500);
        }
        Thread.sleep(500);
    }

    static void loadItems() {
        try (BufferedReader br = new BufferedReader(new FileReader(FILENAME))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\\|");
                int id = Integer.parseInt(parts[0].trim());
                String name = parts[1].trim();
                String brand = parts[2].trim();
                long price = Long.parseLong(parts[3].trim());
                items.add(new Item(id, name, brand, price));
            }
        } catch (IOException ignored) {
        }
    }

    static void saveItems() {
        try (PrintWriter pw = new PrintWriter(new FileWriter(FILENAME))) {
            for (Item item : items) {
                pw.printf("%d|%s|%s|%d\n", item.id, item.name, item.brand, item.price);
            }
        } catch (IOException e) {
            System.out.println("Gagal menyimpan data!");
        }
    }

    static void tambahItem() {
        System.out.println("=== Tambah Item Baru ===");
        int id = (items.size() > 0) ? items.get(items.size() - 1).id + 1 : 1;
        System.out.print("Nama HP: ");
        String name = sc.nextLine();
        System.out.print("Brand HP: ");
        String brand = sc.nextLine();
        System.out.print("Harga: ");
        long price = Long.parseLong(sc.nextLine());

        items.add(new Item(id, name, brand, price));
        saveItems();
        System.out.println("Item berhasil ditambahkan!");
    }

    static void hapusItem() {
        System.out.println("=== Hapus Item ===");
        listItems();
        System.out.print("\nMasukkan ID item yang akan dihapus: ");
        int id = Integer.parseInt(sc.nextLine());
        boolean found = false;

        Iterator<Item> it = items.iterator();
        while (it.hasNext()) {
            Item item = it.next();
            if (item.id == id) {
                it.remove();
                found = true;
                break;
            }
        }

        if (found) {
            saveItems();
            System.out.println("Item berhasil dihapus!");
        } else {
            System.out.println("Item dengan ID " + id + " tidak ditemukan!");
        }
    }

    static void editItem() {
        System.out.println("=== Edit Item ===");
        listItems();
        System.out.print("\nMasukkan ID item yang akan diedit: ");
        int id = Integer.parseInt(sc.nextLine());

        for (Item item : items) {
            if (item.id == id) {
                System.out.printf("Nama [%s]: ", item.name);
                String name = sc.nextLine();
                if (!name.isEmpty()) item.name = name;

                System.out.printf("Brand [%s]: ", item.brand);
                String brand = sc.nextLine();
                if (!brand.isEmpty()) item.brand = brand;

                System.out.printf("Harga [%d]: ", item.price);
                String hargaStr = sc.nextLine();
                if (!hargaStr.isEmpty()) item.price = Long.parseLong(hargaStr);

                saveItems();
                System.out.println("Item berhasil diedit!");
                return;
            }
        }
        System.out.println("Item dengan ID " + id + " tidak ditemukan!");
    }

    static void listItems() {
        System.out.println("=== Daftar Item ===");
        if (items.isEmpty()) {
            System.out.println("Belum ada item!");
            return;
        }
        System.out.printf("%-5s %-20s %-20s %-10s\n", "ID", "Nama", "Brand", "Harga");
        System.out.println("--------------------------------------------------------------");
        for (Item item : items) {
            System.out.printf("%-5d %-20s %-20s %-10d\n", item.id, item.name, item.brand, item.price);
        }
    }

    static void sortItems(boolean ascending) {
        items.sort((a, b) -> ascending ?
                Long.compare(a.price, b.price) :
                Long.compare(b.price, a.price));
        saveItems();
        System.out.println("Item berhasil diurutkan!");
        listItems();
    }

    static void creator() throws InterruptedException {
        System.out.println("CREATOR");
        printCreator("Alexander Kevin Setiawan", "672024018");
        printCreator("Vincent Danis Lekahena", "6720240224");
        printCreator("Erlando Imanuel Shidarta", "672024027");
        printCreator("Geofaldy Morits Kolintama", "672024112");
    }

    static void printCreator(String name, String nim) throws InterruptedException {
        System.out.printf("NAMA: %s\nNIM : %s\n\n", name, nim);
        Thread.sleep(1000);
    }

    static void author() throws InterruptedException {
        while (true) {
            clearScreen();
            creator();
            System.out.print("Ketik 'u' untuk mengulang atau 'x' untuk kembali ke menu: ");
            String choice = sc.nextLine();
            if (choice.equalsIgnoreCase("x")) break;
        }
    }

    static void clearScreen() {
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                System.out.print("\033[H\033[2J");
                System.out.flush();
            }
        } catch (Exception ignored) {}
    }
}
