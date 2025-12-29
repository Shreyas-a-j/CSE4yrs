import java.util.Scanner;
    class Employe {
        int id;
        String name;
        double salary;

        Employe(int id, String name, double salary) {
            this.id = id;
            this.name = name;
            this.salary = salary;
        }

        void raiseSalary(double per) {
            if (per < 0) {
                System.out.println("Invalid input");
            } else {
                salary += salary * per / 100;
            }
        }

        void display() {
            System.out.println("ID: " + id + " Name: " + name + " Salary: " + salary);
        }
    }
public class Employee {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            System.out.println("Enter the Employee details: ");
            System.out.print("Enter ID: ");
            int id = sc.nextInt();
            System.out.print("Enter Name: ");
            String name = sc.next();
            System.out.print("Enter Salary: ");
            double salary = sc.nextDouble();

            Employe e = new Employe(id, name, salary);
            System.out.print("Before salary raise: ");
            e.display();
            System.out.print("How much do u want to raise? ");
            e.raiseSalary(sc.nextDouble());
            System.out.print("After raise: ");
            e.display();
            sc.close();
        }
    }

