#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main() {
     string name;
     int score = 0, rounds = 0;
     cout << "Enter your full name: ";
     getline(cin, name);

     int choice;
     do {
          cout << "\n--- Console Arcade ---\n";
          cout << "1. Dice Duel\n2. Pattern Printer\n3. Show Scoreboard\n4. Quit\n";
          cout << "Choose an option: ";
          cin >> choice;

          switch (choice) {
                case 1: { // Dice Duel
                     srand(time(0));
                     int die1 = rand() % 6 + 1, die2 = rand() % 6 + 1;
                     int sum = die1 + die2;
                     char guess;
                     cout << "Guess (H)igh, (L)ow, or (E)xact 7: ";
                     cin >> guess;
                     bool correct = (guess == 'H' || guess == 'h') ? (sum > 7) :
                                         (guess == 'L' || guess == 'l') ? (sum < 7) :
                                         (sum == 7);
                     if (correct) {
                          cout << "Correct! ";
                          score += 10;
                     } else {
                          cout << "Wrong! ";
                          score -= 5;
                     }
                     rounds++;
                     cout << "Dice: " << die1 << " + " << die2 << " = " << sum << endl;
                     break;
                }
                case 2: { // Pattern Printer
                     int rows, cols;
                     char ch;
                     cout << "Rows: "; cin >> rows;
                     cout << "Columns: "; cin >> cols;
                     cout << "Character: "; cin >> ch;
                     cout << "Pattern:\n";
                     for (int i = 0; i < rows; ++i) {
                          for (int j = 0; j < cols; ++j)
                                cout << ch << " ";
                          cout << endl;
                     }
                     cout << "\nTable:\n";
                     cout << setw(10) << "Rows" << setw(10) << "Cols\n";
                     cout << setw(10) << rows << setw(10) << cols << endl;
                     break;
                }
                case 3: // Scoreboard
                     cout << "\nScoreboard:\n";
                     cout << setw(15) << "Name" << setw(10) << "Rounds" << setw(10) << "Score\n";
                     cout << setw(15) << name << setw(10) << rounds << setw(10) << score << endl;
                     break;
                case 4: // Quit
                     cout << "Goodbye!\n";
                     break;
                default:
                     cout << "Invalid option.\n";
          }

          // Variable scope demo
          int value = 5;
          cout << "Outer value: " << value << endl;
          {
                int value = 10;
                cout << "Inner value: " << value << endl;
          }
          cout << "Outer value again: " << value << endl;

     } while (choice != 4);

     return 0;
}