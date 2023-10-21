// sea_battle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
// sea_battle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
bool boolean_field[10][10];     //создаем булевское поле

void proverka()
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            bool b = boolean_field[i][j];
            std::cout << b << "\t";
        }
        std::cout << '\n';
    }
}


//функция заполнения булевского поля
void field( int a, int b , int x, int y)
{
    if (a - x == 0 && b - y < 0)
    {
        for (; b < y; b++)
        {
            boolean_field[a - 1][b - 1] = true;
        }
    }

    if (a - x == 0 && b - y > 0)
    {
        for (; b > y; b--)
        {
            boolean_field[a - 1][b - 1] = true;    
        }
    }

    if (a - x < 0 && b - y == 0)
    {
        for (; a < x; a++)
        {
            boolean_field[a - 1][b - 1] = true;
        }
    }

    if (a - x > 0 && b - y == 0)
    {
        for (; a > x; a--)
        {
            boolean_field[a - 1][b - 1] = true;
        }
    }

    if (a == x && b == y)
    {
        boolean_field[a - 1][b - 1] = true;
    }
}

// функция проверки корректности расстановки кораблей
bool correction(int a, int b, int x, int y)
{
    // проверка на диагональное расположение корабля
    if (a - x != 0 && b - y != 0)
    {
        return false;
    }
    // проверка на горизонтальное расположение корабля
    if (a - x == 0 && b - y < 0)
    {
        for (; b <= y; b++)
        {
            if (boolean_field[a - 1][b - 1] == true)
            {
                return false;
            }
        }
    }

    if (a - x == 0 && b - y > 0)
    {
        for (; b >= y; b--)
        {
            if (boolean_field[a - 1][b - 1] == true)
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
            if (boolean_field[a - 1][b - 1] == true)
            {
                return false;
            }
        }
    }

    if (a - x > 0 && b - y == 0)
    {
        for (; a >= x; a--)
        {
            if (boolean_field[x - 1][b - 1] == true)
            {
                return false;
            }
        }
    }

    if (a == x && b == y)
    {
        if (boolean_field[a - 1][b - 1] == true)
        {
            return false;
        }
    }
    return true;
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




int main()
{
    proverka();
     
    int a = 0, b = 0; // координаты начала корабля
    int x = 0, y = 0; // координаты конца корабля

    // Ввод четырех однопалубных кораблей
    for (int i = 0; i < 4; )
    {
        std::cout << "enter the coordinates of 1 deck " << i+1 <<" ship using a enter : " << std::endl;

        std::cin >> a;
        a = correct_of_input_X(a);    // проверка корректности ввода x;
        std::cin >> b;
        b = correct_of_input_Y(b);    // проверка корректности ввода y;
        x = a;
        y = b;
        if (correction(a, b, x, y))   // если ввод корректен
        {
            field(a, b, x, y);        // заполняем  булевское поле
            i++;
        }
        else if (!correction(a, b, x, y)) // если ввод не корректен
        {
            std::cout << "sorry, but the place is busy";
        } 
        proverka();
    }


    // Ввод трех двухпалубных кораблей
    for (int i = 0; i < 3; )
    {
        std::cout << "enter the coordinates of 2 deck " << i + 1 << " ship using a enter: \n\n";

        std::cout << "enter the coordinates of the BEGINNING of the ship using enter: \n";
        // проверка корректности ввода начала корабля
        std::cin >> a;
        a =  correct_of_input_X(a);
        std::cin >> b;
        b = correct_of_input_Y(b);
        // проверка корректности ввода конца корабля
        std::cout << "enter the coordinates of the END of the ship using enter \n";
        std::cin >> x;
        x = correct_of_input_A(x);
        std::cin >> y;
        y = correct_of_input_B(y);

        // если корабль БОЛЬШЕ , ЧЕМ ДВУХПАЛУБНЫЙ
        if( abs(a-x) != 1 && b - y ==0 || a - x == 0 && abs(b - y) != 1)
        {
            std::cout << " This ship is NOT DOUBLE-decker!!\n";
        }

        // если с расположением все в порядке
        else 
        {
            if (correction(a, b, x, y)) // если ввод корректен
            {
                field(a, b, x, y);      // заполняем булевское поле
                i++;
            }
            else if (!correction(a, b, x, y))  // если ввод не корректен
            {
                std::cout << "sorry, but the place is busy\n";
            }
        }
        proverka();
    }

    // Ввод ДВУХ трехпалубных кораблей
    for (int i = 0; i < 2; )
    {
        std::cout << "enter the coordinates of 3 deck " << i + 1 << " ship using a enter: \n\n";

        std::cout << "enter the coordinates of the BEGINNING of the ship using enter: \n";
        // проверка корректности ввода начала корабля
        std::cin >> a;
        a = correct_of_input_X(a);
        std::cin >> b;
        b = correct_of_input_Y(b);
        // проверка корректности ввода конца корабля
        std::cout << "enter the coordinates of the END of the ship using enter \n";
        std::cin >> x;
        x = correct_of_input_A(x);
        std::cin >> y;
        y = correct_of_input_B(y);

        // если корабль БОЛЬШЕ , ЧЕМ ТРЕХПАЛУБНЫЙ!
        if (abs(a - x) != 2 && b - y == 0 || a - x == 0 && abs(b - y) != 2)
        {
            std::cout << " This ship is NOT THREE-decker!!\n";
        }

        // если с расположением все в порядке
        else
        {
            if (correction(a, b, x, y)) // если ввод корректен
            {
                field(a, b, x, y);      // заполняем булевское поле
                i++;
            }
            else if (!correction(a, b, x, y))  // если ввод не корректен
            {
                std::cout << "sorry, but the place is busy\n";
            }
        }
        proverka();
    }

    // Ввод КРЕЙСЕРА
    for (int i = 0; i < 1; )
    {
        std::cout << "enter the coordinates of 4 deck " << i + 1 << " ship using a enter: \n\n";

        std::cout << "enter the coordinates of the BEGINNING of the ship using enter: \n";
        // проверка корректности ввода начала корабля
        std::cin >> a;
        a = correct_of_input_X(a);
        std::cin >> b;
        b = correct_of_input_Y(b);
        // проверка корректности ввода конца корабля
        std::cout << "enter the coordinates of the END of the ship using enter \n";
        std::cin >> x;
        x = correct_of_input_A(x);
        std::cin >> y;
        y = correct_of_input_B(y);

        // если корабль БОЛЬШЕ , ЧЕМ ЧЕТЫРЕХПАЛУБНЫЙ!
        if (abs(a - x) != 3 && b - y == 0 || a - x == 0 && abs(b - y) != 3)
        {
            std::cout << " This ship is NOT FOUR-decker!!\n";
        }

        // если с расположением все в порядке
        else
        {
            if (correction(a, b, x, y)) // если ввод корректен
            {
                field(a, b, x, y);      // заполняем булевское поле
                i++;
            }
            else if (!correction(a, b, x, y))  // если ввод не корректен
            {
                std::cout << "sorry, but the place is busy\n";
            }
        }
        proverka();
    }




   // proverka();
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
