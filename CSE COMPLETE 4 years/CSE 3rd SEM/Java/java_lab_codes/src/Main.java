import java.awt.*;

interface Resizable{
    void resizeWidth(int width);
    void resizeHeight(int height);
}
class Rectangle implements Resizable{
    int w;
    int h;

    Rectangle(int width, int height){
        w = width;
        h = height;
    }

    public void resizeWidth(int width){
        w = width;
        System.out.println("New Width: "+w);
    }
    public void resizeHeight(int height){
        h = height;
        System.out.println("New Height: "+h);
    }
    public void display(){
        System.out.println("Rectangle Width: "+w+", Height: "+h);
    }
}
public class Main{
    public static void main(String[] args) {
        Rectangle r = new Rectangle(20,30);
        System.out.println("Initial Size: ");
        r.display();
        r.resizeWidth(30);
        r.resizeHeight(40);
        System.out.println("After Resize: ");
        r.display();
    }
}
