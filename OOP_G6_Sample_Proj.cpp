#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include <cstdio>   // std::remove, std::rename

using namespace std;

class Student {
private:
    string name;
    int rollNumber{};
    int marks[3]{};

public:
    void input() {
        cout << "Enter name: ";
        getline(cin >> ws, name); // consume leading whitespace/newline safely

        cout << "Enter roll number: ";
        cin >> rollNumber;

        cout << "Enter marks in three subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    void display() const {
        cout << "Name: " << name
             << ", Roll Number: " << rollNumber
             << ", Marks: ";
        for (int i = 0; i < 3; i++) {
            cout << marks[i] << (i == 2 ? "" : " ");
        }
        cout << '\n';
    }

    int getRollNumber() const {
        return rollNumber;
    }

    void updateMarks() {
        cout << "Enter new marks in three subjects: ";
        for (int i = 0; i < 3; i++) {
            cin >> marks[i];
        }
    }

    void writeToFile(ofstream& file) const {
        file << name << '\n';
        file << rollNumber << '\n';
        for (int i = 0; i < 3; i++) {
            file << marks[i] << (i == 2 ? "" : " ");
        }
        file << '\n';
    }

    // Return true if a full student record was read successfully
    bool readFromFile(ifstream& file) {
        string rollLine, marksLine;

        if (!getline(file, name)) return false;
        if (name.empty() && file.eof()) return false; // handle trailing newline at EOF

        if (!getline(file, rollLine)) return false;
        if (!getline(file, marksLine)) return false;

        {
            istringstream rs(rollLine);
            if (!(rs >> rollNumber)) return false;
        }
        {
            istringstream ms(marksLine);
            for (int i = 0; i < 3; i++) {
                if (!(ms >> marks[i])) return false;
            }
        }
        return true;
    }
};

void addStudentRecord() {
    Student student;
    student.input();

    ofstream file("students.txt", ios::app);
    if (file.is_open()) {
        student.writeToFile(file);
        file.close();
        cout << "Record added successfully.\n";
    } else {
        cout << "Error opening file for writing.\n";
    }
}

void displayAllRecords() {
    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error opening file for reading.\n";
        return;
    }

    Student student;
    bool any = false;
    while (student.readFromFile(file)) {
        student.display();
        any = true;
    }

    if (!any) {
        cout << "No records found.\n";
    }

    file.close();
}

void searchStudentRecord() {
    int roll;
    cout << "Enter roll number to search: ";
    cin >> roll;

    ifstream file("students.txt");
    if (!file.is_open()) {
        cout << "Error opening file for reading.\n";
        return;
    }

    Student student;
    bool found = false;
    while (student.readFromFile(file)) {
        if (student.getRollNumber() == roll) {
            student.display();
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Record not found.\n";
    }
}

void updateStudentRecord() {
    int roll;
    cout << "Enter roll number to update: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream tempFile("temp.txt", ios::trunc);

    if (!file.is_open() || !tempFile.is_open()) {
        cout << "Error opening file for updating.\n";
        return;
    }

    Student student;
    bool found = false;

    while (student.readFromFile(file)) {
        if (student.getRollNumber() == roll) {
            student.updateMarks();
            found = true;
        }
        student.writeToFile(tempFile);
    }

    file.close();
    tempFile.close();

    std::remove("students.txt");
    std::rename("temp.txt", "students.txt");

    if (found) {
        cout << "Record updated successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

void deleteStudentRecord() {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    ifstream file("students.txt");
    ofstream tempFile("temp.txt", ios::trunc);

    if (!file.is_open() || !tempFile.is_open()) {
        cout << "Error opening file for deletion.\n";
        return;
    }

    Student student;
    bool found = false;

    while (student.readFromFile(file)) {
        if (student.getRollNumber() == roll) {
            found = true; // skip writing this record
        } else {
            student.writeToFile(tempFile);
        }
    }

    file.close();
    tempFile.close();

    std::remove("students.txt");
    std::rename("temp.txt", "students.txt");

    if (found) {
        cout << "Record deleted successfully.\n";
    } else {
        cout << "Record not found.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student Record\n";
        cout << "4. Update Student Record\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addStudentRecord();
                break;
            case 2:
                displayAllRecords();
                break;
            case 3:
                searchStudentRecord();
                break;
            case 4:
                updateStudentRecord();
                break;
            case 5:
                deleteStudentRecord();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
