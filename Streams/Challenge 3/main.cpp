#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream in_f;
    in_f.open("romeoandjuliet.txt");
    if(!in_f)
    {
        std::cerr << "Error while opening file\n";
        return 1;
    }

    std::string to_count;
    std::cout << "Enter a word to count: ";
    std::cin >> to_count;
    size_t count = 0;
    std::string temp;

    while(in_f >> temp)
    {
        if(temp.find(to_count) != std::string::npos)
           ++count;
    }

    std::cout << "Count of entries of word " << to_count << " in text: " << count;
    in_f.close();
    return 0;
}