// Ex1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

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

    
    const std::string path1 = "file1.txt";
    /*
    std::ofstream fout(path1);

    std::cout << "Input count numbers\n";
    int count = 0;
    std::cin >> count;

    std::cout << "Input numbers\n";
    for (int i = 0; i < count; i++)
    {
        int x;
        std::cin >> x;
        fout << x << " ";
    }
    fout.close();
    */

   /*
    Tree<int> tree;
    std::ifstream fin(path1);
    int el;
    while (fin >> el)
        tree.Add(el);
    
    fin.close();

    CountElement(tree.GetRoot());
    std::cout << tree.CountOf(4) << '\n';
    std::cout << tree.CountOf(0) << '\n';
    */

    
    Tree<int> tr3 = { 1, 2, 3, 4, 2, 3, 5 };
    Tree<int> tr4 = { 1, 2, 3, -1, -2, -3};

    PrintGraphReverse(tr4);
    PrintGraph(tr4.GetRoot());
    /*
    std::cout << tr3.Eqval(tr4.GetRoot());
    */
    /*
    std::cout << tr4.Height();
    */
    const std::string pathWords1 = "words1.txt";
    const std::string pathWords2 = "words2.txt";

    /*
    std::cout << "Input string 1\n";
    std::string str1;
    std::getline(std::cin, str1);

    std::cout << "Input string 2\n";
    std::string str2;
    std::getline(std::cin, str2);

    std::ofstream fout1(pathWords1);
    fout1 << str1;
    fout1.close();

    std::ofstream fout2(pathWords2);
    fout2 << str2;
    fout2.close();
    */

    Tree<std::string> tr71;
    Tree<std::string> tr72;
    std::string sup;

    std::ifstream fin1(pathWords1);
    while (fin1 >> sup) tr71.Add(sup);
    fin1.close();

    std::ifstream fin2(pathWords2);
    while (fin2 >> sup) tr72.Add(sup);
    fin2.close();

    PrintGraph(tr71.GetRoot());
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
