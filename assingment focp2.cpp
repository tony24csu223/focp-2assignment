#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;
    string id;

public:
    Person(string n, string i) {
        name = n;
        id = i;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    virtual ~Person() {
        cout << "Person object destroyed for: " << name << endl;
    }
};

class Student : public Person {
private:
    string sid;
    string program;
    float gpa;

public:
    Student(string n, string i, string studentId, string prog, float grade)
        : Person(n, i) {
        sid = studentId;
        program = prog;
        gpa = grade;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Student ID: " << sid << ", Program: " << program << ", GPA: " << gpa << endl;
    }
};

class Professor : public Person {
private:
    string pid;
    string department;
    string specialization;

public:
    Professor(string n, string i, string profId, string dept, string spec)
        : Person(n, i) {
        pid = profId;
        department = dept;
        specialization = spec;
    }

    void displayDetails() override {
        Person::displayDetails();
        cout << "Professor ID: " << pid << ", Department: " << department
             << ", Specialization: " << specialization << endl;
    }
};

int main() {
    vector<Student> students;
    vector<Professor> professors;

    int choice;

    while (true) {
        cout << "\nEnter 1 to add Student, 2 to add Professor, 0 to stop: ";
        cin >> choice;
        cin.ignore(); // clear newline

        if (choice == 0) {
            break;  // exit loop
        } else if (choice == 1) {
            string name, id, sid, program;
            float gpa;

            cout << "\n--- Enter Student Details ---\n";
            cout << "Name: ";
            getline(cin, name);
            cout << "Person ID: ";
            getline(cin, id);
            cout << "Student ID: ";
            getline(cin, sid);
            cout << "Program: ";
            getline(cin, program);
            cout << "GPA: ";
            cin >> gpa;
            cin.ignore();

            students.push_back(Student(name, id, sid, program, gpa));
        } else if (choice == 2) {
            string name, id, pid, department, specialization;

            cout << "\n--- Enter Professor Details ---\n";
            cout << "Name: ";
            getline(cin, name);
            cout << "Person ID: ";
            getline(cin, id);
            cout << "Professor ID: ";
            getline(cin, pid);
            cout << "Department: ";
            getline(cin, department);
            cout << "Specialization: ";
            getline(cin, specialization);

            professors.push_back(Professor(name, id, pid, department, specialization));
        } else {
            cout << "Invalid choice! Please enter 1, 2, or 0." << endl;
        }
    }

    // Display All Students
    cout << "\n===== All Students =====\n";
    for (auto &s : students) {
        s.displayDetails();
        cout << "--------------------------\n";
    }

    // Display All Professors
    cout << "\n===== All Professors =====\n";
    for (auto &p : professors) {
        p.displayDetails();
        cout << "--------------------------\n";
    }

    return 0;
}
