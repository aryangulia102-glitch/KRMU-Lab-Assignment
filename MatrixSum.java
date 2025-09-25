public class MatrixSum {
    public static void main(String[] args) {
        int[][] matrix = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 }
        };
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[] rowSums = new int[rows];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rowSums[i] += matrix[i][j];
            }
        }
        int[] colSums = new int[cols];

        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                colSums[j] += matrix[i][j];
            }
        }

        System.out.println("Row Sums:");
        for (int i = 0; i < rows; i++) {
            System.out.println("Row " + (i + 1) + ": " + rowSums[i]);
        }

        System.out.println("\nColmn Sums:");
        for (int j = 0; j < cols; j++) {
            System.out.println("Column " + (j + 1) + ": " + colSums[j]);
        }
    }
}