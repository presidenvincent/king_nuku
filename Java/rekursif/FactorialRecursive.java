package rekursif;

public class FactorialRecursive {
    public static void main(String[] args) {
        int n = 5;
        System.out.println("Faktorial dari " + n + " adalah: " + factorial(n));
    }

    // Metode rekursif untuk faktorial
    public static long factorial(int n) {
        // Base case
        if (n == 0 || n == 1) {
            return 1;
        }
        // Recursive case
        return n * factorial(n - 1);
    }
}