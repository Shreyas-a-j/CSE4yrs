import java.util.Scanner;
public class hangling {
    public static int divide(int a, int b){
        return a/b;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        try{
            System.out.println("Enter a and b: ");
            int a = sc.nextInt();
            int b = sc.nextInt();
            int result = divide(a,b);
            System.out.println(result);
        } catch (Exception e){
            System.out.println("Exception caught: "+e.getMessage());
        }
        sc.close();
    }
}
