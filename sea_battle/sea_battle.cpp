// sea_battle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

//функция заполнения булевского поля
void field(bool boolean_field[10][10], int x, int y)
{
    boolean_field[x - 1][y - 1] = true;
}

// функция корректности ввода A
int correct_of_input_A(int a)
{
    while (a < 1 || a >10)
    {
        std::cout << "incorrect input!!!" << std::endl;
        std::cout << "enter coordinates from 1 to 10:  ";
        std::cin >> a;

    }
    return a;
}

// функция корректности ввода B
int correct_of_input_B(int b)
{
    while (b < 1 || b >10)
    {
        std::cout << "incorrect input!!!" << std::endl;
        std::cout << "enter coordinates from 1 to 10:  ";
        std::cin >> b;

    }
    return b;
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

// функция проверки корректности расстановки кораблей
bool correction(int a, int b, int x, int y,bool boolean_field[10][10])
{
    // проверка на горизонтальное расположение корабля
    if (a - x == 0 && b - y <  0)
    {
        for (; b <= y; b++)
        {
            if (boolean_field[a][b] == true)
            {
                return false;
            }  
        }
    }

    if (a - x == 0 && b - y > 0)
    {
        for (; b >= y; b--)
        {
            if (boolean_field[a][b] == true)
            {
                return false;
            }
        }
    }
    // Проверка на вертикальное расположение
    if (a - x < 0 && b - y == 0)
    {
        for (; a <= x; a++)
        {
            if (boolean_field[a][b] == true)
            {
                return false;
            }
        }
    }

    if (a - x > 0 && b - y == 0)
    {
        for (; a >= x; a--)
        {
            if (boolean_field[a][b] == true)
            {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    bool boolean_field[10][10]{};  //создаем булевское поле
    int a=0, b=0; // координаты начала корабля
    int x=0, y=0; // координаты конца корабля

    // Ввод четырех однопалубных кораблей
    for(int i = 0; i < 4 ; i++)
    {
        std::cout << "enter the coordinates of 1 deck ship using a space or enter: " << std::endl;

        std::cin >> x >> y;
       

        correct_of_input_X(x); // проверка корректности ввода x;
        correct_of_input_Y(y); // проверка корректности ввода y;
        field(boolean_field, x, y);
    }
    // Ввод трех двухпалубных кораблей
    for (int i = 0; i < 3; i++)
    {
        std::cout << "enter the coordinates of 2 deck ship using a space or enter: " << std::endl;

        std::cin >> x >> y;
        std::cin >> a >> b;
        correct_of_input_X(x);
        correct_of_input_Y(y);
        correct_of_input_A(a);
        correct_of_input_B(b);

    }
   

    std::cout << boolean_field[0][0];
    std::cout << boolean_field[1][1];
    std::cout << boolean_field[2][2];
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
