#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold student details
struct Student {
    int id;
    string name;
    int age;
    string course;
};

// Function to add a new student
void addStudent(vector<Student> &students) {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;
    cout << "Enter Student Name: ";
    cin.ignore(); // clear buffer
    getline(cin, s.name);
    cout << "Enter Student Age: ";
    cin >> s.age;
    cout << "Enter Student Course: ";
    cin.ignore();
    getline(cin, s.course);

    students.push_back(s);
    cout << " Student added successfully!\n";
}

// Function to display all students
void displayStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << " No student records found.\n";
        return;
    }
    cout << "\n--- Student Records ---\n";
    for (const auto &s : students) {
        cout << "ID: " << s.id << ", Name: " << s.name
             << ", Age: " << s.age << ", Course: " << s.course << endl;
    }
}

// Function to search student by ID
void searchStudent(const vector<Student> &students) {
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (const auto &s : students) {
        if (s.id == id) {
            cout << " Student Found!\n";
            cout << "ID: " << s.id << ", Name: " << s.name
                 << ", Age: " << s.age << ", Course: " << s.course << endl;
            return;
        }
    }
    cout << " Student with ID " << id << " not found.\n";
}

// Function to update student details
void updateStudent(vector<Student> &students) {
    int id;
    cout << "Enter Student ID to update: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, s.name);
            cout << "Enter new age: ";
            cin >> s.age;
            cout << "Enter new course: ";
            cin.ignore();
            getline(cin, s.course);

            cout << " Student record updated successfully!\n";
            return;
        }
    }
    cout << " Student with ID " << id << " not found.\n";
}

int main() {
    vector<Student> students; // dynamic list of students
    int choice;

    do {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateStudent(students); break;
            case 5: cout << " Exiting program...\n"; break;
            default: cout << " Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
