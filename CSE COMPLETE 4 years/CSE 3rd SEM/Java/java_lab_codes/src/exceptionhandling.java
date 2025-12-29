import java.util.Scanner;
class DivisionByZeroException extends Exception{
    public DivisionByZeroException(String message){
        super(message);
    }
}
public class exceptionhandling {
    static int divide(int a, int b) throws DivisionByZeroException {
        if(b==0){
            throw new DivisionByZeroException("Error Division by zero is not allowed");
        } return a/b;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        try{
            System.out.println("Enter Numerator: ");
            int a = sc.nextInt();
            System.out.println("Enter Denominator: ");
            int b = sc.nextInt();
            int result = divide(a,b);
        } catch (DivisionByZeroException e){
            System.out.println("Exception caught: "+e.getMessage());
        }
        finally{
            System.out.println("Program execution completed (from finally key block)");
            sc.close();
        }
    }
}
