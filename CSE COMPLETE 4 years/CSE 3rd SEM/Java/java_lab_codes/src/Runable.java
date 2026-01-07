class mythread implements Runnable{
    public void run(){
        try {
            System.out.println("Thread: "+Thread.currentThread().getName() + " is running");
            Thread.sleep(500);
            System.out.println("Thread: "+Thread.currentThread().getName() + " is resumed");
        }catch (InterruptedException e){
            System.out.println("Intrupt: "+ e);
        }
    }
}
public class Runable {
    public static void main(String[] args) {
        mythread o = new mythread();
        mythread o1 = new mythread();
        mythread o2 = new mythread();
        Thread t1 = new Thread(o,"t1");
        Thread t2 = new Thread(o1, "t2");
        Thread t3 = new Thread(o2, "t3");
        t1.start();
        t2.start();
        t3.start();
    }
}
