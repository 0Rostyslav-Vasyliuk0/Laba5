#include <iostream>
#include <string>

using namespace std;

class Addressa {
private:
    string name;
    string street;
    int housenumber;

public:
    // Конструктор за замовчуванням
    Addressa() : name(""), street(""), housenumber(0) {}

    // Конструктор з параметрами для ініціалізації об'єкта
    Addressa(string _name, string _street, int _housenumber) {
        if (validateHouseNumber(_housenumber)) {
            name = _name;
            street = _street;
            housenumber = _housenumber;
        } else {
            cout << "Некоректний номер будинку." << endl;
            name = "";
            street = "";
            housenumber = 0;
        }
    }

    // Деструктор
    ~Addressa() {
        cout << "Деструктор викликаний для " << name << endl;
    }

    // Метод для встановлення значень
    void setAddressa(string _name, string _street, int _housenumber) {
        name = _name;
        street = _street;
        if (validateHouseNumber(_housenumber)) {
            housenumber = _housenumber;
        } else {
            cout << "Некоректний номер будинку." << endl;
        }
    }

    // Метод для вводу даних
    void inputAddressa() {
        cout << "Введіть ім'я: ";
        getline(cin, name);
        cout << "Введіть вулицю: ";
        getline(cin, street);
        cout << "Введіть номер будинку: ";
        cin >> housenumber;
        cin.ignore(); // Очищення буферу

        if (!validateHouseNumber(housenumber)) {
            cout << "Неправильний номер будинку, встановлено значення за замовчуванням (0)." << endl;
            housenumber = 0;
        }
    }

    // Метод для виведення даних
    void printAddressa() const {
        cout << "Ім'я: " << name << ", Вулиця: " << street << ", Номер будинку: " << housenumber << endl;
    }

    // Метод перевірки, чи житель живе на заданій вулиці
    bool isOnStreet(const string& searchStreet) const {
        return street == searchStreet;
    }

private:
    // Метод для валідації номера будинку
    bool validateHouseNumber(int number) const {
        return number > 0;
    }
};

int main() {
    // Створення кількох об'єктів класу Addressa
    Addressa Oleg_1("Oleg :)", "Шевченка", 6);
    Addressa Oleg_2("Oleg :(", "Сембратовича", 8);
    Addressa user; // Об'єкт для особистих даних, які будуть введені користувачем

    // Вивід інформації про об'єкти
    cout << "Дані про зареєстрованих осіб:" << endl;
    Oleg_1.printAddressa();
    Oleg_2.printAddressa();

    // Введення та виведення особистих даних користувача
    cout << "\nВведіть дані:" << endl;
    user.inputAddressa();
    cout << "\nВаші дані:" << endl;
    user.printAddressa();

    // Пошук жителів на вулиці "Шевченка"
    cout << "\nЖителі на вулиці Шевченка:" << endl;
    if (Oleg_1.isOnStreet("Шевченка")) Oleg_1.printAddressa();
    if (Oleg_2.isOnStreet("Шевченка")) Oleg_2.printAddressa();
    if (user.isOnStreet("Шевченка")) user.printAddressa();

    return 0;
}
