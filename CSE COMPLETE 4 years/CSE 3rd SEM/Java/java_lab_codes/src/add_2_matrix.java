import java.util.Scanner;
public class add_2_matrix {
    public static void main(String[] args) {
        if(args.length != 1){
            System.out.println("Please Provide the value of N: ");
            return;
        }
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(args[0]);
        int[][] matrix1 = new int[n][n];
        int[][] matrix2 = new int[n][n];
        int[][] result = new int[n][n];

        System.out.println("Enter ele for matrix 1: ");
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix1[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter ele for matrix 2: ");
        for(int i=0; i<n; i++) {
            for (int j = 0; j < n; j++) {
                matrix2[i][j] = sc.nextInt();
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        System.out.println("The result after sum is : ");
        for(int i=0; i<n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(result[i][j]+" ");
            }
            System.out.println();
        }
        sc.close();
    }
}
