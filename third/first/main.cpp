/* Определить количество слов в нечетных строках текста */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream file("example.txt");
    if(file.is_open()){
        string word;
        char symbol;
        int kol_str = 1, kol_words = 0;
        while(!file.eof()){
            file >> word;
            if(kol_str % 2 != 0) kol_words++;
            file.get(symbol);
            if(symbol == '\n') kol_str++;
        }
        cout << "Кол-во слов в нечётных строках:  "  << kol_words << endl;
        file.close();
    }
    return 0;
}
