#include <iostream>
#include <Windows.h>
#include <string>

class Counter
{
private:
    int count;
public:
    void inc() {
        this->count++;
    }
    void dec() {
        this->count--;
    }
    void print_counter() {
        std::cout << this->count << std::endl;
    }
    void default_counter() {
        this->count = 1;
    }
    void setup_counter() {
        std::string s;
        bool f;
        do {
            f = TRUE;
            std::cout << "Введите начальное значение счётчика: ";
            try {
                std::cin >> s;
                this->count = static_cast<double>(std::stoi(s));
            }
            catch (const std::invalid_argument&) {
                std::cout << "Неверный ввод!" << std::endl;
            }
        } while (f == FALSE);
    }
    Counter() {
        count = 1;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Counter counter;
    std::string operation;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> operation;
    if (operation == "да") counter.setup_counter();
    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> operation;
        if (operation == "+") counter.inc();
        if (operation == "-") counter.dec();
        if (operation == "=") counter.print_counter();
    } while (operation != "x");
    std::cout << "До свидания!" << std::endl;
    system("pause");
}

