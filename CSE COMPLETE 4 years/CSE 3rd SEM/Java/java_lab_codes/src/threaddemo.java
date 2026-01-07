class Mythread extends Thread{
    Mythread(){
        super("Child Thread");
        System.out.println("Child thread created");
        start();
    }
    public void run(){
        try{
            for(int i=0; i<=5; i++){
                System.out.println("Child Thread "+i);
                sleep(500);
            }
        }catch(InterruptedException e){
            System.out.println("Child Thread Intrupt: "+e);
        }
        System.out.println("Child thread exiting");
    }
}
public class threaddemo {
    public static void main(String[] args){
        new Mythread();
        try{
            for(int i=0; i<=5; i++){
                System.out.println("Main thread "+i);
                Thread.sleep(500);
            }
        }catch (InterruptedException e){
            System.out.println("Main thread Intrupt: "+e);
        }
        System.out.println("Main Thread Exiting");
    }
}
