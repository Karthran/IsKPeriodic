#pragma once

#define UNSUCCESSFUL -1

auto isOKSelect() -> bool;
auto getValue() -> int;
// Checks if a periodic string with period K
auto IsKPeriodic(const std::string& string, int period) -> bool;
// Searches for periods in a string, returns the number of periods found
auto IsPeriodic(const std::string& string, std::vector<int>& periods) -> int;
