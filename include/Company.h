#ifndef COMPANY_H
#define COMPANY_H
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Company
{
        string companyName;
        int rentDayNumber;
};
bool sortByName(const Company &c1, const Company & c2);

#endif