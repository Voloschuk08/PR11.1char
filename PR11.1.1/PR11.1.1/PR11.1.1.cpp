#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функція, яка перевіряє наявність пари "no" або "on" у рядку
bool ContainsPair(const string& s) {
    return (s.find("no") != string::npos || s.find("on") != string::npos);
}

// Функція, яка замінює кожну пару "no" на "***"
string ReplaceNo(const string& s) {
    string result = s;
    size_t pos = 0;
    while ((pos = result.find("no", pos)) != string::npos) {
        result.replace(pos, 2, "***");
        pos += 3; // перемістити позицію на кінець заміни
    }
    return result;
}

int main() {
    // Введення імені файлу
    string filename;
    cout << "Enter the name of the text file: ";
    cin >> filename;

    // Відкриття файлу для читання
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    // Файл для запису результатів
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }

    string line;
    bool containsPair = false;

    // Обробка рядків файлу
    cout << "File content with replacements:" << endl;
    while (getline(inputFile, line)) {
        if (ContainsPair(line)) {
            containsPair = true;
        }
        string modifiedLine = ReplaceNo(line);
        cout << modifiedLine << endl; // Вивід замінених рядків на екран
        outputFile << modifiedLine << endl; // Запис замінених рядків у новий файл
    }

    // Закриття файлів
    inputFile.close();
    outputFile.close();

    // Підсумковий результат
    if (containsPair) {
        cout << "The file contains 'no' or 'on'." << endl;
    }
    else {
        cout << "The file does not contain 'no' or 'on'." << endl;
    }

    return 0;
}
