#include <iostream>
#include <vector>
#include <iomanip>

#include "Utils.h"


auto run_IsKPeriodic() -> void
{
    std::string string;
    std::cout << "Enter the string: ";
    std::cin >> string;
    auto period{0};
    while (period <= 0)
    {
        std::cout << "Enter the expected period: ";
        period = getValue();
    }
    
    auto result{IsKPeriodic(string, period)};
    std::cout << std::endl;
    if (result)
        std::cout << period <<" is the period for this string. " << std::endl;
    else
        std::cout << period <<" is not a period for this string." << std::endl;
}

auto run_IsPeriodic() -> void 
{
    std::string string;
    std::cout << "Enter the string: ";
    std::cin >> string;
    std::vector<int> periods;

    auto number_of_periods{IsPeriodic(string, periods)};
    std::cout << std::endl;
    if (number_of_periods)
    {
        std::cout << "String is periodic, has " << number_of_periods << " period(s) " << std::endl;
        for (auto i{0}; i < number_of_periods; ++i)
        {
            std::cout << std::setw(3) << std::setfill(' ') << std::right << periods[i] << " - " << string.substr(0, periods[i]) << std::endl; 
        }

    }
    else
        std::cout << "String is not periodic." << std::endl;
}

auto main() -> int
{
    auto finish_flag{false};
    while (!finish_flag)
    {
        std::cout << std::endl;       
        std ::cout << "1.IsKPeriodic" << std::endl;
        std::cout << "2.IsPeriodic" << std::endl;
        std::cout << "3.Quit" << std::endl;
        std::cout << "Select : ";
        auto select{getValue()};
        switch (select)
        {
            case 1: run_IsKPeriodic();
                break;
            case 2: run_IsPeriodic(); 
                break;
            default: finish_flag = true;
        }
    }
    return 0;
}

//abacabacabaabacabacaba
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
//abcabcabcabcabc
//abcabcabdabcabfabcabcabcabdabcabfabcabcabcabdabcabfabcabcabcabdabcabfabc