#include <iostream>
#include <string>
using namespace std;
//hamid bsit1
struct Student {
    int studentID;
    string firstName, lastName, course;
    float GPA;
};

Student students[100]; // Array of structure
int count = 0;

void displayMenu() {
    cout << "\n--- Student Management System ---\n";
    cout << "1. Add Student\n";
    cout << "2. Edit Student\n";
    cout << "3. Delete Student\n";
    cout << "4. View Students\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int searchStudent(int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].studentID == id) {
            return i;
        }
    }
    return -1;
}

void addStudent() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    if (searchStudent(id) != -1) {
        cout << "Duplicate ID! Try again.\n";
        return;
    }

    students[count].studentID = id;
    cout << "Enter First Name: ";
    cin >> students[count].firstName;
    cout << "Enter Last Name: ";
    cin >> students[count].lastName;
    cout << "Enter Course: ";
    cin >> students[count].course;
    cout << "Enter GPA: ";
    cin >> students[count].GPA;

    cout << "Student added successfully!\n";
    count++;
}

void editStudent() {
    int id, index;
    cout << "Enter Student ID to edit: ";
    cin >> id;

    index = searchStudent(id);
    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    cout << "Enter New First Name: ";
    cin >> students[index].firstName;
    cout << "Enter New Last Name: ";
    cin >> students[index].lastName;
    cout << "Enter New Course: ";
    cin >> students[index].course;
    cout << "Enter New GPA: ";
    cin >> students[index].GPA;

    cout << "Student updated successfully!\n";
}

void deleteStudent() {
    int id, index;
    cout << "Enter Student ID to delete: ";
    cin >> id;

    index = searchStudent(id);
    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    for (int i = index; i < count - 1; i++) {
        students[i] = students[i + 1];
    }
    count--;
    cout << "Student deleted successfully!\n";
}

void viewStudents() {
    if (count == 0) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].studentID << "\n";
        cout << "Name: " << students[i].firstName << " " << students[i].lastName << "\n";
        cout << "Course: " << students[i].course << "\n";
        cout << "GPA: " << students[i].GPA << "\n";
        cout << "------------------------\n";
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            editStudent();
            break;
        case 3:
            deleteStudent();
            break;
        case 4:
            viewStudents();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
