// Ex1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Header.h"

std::ostream& operator<<(std::ostream& os, std::vector<List<int>>& vec)
{
    for (int i = 0; i < vec.size(); i++)
        os <<  i << ": " << vec[i];
    os << '\n';
    return os;
};

int main()
{
    //CreateMatrix();

    /*
    auto matrix = ReadMatrixFormFile();

    std::cout << "Graph\n";
    auto link = ConvertMatrixFromAdjacency(matrix);
    std::cout << link << std::endl;

    std::cout << "Main tree in this Graph (width)\n";
    auto mainTreeLinkWidth = MainTreeWigth(link);
    std::cout << mainTreeLinkWidth;

    std::cout << "Main tree in this Graph (width)\n";
    auto mainTreeLinkHeight = MainTreeHeight(link);
    std::cout << mainTreeLinkHeight;
    */

    Tree<int> tree = { 1, 2, 3, 4 } ;

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
