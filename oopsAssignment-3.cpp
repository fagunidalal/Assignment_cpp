#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string id;
    string contact;

public:
    Person(string n, int a, string i, string c) : name(n), age(a), id(i), contact(c) {}
    virtual ~Person() {}

    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", ID: " << id << ", Contact: " << contact << endl;
    }

    virtual double calculatePayment() const {
        return 0.0;
    }
};

class Student : public Person {
protected:
    string enrollmentDate;
    string program;

public:
    Student(string n, int a, string i, string c, string e, string p)
        : Person(n, a, i, c), enrollmentDate(e), program(p) {}
        virtual ~Student() {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate << ", Program: " << program << endl;
    }
};

class UndergraduateStudent : public Student {
private:
    string major;
    string minor;
    string expectedGraduationDate;

public:
    UndergraduateStudent(string n, int a, string i, string c, string e, string p, string m, string mi, string eg)
        : Student(n, a, i, c, e, p), major(m), minor(mi), expectedGraduationDate(eg) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Major: " << major << ", Minor: " << minor << ", Expected Graduation: " << expectedGraduationDate << endl;
    }

    double calculatePayment() const override {
        return 5000.0;
    }
};

class GraduateStudent : public Student {
private:
    string researchTopic;
    string thesisTitle;
    string advisor;

public:
    GraduateStudent(string n, int a, string i, string c, string e, string p, string rt, string tt, string ad)
        : Student(n, a, i, c, e, p), researchTopic(rt), thesisTitle(tt), advisor(ad) {}

    void displayDetails() const override {
        Student::displayDetails();
        cout << "Research Topic: " << researchTopic << ", Thesis Title: " << thesisTitle << ", Advisor: " << advisor << endl;
    }

    double calculatePayment() const override {
        return 7000.0;
    }
};

class Professor : public Person {
protected:
    string department;
    string hireDate;

public:
    Professor(string n, int a, string i, string c, string d, string h)
        : Person(n, a, i, c), department(d), hireDate(h) {}
        virtual ~Professor() {}

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << ", Hire Date: " << hireDate << endl;
    }

    virtual double calculatePayment() const override {
        return 10000.0;
    }
};

class AssistantProfessor : public Professor {
private:
    string tenureTrackDate;

public:
    AssistantProfessor(string n, int a, string i, string c, string d, string h, string t)
        : Professor(n, a, i, c, d, h), tenureTrackDate(t) {}

    void displayDetails() const override {
        Professor::displayDetails();
        cout << "Tenure Track Date: " << tenureTrackDate << endl;
    }

    double calculatePayment() const override {
        return 12000.0;
    }
};

class AssociateProfessor : public Professor {
private:
    string publishingRequirements;

public:
    AssociateProfessor(string n, int a, string i, string c, string d, string h, string p)
        : Professor(n, a, i, c, d, h), publishingRequirements(p) {}

    void displayDetails() const override {
        Professor::displayDetails();
        cout << "Publishing Requirements: " << publishingRequirements << endl;
    }

    double calculatePayment() const override {
        return 15000.0;
    }
};

class FullProfessor : public Professor {
private:
    string researchGrants;

public:
    FullProfessor(string n, int a, string i, string c, string d, string h, string r)
        : Professor(n, a, i, c, d, h), researchGrants(r) {}

    void displayDetails() const override {
        Professor::displayDetails();
        cout << "Research Grants: " << researchGrants << endl;
    }

    double calculatePayment() const override {
        return 20000.0;
    }
};

class Course {
private:
    string courseCode;
    string courseTitle;
    Professor* instructor;

public:
    Course(string code, string title, Professor* prof)
        : courseCode(code), courseTitle(title), instructor(prof) {}
        virtual ~Course() {}

    void displayDetails() const {
        cout << "Course Code: " << courseCode << ", Course Title: " << courseTitle << endl;
        instructor->displayDetails();
    }
};

class Department {
private:
    string name;
    vector<Professor*> professors;

public:
    Department(string n) : name(n) {}
    virtual ~Department() {}

    void addProfessor(Professor* p) {
        professors.push_back(p);
    }

    void showProfessors() const {
        cout << "Professors in Department " << name << ":\n";
        for (auto p : professors) {
            p->displayDetails();
            cout << endl;
        }
    }
};

int main() {
    cout << endl;
    AssistantProfessor* prof1 = new AssistantProfessor("Richa Singh", 30, "P001", "richa@uni.com", "Computer Science", "2020-08-15", "15 june 2025");
    AssociateProfessor* prof2 = new AssociateProfessor("Neha Tyagi", 35, "P002", "neha@uni.com", "Physics", " 20 july 2015", "Evloution of psyhics");

    UndergraduateStudent u1("Faguni", 20, "001", "faguni@mail.com", "1 june 2022", "Computer Science", "Software Engineering", "AI", "1 may 2025");
    GraduateStudent g1("Kanika", 24, "002", "kanika@mail.com", "1 june 2020", "Computer Science", "Internet networks", "Computer Networking", "Dr. Neha");

    Course csCourse("CS101", "Introduction to Programming", prof1);

    u1.displayDetails();
    cout << endl;
    g1.displayDetails();
    cout << endl;
    csCourse.displayDetails();

    delete prof1;
    delete prof2;


    return 0;
}
