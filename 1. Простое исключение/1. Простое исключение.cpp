// 1. Простое исключение.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>
#include <exception>

int function(std::string str, int forbidden_length) {
    //Эта функция должна возвращать длину переданной строки, если эта длина не равна значению переданного параметра forbidden_length.
    if (str.length() != forbidden_length) {
        return str.length(); // возвращаем длину строки, если она не равна запрещенной длине
    }
    else {
        //кидаем исключение
        throw std::runtime_error( "Вы ввели слово запретной длины!До свидания");
        //всё что ниже строчки с выбросом исключения - не выполняется
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    std::cout << "Введите запретную длину : " << std::endl;
    int ban{ 0 };
    std::cin >>ban;
    std::cout << "Введите слово : " << std::endl;
    std::string str;
    std::cin >> str;
    while (str.length() != ban) {
        std::cout << "Длина слова " << str << "  " << function(str, ban) << std::endl; // вывод длины строки
        std::cout << std::endl;
        std::cout << "Введите слово : " << std::endl;
        std::cin >> str;
    }
    // перехват выброш исключ
    try
    {
        function(str, ban);
    }
    catch (const std::exception& bad_length)
    {
        std::cout << bad_length.what() << std::endl;
    }

     
        
    return 0;
   //std::string str = "Hello, world!";
   // int len = static_cast<int>(str.length()); // вычисление длины строки
    //std::cout << "Длина строки: " << len << std::endl; // вывод длины строки
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
