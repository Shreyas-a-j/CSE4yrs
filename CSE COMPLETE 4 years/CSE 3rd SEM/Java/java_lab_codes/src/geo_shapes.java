abstract class shape1{
        abstract double calculateArea();
        abstract double calculateParameter();
}
class circle1 extends shape1{
    double radius;
    circle1(double r){
        radius = r;
    }
    double calculateArea(){
        return Math.PI*radius*radius;
    }
    double calculateParameter(){
        return 2*Math.PI*radius;
    }
}
class triangle1 extends shape1{
    double a,b,c;
    triangle1(double x, double y, double z){
        a = x;
        b = y;
        c = z;
    }
    double calculateArea(){
        double s = (a+b+c)/2;
        return Math.sqrt(s*(s-a)*(s-b)*(s-c));
    }
    double calculateParameter(){
        return a+b+c;
    }
}

public class geo_shapes {
    public static void main(String[] args) {
        circle1 c = new circle1(5);
        System.out.println("Circle Area: " + c.calculateArea());
        System.out.println("Circle Parameter " + c.calculateParameter());

        triangle1 t = new triangle1(3,4,5);
        System.out.println("Triangle Area: " + t.calculateArea());
        System.out.println("Traingle parameter "+ t.calculateParameter());
    }
}


