#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    vector<int> scores;
    double average;
    char letter;
    string status; // PASS or FAIL
};

// Function to calculate letter grade using a switch-like structure
char getLetterGrade(double avg) {
    int tens = static_cast<int>(avg) / 10;
    switch (tens) {
        case 10:
        case 9: return 'A';
        case 8: return 'B';
        case 7: return 'C';
        case 6: return 'D';
        default: return 'F';
    }
}

int main() {
    vector<Student> students;
    string filename;

    cout << "Enter input filename: ";
    cin >> filename;
    cin.ignore();  // clear newline after filename input

    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: File could not be opened.\n";
        return 1;
    }

    while (true) {
        Student s;
        getline(infile, s.name);
        if (s.name.empty()) break;  // stop if no more names

        int score;
        while (infile >> score && score != -1) {
            s.scores.push_back(score);
        }
        infile.ignore(); // ignore newline after -1

        // Calculate average
        int sum = 0;
        for (int sc : s.scores) sum += sc;
        s.average = (s.scores.empty()) ? 0 : static_cast<double>(sum) / s.scores.size();

        // Assign grade
        s.letter = getLetterGrade(s.average);

        // Pass/Fail
        s.status = (s.average >= 60) ? "PASS" : "FAIL";

        students.push_back(s);
    }
    infile.close();

    // Print formatted table
    cout << left << setw(20) << "Name"
         << setw(10) << "Average"
         << setw(10) << "Grade"
         << setw(10) << "Status" << endl;
    cout << string(50, '-') << endl;

    for (const auto& s : students) {
        cout << left << setw(20) << s.name
             << setw(10) << fixed << setprecision(2) << s.average
             << setw(10) << s.letter
             << setw(10) << s.status << endl;
    }

    // Ask if user wants to save results
    cout << "\nSave results to file? (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        ofstream outfile("grade_report.txt");
        for (const auto& s : students) {
            outfile << left << setw(20) << s.name
                    << setw(10) << fixed << setprecision(2) << s.average
                    << setw(10) << s.letter
                    << setw(10) << s.status << endl;
        }
        outfile.close();
        cout << "Report saved to grade_report.txt\n";
    }

    // Optional: search by name
    cout << "\nSearch for a student by name? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cin.ignore();
        string searchName;
        cout << "Enter student name: ";
        getline(cin, searchName);

        bool found = false;
        for (const auto& s : students) {
            if (s.name == searchName) {
                cout << left << setw(20) << s.name
                     << setw(10) << s.average
                     << setw(10) << s.letter
                     << setw(10) << s.status << endl;
                found = true;
                break;
            }
        }
        if (!found) cout << "Student not found.\n";
    }

    return 0;
}
