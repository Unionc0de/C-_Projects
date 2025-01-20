#include <iostream>         // Подключение библиотеки для ввода/вывода
#include <windows.h>        // Подключение библиотеки Windows API для работы с файлами и папками
#include <string>

using namespace std;        // Использование пространства имен std для упрощения записи

int main() {
    // Ввод пути к папке от пользователя
    setlocale(LC_ALL, "rus");
    string path;
    cout << "Введите путь к папке: ";
    cin>>path;

    // Добавляем шаблон "\*" для поиска всех файлов/папок в директории
    path += "\\*";

    // Структура для хранения информации о файле или папке
    WIN32_FIND_DATAA findFileData;

    // Функция FindFirstFileA возвращает дескриптор первого файла в папке
    HANDLE hFind = FindFirstFileA(path.c_str(), &findFileData);

    // Проверяем, удалось ли открыть папку
    if (hFind == INVALID_HANDLE_VALUE) {
        cerr << "Ошибка при открытии директории! Проверьте путь." << endl;
        return 1; // Завершаем программу с кодом ошибки
    }
    else {
        // Цикл для перебора всех файлов и папок
        do {
            // Выводим имя текущего файла или папки
            cout << findFileData.cFileName << endl;
        } while (FindNextFileA(hFind, &findFileData) != 0); // Переходим к следующему файлу/папке

        // Закрываем дескриптор, чтобы освободить ресурсы
        FindClose(hFind);
    }

    return 0; // Успешное завершение программы
}
