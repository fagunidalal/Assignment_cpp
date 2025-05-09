#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class UniversitySystemException : public runtime_error {
public:
    UniversitySystemException(const string& message) : runtime_error(message) {}
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(const string& message) : UniversitySystemException(message) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(const string& message) : UniversitySystemException(message) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(const string& message) : UniversitySystemException(message) {}
};

class Person {
protected:
    string name;
    int age;
    string id;
    string contact;

public:
    Person(string n, int a, string i, string c) : name(n), age(a), id(i), contact(c) {
        if (id.empty() || contact.empty()) {
            throw UniversitySystemException("Invalid ID or contact information.");
        }
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
        cout << "Contact: " << contact << endl;
    }

    virtual double calculatePayment() const {
        return 0.0;
    }
};

class Student : public Person {
protected:
    string program;
    float cgpa;

public:
    Student(string n, int a, string i, string c, string prog, float gpa) 
        : Person(n, a, i, c), program(prog), cgpa(gpa) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Program: " << program << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

class Professor : public Person {
protected:
    string department;
    float baseSalary;

public:
    Professor(string n, int a, string i, string c, string dept, float salary) 
        : Person(n, a, i, c), department(dept), baseSalary(salary) {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << endl;
        cout << "Base Salary: " << baseSalary << endl;
    }

    double calculatePayment() const override {
        return baseSalary;
    }
};

class Course {
private:
    string courseCode;
    string courseTitle;
    int maxStudents;
    int enrolledStudents;

public:
    Course(string code, string title, int max) 
        : courseCode(code), courseTitle(title), maxStudents(max), enrolledStudents(0) {}

    void enrollStudent() {
        if (enrolledStudents >= maxStudents) {
            throw EnrollmentException("Cannot enroll. Course is full.");
        }
        enrolledStudents++;
        cout << "Student enrolled in " << courseTitle << endl;
    }

    void finalizeGrades() {
        if (enrolledStudents == 0) {
            throw GradeException("Cannot finalize grades. No students enrolled.");
        }
        cout << "Grades finalized for " << courseTitle << endl;
    }
};

class UniversitySystem {
public:
    void enrollStudentInCourse(Course& course) {
        course.enrollStudent();
    }

    void finalizeCourseGrades(Course& course) {
        course.finalizeGrades();
    }

    void calculateProfessorPayments(Professor& professor) {
        double payment = professor.calculatePayment();
        cout << "Professor's Payment: " << payment << endl;
    }
};

int main() {
    try {
        Professor prof1("Richa Singh", 45, "P001", "richa@uni.com", "Computer Science", 50000);
        Student student1("Faguni", 21, "001", "faguni@mail.com", "Computer Science", 3.9);

        Course cs101("CS101", "Beginner Programming", 1);

        UniversitySystem system;
        system.enrollStudentInCourse(cs101);
        system.calculateProfessorPayments(prof1);
        system.finalizeCourseGrades(cs101);

    } catch (const EnrollmentException& e) {
        cout << "Enrollment Error: " << e.what() << endl;
    } catch (const GradeException& e) {
        cout << "Grade Error: " << e.what() << endl;
    } catch (const PaymentException& e) {
        cout << "Payment Error: " << e.what() << endl;
    } catch (const UniversitySystemException& e) {
        cout << "General Error: " << e.what() << endl;
    } catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}
