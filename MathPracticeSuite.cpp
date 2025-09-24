#include <iostream>
#include <cstdlib>  // for rand(), srand()
#include <ctime>    // for time()
using namespace std;

int main() {
    srand(time(0)); // seed once with current time

    int correct = 0;
    int wrong = 0;

    while (true) {
        cout << "\n=== Math Practice Suite ===\n";
        cout << "1) Addition\n";
        cout << "2) Subtraction\n";
        cout << "3) Multiplication\n";
        cout << "4) Division\n";
        cout << "5) Statistics\n";
        cout << "Q) Quit\n";
        cout << "Choose: ";

        char choice;
        cin >> choice;

        if (choice == 'Q' || choice == 'q') {
            cout << "Goodbye!\n";
            break;
        }

        if (choice >= '1' && choice <= '4') {
            while (true) {
                int a = rand() % 12 + 1; // random 1–12
                int b = rand() % 12 + 1; // random 1–12

                char op;
                int answer;
                if (choice == '1') { op = '+'; answer = a + b; }
                else if (choice == '2') { op = '-'; answer = a - b; }
                else if (choice == '3') { op = '*'; answer = a * b; }
                else {
                    op = '/';
                    b = rand() % 12 + 1;      // make sure b != 0
                    a = b * (rand() % 12 + 1); // ensure divisible
                    answer = a / b;
                }

                cout << "What is " << a << " " << op << " " << b
                     << "? (enter -999 to go back to menu): ";

                int user;
                cin >> user;
                if (user == -999) break;

                if (user == answer) {
                    cout << "Correct!\n";
                    correct++;
                } else {
                    cout << "Wrong. The correct answer is " << answer << ".\n";
                    wrong++;
                }
            }
        }
        else if (choice == '5') {
            int total = correct + wrong;
            cout << "\nSTATISTICS\n";
            cout << "Correct: " << correct << "\n";
            cout << "Wrong:   " << wrong << "\n";
            cout << "Total:   " << total << "\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
