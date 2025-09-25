public class addition {
    public static void main(String[] args) {
        int[][] matrix1 = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 }

        };
        int[][] matrix2 = {
                { 9, 8, 7 },
                { 6, 5, 4 },
                { 3, 2, 1 }
        };
        int rows = matrix1.length;
        int cols = matrix1[0].length;
        int[][] result = new int[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = matrix1[i][j] = matrix2[i][j];

            }
        }
        System.out.println("Result of matrix addition: ");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.println(result[i][j] + " ");
            }
            System.out.println();
        }

    }
}