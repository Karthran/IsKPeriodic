#include <iostream>
#include <vector>

#include "Utils.h"

auto isOKSelect() -> bool
{
    char select;
    std::cin >> select;
    if (select != 'Y' && select != 'y') return false;
    return true;
}

auto getValue() -> int
{
    auto value{UNSUCCESSFUL};
    while (true)
    {
        std::cin >> value;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect value entered!" << std::endl;
            std::cout << "Try again: ";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

auto IsKPeriodic(const std::string& string, int period) -> bool
{
    auto size{static_cast<int>(string.size())};

    if (size < 2) return false;

    auto j{period};
    auto result{true};

    for (auto i{0}; i < size - period; ++i, ++j) //Compare values ​​with an index difference equal to the period
    {
        if (string[i] == string[j]) continue;
        result = false;
        break;
    }
    return result;
}

auto IsPeriodic(const std::string& string, std::vector<int>& periods) -> int
{
    auto size{static_cast<int>(string.size())};
    auto lps_arr{new int[size]{}};
    auto i{1};
    auto j{0};

    if (size < 2) return 0;

    while (i < size)                    //Build LPS array (Longest Preffix Suffix)
    {                                   // ABABC 
        if (string[i] == string[j])     // 00120
        {
            lps_arr[i] = ++j;
            ++i;
        }
        else
        {
            if (j != 0) j = lps_arr[j - 1];
            else lps_arr[i++] = 0;
        }
    }

    auto period{0};
    auto current_item{-1};

    for (auto i{0}; i < size; ++i)        // Looking for an index with which starts a constant increase values
    {                                     // 0 0 1 2 0 1 2 3 4 3 4 5 6 7 8 9 ...              
        if (lps_arr[i] == 0) ++period;    //                   ^ 
        else
        {
            if (current_item >= lps_arr[i])          //                                                           |
            {                                        //                                         indices   0 1 2 3 4 5 6 7 8 9 ...
                if (lps_arr[i] == 0) period = i + 1; // Correct period if zero goes after non-zero value (0 0 1 2 0 1 2 3 4 3 4 5 6 7 8 9 ...)
                else period = i - lps_arr[i] + 1;    // Correct period = index - (lps_arr[index] - 1)                   ^<--^     
            }
            else current_item = lps_arr[i];
        }
    }

    if (period + current_item != size || current_item % period) return 0;

    auto periods_in_size = size / period;
    int iterations = periods_in_size / 2;

    periods.push_back(period);
    auto number_of_periods{1};

    for (auto i{1}; i < iterations; ++i) //Finding All Divisors of a periods_in_size
    {
        if (periods_in_size % (i + 1)) continue;
        periods.push_back(period * (i + 1));
        number_of_periods++;
    }

    delete[] lps_arr;
    return number_of_periods;
}
