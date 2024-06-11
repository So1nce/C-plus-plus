#include <iostream>
#include <locale>
using namespace std;

// Оголошення функцій для обчислення B1 і B2
int computeB1(int J) noexcept;
int computeB2(int J) noexcept;

void displayMenu() {
    cout << "Меню:" << endl;
    cout << "1. Робота1" << endl;
    cout << "2. Робота2" << endl;
    cout << "3. Вихiд" << endl;
    cout << "Виберiть пункт меню: ";
}

int main() {

    setlocale(LC_CTYPE, "ukr");
    int choice;
    int J;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введiть значення Ж: ";
            cin >> J;
            cout << "Результат обчислення B1 = Ж mod 4: " << computeB1(J) << endl;
            break;
        case 2:
            cout << "Введiть значення Ж: ";
            cin >> J;
            cout << "Результат обчислення B2 = (Ж + 1) mod 4: " << computeB2(J) << endl;
            break;
        case 3:
            cout << "Вихiд з програми." << endl;
            return 0;
        default:
            cout << "Невiрний вибір, спробуйте ще раз." << endl;
        }
    }

    return 0;
}

// Реалізація функцій для обчислення B1 і B2
int computeB1(int J) noexcept {
    return J % 4;
}

int computeB2(int J) noexcept {
    return (J + 1) % 4;
}