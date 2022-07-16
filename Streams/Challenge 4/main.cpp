#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

int main()
{
    std::ifstream in_f("romeoandjuliet");
    if(!in_f)
    {
        std::cerr << "Error while opening input file occured\n";
        return 1;
    }

    std::ofstream out_f("romeoandjuliet_res");
    if(!out_f)
    {
        std::cerr << "Error while opening output file occured\n";
        return 2;
    }

    std::string temp;
    int line_counter = 0;
    while(std::getline(in_f, temp))
    {
        if(temp != "")
            out_f << std::setw(6) << std::left << ++line_counter;
        out_f << temp << std::endl;
    }

    std::cout << "Copying complete!" << std::endl;

    in_f.close();
    out_f.close();
    return 0;
}