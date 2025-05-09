#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Person {
private:
    string name;
    int age;
    string id;
    string contact;

public:
    Person() : name(""), age(0), id(""), contact("") {}

    Person(string n, int a, string i, string c) {
        setName(n);
        setAge(a);
        id = i;
        contact = c;
    }
    virtual ~Person() {}

    void setName(string n) {
        if (!n.empty()) name = n;
        else cout << "Name cannot be empty.\n";
    }

    void setAge(int a) {
        if (a > 0 && a < 120) age = a;
        else cout << "Invalid age.\n";
    }

    string getName() const { return name; }
    int getAge() const { return age; }
    string getId() const { return id; }
    string getContact() const { return contact; }

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age
             << ", ID: " << id << ", Contact: " << contact << endl;
    }

    virtual double calculatePayment() const {
        return 0.0;
    }
};

class Student : public Person {
private:
    string enrollmentDate;
    string program;
    float gpa;

public:
    Student() : Person(), enrollmentDate(""), program(""), gpa(0.0) {}

    Student(string n, int a, string i, string c, string e, string p, float g)
        : Person(n, a, i, c), enrollmentDate(e), program(p) {
        setGPA(g);
    }
    virtual ~Student() {}

    void setGPA(float g) {
        if (g >= 0.0 && g <= 4.0) gpa = g;
        else cout << "Invalid GPA.\n";
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate
             << ", Program: " << program << ", GPA: " << gpa << endl;
    }

    double calculatePayment() const override {
        return 10000.0;
    }
};

class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;

public:
    Professor() : Person(), department(""), specialization(""), hireDate("") {}

    Professor(string n, int a, string i, string c, string d, string s, string h)
        : Person(n, a, i, c), department(d), specialization(s), hireDate(h) {}
    
    virtual ~Professor () {}

        void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department
             << ", Specialization: " << specialization
             << ", Hire Date: " << hireDate << endl;
    }

    double calculatePayment() const override {
        return 5000.0;
    }
};

class Course {
private:
    string code;
    string title;
    int credits;
    string description;

public:
    Course(string c, string t, int cr, string d) {
        code = c;
        title = t;
        setCredits(cr);
        description = d;
    }
    virtual ~Course() {}

    void setCredits(int cr) {
        if (cr > 0) credits = cr;
        else cout << "Invalid credits.\n";
    }
};

class Department {
private:
    string name;
    string location;
    double budget;

public:
    Department(string n, string l, double b) {
        name = n;
        location = l;
        budget = b;
    }
    virtual ~Department () {}
};

class GradeBook {
private:
    vector<pair<string, double>> grades;

public:
    void addGrade(string studentID, double grade) {
        grades.push_back({studentID, grade});
    }

    double calculateAverageGrade() const {
        double sum = 0;
        for (auto g : grades) sum += g.second;
        return grades.empty() ? 0 : sum / grades.size();
    }

    double getHighestGrade() const {
        double high = 0;
        for (auto g : grades)
            if (g.second > high) high = g.second;
        return high;
    }

    void getFailingStudents() const {
        cout << "Failing Students: ";
        for (auto g : grades)
            if (g.second < 50)
                cout << g.first << " ";
        cout << endl;
    }
};

class EnrollmentManager {
private:
    vector<pair<string, string>> enrollments;

public:
    void enrollStudent(string course, string studentID) {
        enrollments.push_back({course, studentID});
    }

    void dropStudent(string course, string studentID) {
        enrollments.erase(remove(enrollments.begin(), enrollments.end(), make_pair(course, studentID)), enrollments.end());
    }

    int getEnrollmentCount(string course) const {
        int count = 0;
        for (auto e : enrollments)
            if (e.first == course)
                count++;
        return count;
    }
};

void testPolymorphism(Person* p) {
    p->displayDetails();
    cout << "Payment: Rs." << p->calculatePayment() << endl << endl;
}





int main() {
    Student s1("Faguni", 18, "001", "faguni@mail.com", "1 june 2024", "CS", 3.9);
    Student s2("Kanika", 21, "002", "kanika@mail.com", "22 june 2020", "ECE", 2.1);
    Professor p1("Richa Singh", 30, "P001", "richa@mail.com", "CS", "AI", "20 may 2018");
    Professor p2("Neha Tyagi", 35, "P002", "neha@mail.com", "ECE", "DS", "15 may 2019");

    cout << "\n**********************Test for Polymorphism*************************" << endl;
    vector<Person*> people = {&s1, &s2, &p1, &p2};
    for (auto p : people)
        testPolymorphism(p);

    GradeBook gb;
    gb.addGrade("001", 98);
    gb.addGrade("002", 33);
    cout << "Average Grade: " << gb.calculateAverageGrade() << endl;
    cout << "Highest Grade: " << gb.getHighestGrade() << endl;
    gb.getFailingStudents();

    EnrollmentManager em;
    em.enrollStudent("CS101", "001");
    em.enrollStudent("CS101", "002");
    cout << "Enrollment Count for CS101: " << em.getEnrollmentCount("CS101") << endl;

    

    return 0;
}
