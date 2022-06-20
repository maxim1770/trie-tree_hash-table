#include <iostream>
#include <fstream>
#include "trie.cpp"
#include "dList.cpp"
#include "hash.cpp"

int main()
{
    std::ifstream input;
    std::ofstream output;
    input.open("input.txt");
    output.open("output.txt");
    if (!input.is_open() || !output.is_open()) {
        std::cout << "Files not open";
        return 0;
    }
    else {
        hashTable<word> mas(26);
        for (char i = 'a'; i <= 'z'; i++)
            mas.add(word(i));
        trieTree a(mas);
        std::string s;
        int i;
        input >> i;
        for(int j=0;j<i;j++)
        {
            input >> s;
            a.add(s);
        }
        output << a.allWords() << '\n';

        input >> i;
        for (int j = 0; j < i; j++) {
            input >> s;
            a.remove(s);
        }
        output << a.allWords() << '\n';
        
        trieTree b(mas);
        input >> i;
        for (int j = 0; j < i; j++)
        {
            input >> s;
            b.add(s);
        }
        output << b.allWords() << '\n';

        trieTree c(mas);
        c = a.merge(b);
        output << c.allWords() << '\n';
    }
    return 0;
}