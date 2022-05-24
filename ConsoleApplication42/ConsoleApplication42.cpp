#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    const char a[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
    const char A[] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
    const char sumb[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
    const char sumbol[] = { '!', '@', '#', '$', '%', '&', '?', '-', ' ' };

    vector<char> symbols;
    int n;
    cout << "Введите длину пароля: ";
    cin >> n;

    int choise;
    cout << "Выберите тип буквы (заглавные - 0, прописные - 1, оба варианта - 2): ";
    cin >> choise;
    if (choise == 0)
        symbols.insert(symbols.end(), A, A + sizeof(A));
    else
    {
        symbols.insert(symbols.end(), a, a + sizeof(a));
        if (choise == 2)
            symbols.insert(symbols.end(), A, A + sizeof(A));
    }

    cout << "Использовать цифры (нет - 0, да - 1): ";
    cin >> choise;
    if (choise == 1)
        symbols.insert(symbols.end(), sumb, sumb + sizeof(sumb));

    cout << "Использовать символы (нет - 0, да - 1): ";
    cin >> choise;
    if (choise == 1)
        symbols.insert(symbols.end(), sumbol, sumbol + sizeof(sumbol));

    mt19937 gen{ random_device()() };
    uniform_int_distribution<> dist(0, symbols.size() - 1);
    for (int i = 0; i < n; i++)
        cout << symbols[dist(gen)];
    cout << endl;

}
//Генератор случайных чисел std::mt19937 из <random> всегда выдает одно и то же число Добавить вопрос в закладки
//std::random_device - это генератор случайных чисел с равномерным распределением, который генерирует недетерминированные случайные числа.
//Шаблон класса описывает инклюзивное распределение, которое создает значения определяемого пользователем целочисленного типа с распределением таким образом, чтобы каждое значение было одинаково вероятным.