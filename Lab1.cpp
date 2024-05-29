#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <windows.h> 

using namespace std;

void find_max_length_words(ifstream& file) {
    set<string> max_length_words;
    int max_length = 0;
    string word;

    while (file >> word) {
        // Видаляємо пунктуацію зі слова (наприклад, коми, крапки)
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());

        if (word.length() > max_length) {
            max_length = word.length();
            max_length_words.clear();
            max_length_words.insert(word);
        }
        else if (word.length() == max_length) {
            max_length_words.insert(word);
        }
    }

    cout << "Максимальна довжина слова: " << max_length << endl;
    cout << "Слова максимальної довжини: ";
    for (const string& w : max_length_words) {
        cout << w << " ";
    }
    cout << endl;
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file;
    string path;
    // Отримати шлях до файлу від користувача
    cout << "Введіть шлях до файлу: ";
    cin >> path;

    // Відкрити файл
    file.open(path);
    if (!file) {
        cout << "Файл не може бути відкритий!\n";
        return 0;
    }
    else {
        cout << "Файл відкритий!\n";
    }

    find_max_length_words(file);
    file.close();

    return 0;
}