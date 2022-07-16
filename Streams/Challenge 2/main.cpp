#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

// Formatting parameters
    constexpr int student_column = 15;
    constexpr int score_column = 10;
    constexpr int full_length = student_column + score_column;

template<typename T>
void print_row(const std::string& left, const T& right)
{
    std::cout << std::setw(student_column) << std::left << left
            << std::setw(score_column) << std::right << right << std::endl;
}

void print_del()
{
    std::cout << std::setw(full_length) << std::setfill('-') 
            << "" << std::endl << std::setfill(' ');
}

int main()
{

    std::fstream in_f;
    in_f.open("responses.txt");
    if(!in_f)
    {
        std::cerr << "File openin failure";
        return 1;
    }

    std::string correct_ans;
    std::getline(in_f, correct_ans);

    
    print_row("Student", "Score");
    print_del();

    std::string name{}, answ{};
    int score = 0;
    int summary = 0;
    int count = 0;

    while(in_f >> name >> answ)
    {
        ++count;
        for(int i = 0; i < answ.size(); ++i)
            if(correct_ans[i] == answ[i])
                ++score;

        print_row(name, score);
        
        summary += score;
        score = 0;
    }

    print_del();

    double avg = (double)summary / count;
    std::cout << std::fixed << std::setprecision(1);

    print_row("Average score", avg);

    return 0;
}