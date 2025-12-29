class shape {
    void draw() {
        System.out.println("Drawing draw");
    }

    void erase() {
        System.out.println("Erasing draw");
    }
}
    class circle extends shape{
        @Override
        void draw() {
            System.out.println("Drawing circle");
        }
        @Override
        void erase() {
            System.out.println("Erasing circle");
        }
    }
    class triangle extends shape{
        @Override
        void draw() {
            System.out.println("Drawing triangle");
        }
        @Override
        void erase() {
            System.out.println("Erasing triangle");
        }
    }
    class square extends shape{
        @Override
        void draw() {
            System.out.println("Drawing square");
        }
        @Override
        void erase() {
            System.out.println("Erasing square");
        }
    }


public class shapes {
    public static void main(String[] args) {
        shape s;
        s = new circle();
        s.draw();
        s.erase();
        s = new triangle();
        s.draw();
        s.erase();
        s = new square();
        s.draw();
        s.erase();
    }
}
