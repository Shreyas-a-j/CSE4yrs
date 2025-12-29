class outer{
    void display(){
        System.out.println("This is outer class display");
    }
    class inner{
        void display(){
            System.out.println("This is Inner class");
        }
    }
}

public class mainclass {
    public static void main(String[] args) {
        outer o = new outer();
        o.display();
        outer.inner i = o.new inner();
        i.display();
    }
}
