#include <iostream>
#include <string>

using namespace std;

class Addressa // Оголошення класу
{
private:
    string name;
    string street;
    int housenumber;

public:
    // Конструктор за замовчуванням
    Addressa(string _name = "", string _street = "", int _housenumber = 0)
        : name(_name), street(_street), housenumber(_housenumber) {}

    // Дозволяє встановлювати значення
    void setAddressa(string _name, string _street, int _housenumber) {
        name = _name;
        street = _street;
        housenumber = _housenumber;
    }

    // Дозволяє вводити свої дані
    void inputAddressa() {
        cout << "Введіть ім'я: \n";
        cin.ignore(); // Очищає буфер перед введенням рядка
        getline(cin, name);
        cout << "Введіть вулицю: \n";
        getline(cin, street);
        cout << "Введіть номер будинку: \n";
        cin >> housenumber;
    }

    // Показує дані на екрані
    void printAddressa() const {
        // Виводимо дані в одному рядку
        cout << "Ім'я: " << name << ", Вулиця: " << street << ", Номер будинку: " << housenumber << endl;
    }
};

int main() // Основна функція
{
    // Створює два об'єкти з різними даними
    Addressa Oleg_1("Oleg :)", "Шевченка", 6);
    Addressa Oleg_2("Oleg :(", "Сембратовича", 8);
    Addressa user; // Об'єкт для введення користувацьких даних
  // Виведення даних на екран
    cout << "Дані про зареєстрованих осіб:" << endl;
    Oleg_1.printAddressa();
    Oleg_2.printAddressa();
  // Введення та виведення особистих даних користувача
    cout << "\nВведіть ваші дані:" << endl;
    user.inputAddressa();
    cout << "\nВаші дані: ";
    user.printAddressa(); // Тепер дані виводяться в одному рядку

    return 0;
}
