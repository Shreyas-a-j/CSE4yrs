import java.util.Stack;
import java.util.Scanner;
public class stacks {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        Scanner sc = new Scanner(System.in);
        final int max = 10;
        System.out.println("Enter how many ele u want to push? MAX 10 elements: ");
        int n = sc.nextInt();
        for(int i=0; i<n; i++){
            if(i>max-1){
                System.out.println("Stack overflow");
                break;
            }else {
                System.out.println("Enter the ele to push: ");
                int val = sc.nextInt();
                s.push(val);
            }
        }
        System.out.println("Enter how many ele u want to pop?");
        int m = sc.nextInt();
        for(int i=0; i<m; i++){
            if(s.isEmpty()){
                System.out.println("Stack underflow");
            }else {
                s.pop();
            }
        }
        System.out.println(s);
        System.out.println("Do u want to peek? 1 = yes, 0 = no");
        int a = sc.nextInt();
        if(a == 1){
            System.out.println(s.peek());
        }else{
            return;
        }
    }
}
