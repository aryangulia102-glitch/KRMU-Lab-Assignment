import java.util.Scanner;

class student {
    String rollNo;
    String name;
    String course;
    double marks;
    String grade;
    Scanner sc = new Scanner(System.in);

    public void inputStudent() {
        System.out.println("Enter Roll Number:");
        rollNo = sc.nextLine();
        System.out.println("Enter Name:");
        name = sc.nextLine();
        System.out.println("Enter Course:");
        course = sc.nextLine();
        System.out.println("Enter Marks:");
        marks = sc.nextDouble();
        sc.nextLine();
        CalculateGrade();
    }

    private void CalculateGrade() {
        if (marks >= 90)
            grade = "A+";
        else if (marks >= 80)
            grade = "A";
        else if (marks >= 70)
            grade = "B";
        else if (marks >= 60)
            grade = "C";
        else if (marks >= 50)
            grade = "D";
        else
            grade = "F";
    }

    public void displayStudent() {
        System.out.println("Roll No:" + rollNo);
        System.out.println("Name:" + name);
        System.out.println("Course:" + course);
        System.out.println("Marks:" + marks);
        System.out.println("Grade:" + grade);
        System.out.println("--------------");
    }
}
