#include <iostream>
#include <vector>
#include <iomanip>

#include "Utils.h"
#include "IsKPeriodic.h"


auto run_IsKPeriodic() -> void
{
    std::string string;
    std::cout << "Enter the string: ";
    std::cin >> string;
    std::cout << "Enter the expected period: ";
    auto period{getValue()};
    
    auto result{IsKPeriodic(string, period)};
    if (result)
        std::cout << "The string is periodic, period: " << period << std::endl;
    else
        std::cout << "The string is not periodic." << std::endl;
}

auto run_IsPeriodic() -> void 
{
    std::string string;
    std::cout << "Enter the string: ";
    std::cin >> string;
    std::vector<int> periods;

    auto number_of_periods{IsPeriodic(string, periods)};

    if (number_of_periods)
    {
        std::cout << "The string is periodic, has " << number_of_periods << " period(s) " << std::endl;
        for (auto i{0}; i < number_of_periods; ++i)
        {
            std::cout << std::setw(3) << std::setfill(' ') << std::right << periods[i] << " - " << string.substr(0, periods[i]) << std::endl; 
        }

    }
    else
        std::cout << "The string is not periodic." << std::endl;
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

