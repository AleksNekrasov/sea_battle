﻿// sea_battle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

//функция заполнения булевского поля
void field(bool boolean_field[10][10], int x, int y)
{
    boolean_field[x - 1][y - 1] = true;
}
// функция корректности ввода X
int correct_of_input_X(int x)
{
    while (x < 1 || x >10)
    {
        std::cout << "incorrect input!!!" << std::endl;
        std::cout << "enter coordinates from 1 to 10:  ";
        std::cin >> x;

    }
    return x;
}
// функция корректности ввода Y
int correct_of_input_Y(int y)
{
    while (y < 1 || y >10)
    {
        std::cout << "incorrect input!!!" << std::endl;
        std::cout << "enter coordinates from 1 to 10:  ";
        std::cin >> y;

    }
    return y;
}



int main()
{
    bool boolean_field[10][10]{};  //создаем булевское поле
    int x, y;
    std::cout << "enter x ,  y  ";

    std::cin >> x;
    std::cin >> y;

    correct_of_input_X(x);
    correct_of_input_Y(y);
    field(boolean_field, x, y);
    std::cin >> x;
    std::cin >> y;

    correct_of_input_X(x);
    correct_of_input_Y(y);
    field(boolean_field, x, y);

    std::cout << boolean_field[0][0];
    std::cout << boolean_field[3][3];

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.