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
        // ��������� ���������� � ����� (���������, ����, ������)
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

    cout << "����������� ������� �����: " << max_length << endl;
    cout << "����� ����������� �������: ";
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
    // �������� ���� �� ����� �� �����������
    cout << "������ ���� �� �����: ";
    cin >> path;

    // ³������ ����
    file.open(path);
    if (!file) {
        cout << "���� �� ���� ���� ��������!\n";
        return 0;
    }
    else {
        cout << "���� ��������!\n";
    }

    find_max_length_words(file);
    file.close();

    return 0;
}