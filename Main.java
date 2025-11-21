class EvenNumbers extends Thread {
    @Override
    public void run() {
        System.out.println("Thread1: Even numbers from 1 to 20 :");
        for (int i = 1; i <= 20; i++) {
            if (i % 2 == 0) {
                System.out.print(i + " ");
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    System.out.println("Thread interrupted: " + e.getMessage());
                }
            }
        }
        System.out.println();
    }
}

class OddNumbers extends Thread {
    @Override
    public void run() {
        System.out.println("Thread2: Odd numbers 1 to 20 :");
        for (int i = 1; i <= 20; i++) {
            if (i % 2 != 0) {
                System.out.print(i + " ");
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    System.out.println("Thread interrupted: " + e.getMessage());
                }
            }
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        EvenNumbers evenThread = new EvenNumbers();
        OddNumbers oddThread = new OddNumbers();

        evenThread.start();
        oddThread.start();
    }
}