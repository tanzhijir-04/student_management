#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Student {
    int id;
    int basicCredits;
    int majorCredits;
    int electiveCredits;
    int humanitiesCredits;
    int practicalCredits;
};

unordered_map<int, Student> studentDatabase;

void loadFromFile(const string& filename) {
    ifstream infile(filename.c_str());
    if (!infile.is_open()) {
        cerr << "File " << filename << " not found. Creating a new file." << endl;
        ofstream outfile(filename.c_str());
        outfile.close();
        return;
    }

    Student student;
    while (infile >> student.id >> student.basicCredits >> student.majorCredits
                  >> student.electiveCredits >> student.humanitiesCredits >> student.practicalCredits) {
        studentDatabase[student.id] = student;
    }

    infile.close();
}

void saveToFile(const string& filename) {
    ofstream outfile(filename.c_str());
    if (!outfile.is_open()) {
        cerr << "Could not open file " << filename << endl;
        return;
    }

    for (const auto& entry : studentDatabase) {
        const Student& student = entry.second;
        outfile << student.id << " " << student.basicCredits << " " << student.majorCredits
                << " " << student.electiveCredits << " " << student.humanitiesCredits << " "
                << student.practicalCredits << endl;
    }

    outfile.close();
}

void displayStudent(int id) {
    if (studentDatabase.find(id) != studentDatabase.end()) {
        const Student& student = studentDatabase[id];
        cout << "Student ID: " << student.id << endl;
        cout << "Basic Credits: " << student.basicCredits << endl;
        cout << "Major Credits: " << student.majorCredits << endl;
        cout << "Elective Credits: " << student.electiveCredits << endl;
        cout << "Humanities Credits: " << student.humanitiesCredits << endl;
        cout << "Practical Credits: " << student.practicalCredits << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

void updateStudent(int id, const Student& updatedStudent) {
    if (studentDatabase.find(id) != studentDatabase.end()) {
        studentDatabase[id] = updatedStudent;
        cout << "Student ID " << id << " updated successfully." << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

void deleteStudent(int id) {
    if (studentDatabase.find(id) != studentDatabase.end()) {
        studentDatabase.erase(id);
        cout << "Student ID " << id << " deleted successfully." << endl;
    } else {
        cout << "Student with ID " << id << " not found." << endl;
    }
}

void addStudent() {
    Student student;
    cout << "Enter student ID: ";
    while (!(cin >> student.id)) {
        cout << "Invalid input. Please enter a valid student ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter basic credits: ";
    while (!(cin >> student.basicCredits)) {
        cout << "Invalid input. Please enter a valid number of basic credits: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter major credits: ";
    while (!(cin >> student.majorCredits)) {
        cout << "Invalid input. Please enter a valid number of major credits: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter elective credits: ";
    while (!(cin >> student.electiveCredits)) {
        cout << "Invalid input. Please enter a valid number of elective credits: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter humanities credits: ";
    while (!(cin >> student.humanitiesCredits)) {
        cout << "Invalid input. Please enter a valid number of humanities credits: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Enter practical credits: ";
    while (!(cin >> student.practicalCredits)) {
        cout << "Invalid input. Please enter a valid number of practical credits: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (studentDatabase.find(student.id) != studentDatabase.end()) {
        cout << "Student with ID " << student.id << " already exists. Do you want to update the information? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            studentDatabase[student.id] = student;
            cout << "Student information updated successfully." << endl;
        } else {
            cout << "Student information not updated." << endl;
        }
    } else {
        studentDatabase[student.id] = student;
        cout << "Student added successfully." << endl;
    }
}

int main() {
    string filename = "students.txt";
    loadFromFile(filename);

    int choice, id;
    Student student;

    while (true) {
        cout << "1. Load students from file" << endl;
        cout << "2. Save students to file" << endl;
        cout << "3. Display student information" << endl;
        cout << "4. Update student information" << endl;
        cout << "5. Delete student" << endl;
        cout << "6. Add new student" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                loadFromFile(filename);
                break;
            case 2:
                saveToFile(filename);
                break;
            case 3:
                cout << "Enter student ID: ";
                while (!(cin >> id)) {
                    cout << "Invalid input. Please enter a valid student ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                displayStudent(id);
                break;
            case 4:
                cout << "Enter student ID: ";
                while (!(cin >> id)) {
                    cout << "Invalid input. Please enter a valid student ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter basic credits: ";
                while (!(cin >> student.basicCredits)) {
                    cout << "Invalid input. Please enter a valid number of basic credits: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter major credits: ";
                while (!(cin >> student.majorCredits)) {
                    cout << "Invalid input. Please enter a valid number of major credits: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter elective credits: ";
                while (!(cin >> student.electiveCredits)) {
                    cout << "Invalid input. Please enter a valid number of elective credits: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter humanities credits: ";
                while (!(cin >> student.humanitiesCredits)) {
                    cout << "Invalid input. Please enter a valid number of humanities credits: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "Enter practical credits: ";
                while (!(cin >> student.practicalCredits)) {
                    cout << "Invalid input. Please enter a valid number of practical credits: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                student.id = id;
                updateStudent(id, student);
                break;
            case 5:
                cout << "Enter student ID: ";
                while (!(cin >> id)) {
                    cout << "Invalid input. Please enter a valid student ID: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                deleteStudent(id);
                break;
            case 6:
                addStudent();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
