
class MyPoint{
    private int x;
    private int y;

    public MyPoint(){
        this.x = 0;
        this.y = 0;
    }
    public MyPoint(int x, int y){
        this.x = x;
        this.y = y;
    }
    public void setXY(int x, int y){
        this.x = x;
        this.y = y;
    }
    public int[] getXY(){
        int[] arr = {x,y};
        return arr;
    }
    public String to_string(){
        return "X: "+ x +", Y: " + y;
    }
    public double distance(int x, int y){
        int dx = this.x - x;
        int dy = this.y - y;
        return Math.floor(Math.sqrt(dx*dx + dy*dy));
    }
    public double distance(MyPoint another){
        int dx = this.x - another.x;
        int dy = this.y - another.y;
        return Math.floor(Math.sqrt(dx*dx + dy*dy));
    }
    public double distance() {
        return Math.floor(Math.sqrt(x * x + y * y));
    }
}

public class geometry {
    public static void main(String[] args) {
        MyPoint p1 = new MyPoint();
        MyPoint p2 = new MyPoint(2,3);

        System.out.println("P1: "+p1.to_string());
        System.out.println("P2: "+p2.to_string());

        p1.setXY(4,5);

        int[] ar = p1.getXY();
        System.out.println("P1: " + "X: "+ ar[0]+", Y: "+ar[1]+" After setXY()");
        System.out.println("Distance from P1 to (8,9) "+p1.distance(8,9));
        System.out.println("Distance from P1 to P2: "+p1.distance(p2));
        System.out.println("Distnace from P2 to Origin: "+p2.distance());

    }
}
