#include "ConferenceRoom.h"
#include "Room.h"
#include "Aircondition.h"
#include "Projector.h"
#include "Screen.h"
#include "Company.h"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

ConferenceRoom::ConferenceRoom() {
    roomType = "Conference Room";
    chairNumber = 100;
    projectorDigital = new Projector("digital");
    areWindowsOpen = false;
    cout << "Constructor of ConferenceRoom class is called." << endl;
}

ConferenceRoom::ConferenceRoom(const ConferenceRoom &conferenceRoom) {
    roomType = conferenceRoom.roomType;
    aircondition = conferenceRoom.aircondition;
    projectorDigital = conferenceRoom.projectorDigital;
    screen = conferenceRoom.screen;
    chairNumber = conferenceRoom.chairNumber;
    cout << "Called coping constructor for ConferenceRoom." << endl;
}

ConferenceRoom::~ConferenceRoom() {
    delete projectorDigital;
    cout << "Destructor of ConferenceRoom object is called." << endl;
}

void ConferenceRoom::openWindows() {
    if (areWindowsOpen == false) {
        cout << "Windows have been closed, so they will be open in a moment." << endl;
        areWindowsOpen = true;
    } else {
        cout << "Windows have been opened." << endl;
    }
}

string ConferenceRoom::getRoomTypeName() {
    return roomType;
}

void ConferenceRoom::closeWindows() {
    if (areWindowsOpen == false) {
        cout << "Windows have been closed." << endl;
    } else {
        cout << "Windows have been opened, so they will be closed in a moment." << endl;
        areWindowsOpen = false;
    }
}

void ConferenceRoom::closeAllInRoom() {
    cout << "Movie is ended. Everything in " << roomType << " is turn off." << endl;
    if (projectorDigital != NULL) {
        projectorDigital->turnOff();
    }
    turnOffAircondition();
    closeWindows();
}

void ConferenceRoom::setNumberOfChairs() {
    cout << "Write how many chairs should be in: ";
    cin >> chairNumber;
    cout << endl;
}

int ConferenceRoom::getNumberOfChairs() {
    cout << "In the room will be " << chairNumber << "." << endl;
    return chairNumber;
}

void ConferenceRoom::readParamsFromConsole() {
    Room::readParamsFromConsole();
    readNumberOfChairs();
    readOpenCloseWindowsFromConsole();
    readListOfCompaniesFromConsole();
}

void ConferenceRoom::readListOfCompaniesFromConsole() {
    cout
            << "Would you like to write names of companies which will rent his Conference Room in next week? (Write y or n)"
            << endl;
    string yesNo;
    int amountOfCompanies;
    do {
        cin >> yesNo;
        cout << endl;
        if (yesNo == "y") {

            cout << "How many companies do you want to write on list (7 or less -- one company for one day of week)?"
                 << endl;
            do {
                cin >> amountOfCompanies;
                if (cin.fail()) {
                    amountOfCompanies = 100;
                    cin.clear();
                    string s;
                    cin >> s;
                }
                cout << endl;
                if (amountOfCompanies < 1 || amountOfCompanies > 7) {
                    cout << "Wrong ansewr. Try again." << endl;
                }
            } while (amountOfCompanies < 1 || amountOfCompanies > 7);
            vector<Company> listOfCompany;
            for (int companyNumber = 1; companyNumber <= amountOfCompanies; companyNumber++) {
                Company company;
                cout << "Write name of company: " << endl;
                cin >> company.companyName;
                cout << endl;
                do {
                    cout << "Write number of week's day (from 1 to 7): " << endl;
                    int rdn = 10;
                    cin >> rdn;
                    if (cin.fail()) {
                        rdn = 0;
                        cin.clear();
                        string s;
                        cin >> s;
                    }
                    cout << endl;
                    vector<Company>::iterator ir;
                    for (ir = listOfCompany.begin(); ir != listOfCompany.end(); ir++) {
                        if (rdn == ir->rentDayNumber) {
                            rdn = rdn + 10;
                            cout << "This day is occupied. Choose another day." << endl;
                        }
                    }
                    company.rentDayNumber = rdn;
                } while (company.rentDayNumber < 1 || company.rentDayNumber > 7);
                listOfCompany.push_back(company);
            }
            sort(listOfCompany.begin(), listOfCompany.end(), sortByName);
            cout << "Companies sort by name: \n Name\tDay of week\n";
            for_each(listOfCompany.begin(), listOfCompany.end(), showListName);

            sort(listOfCompany.begin(), listOfCompany.end(), sortByRentDay);
            cout << "Companies sort by number of rent day: \nDay\tName\n";
            vector<Company>::iterator ir;
            for (ir = listOfCompany.begin(); ir != listOfCompany.end(); ir++)
                cout << ir->rentDayNumber << "\t" << ir->companyName << endl;
            //for_each(listOfCompany.begin(), listOfCompany.end(), showListDay);
            addCompaniesToListOfCompaniesFromConsole(listOfCompany, amountOfCompanies);
        } else if (yesNo == "n") {
        } else {
            cout << "It is wrong answer. Try again." << endl;
        }
    } while (yesNo != "y" && yesNo != "n");

}

void
ConferenceRoom::addCompaniesToListOfCompaniesFromConsole(vector<Company> listOfCompany, int lengthOfBegginingVector) {
    cout << "Would you like to add more companies? (Write y or n)" << endl;
    string yesNo;
    int numberOfAddCompany = 7 - lengthOfBegginingVector;
    int amountOfCompanies;
    do {
        cin >> yesNo;
        cout << endl;
        if (yesNo == "y") {

            cout
                    << "How many companies do you want to add to list (on the list can be max 7 companies, so you can add max "
                    << numberOfAddCompany << " companies)?" << endl;
            do {
                cin >> amountOfCompanies;
                if (cin.fail()) {
                    amountOfCompanies = 0;
                    cin.clear();
                    string s;
                    cin >> s;
                }

                cout << endl;
                if (amountOfCompanies + numberOfAddCompany < 1 || amountOfCompanies + numberOfAddCompany > 7) {
                    cout << "Wrong answer. Try again." << endl;
                }
            } while (amountOfCompanies < 1 || amountOfCompanies > 7);

            for (int companyNumber = 1; companyNumber <= amountOfCompanies; companyNumber++) {
                Company company;
                cout << "Write name of company: " << endl;
                cin >> company.companyName;
                cout << endl;
                do {
                    cout << "Write number of week's day (from 1 to 7): " << endl;
                    int rdn = 10;
                    cin >> rdn;
                    if (cin.fail()) {
                        rdn = 0;
                        cin.clear();
                        string s;
                        cin >> s;
                    }
                    cout << endl;
                    vector<Company>::iterator ir;
                    for (ir = listOfCompany.begin(); ir != listOfCompany.end(); ir++) {
                        if (rdn == ir->rentDayNumber) {
                            rdn = rdn + 10;
                            cout << "This day is occupied. Choose another day." << endl;
                        }
                    }
                    company.rentDayNumber = rdn;
                } while (company.rentDayNumber < 1 || company.rentDayNumber > 7);
                listOfCompany.push_back(company);
            }
            sort(listOfCompany.begin(), listOfCompany.end(), sortByName);
            cout << "Companies sort by name: \n Name\tDay of week\n";
            for_each(listOfCompany.begin(), listOfCompany.end(), showListName);

            sort(listOfCompany.begin(), listOfCompany.end(), sortByRentDay);
            cout << "Companies sort by number of rent day: \nDay\tName\n";
            vector<Company>::iterator ir;
            for (ir = listOfCompany.begin(); ir != listOfCompany.end(); ir++)
                cout << ir->rentDayNumber << "\t" << ir->companyName << endl;
            //for_each(listOfCompany.begin(), listOfCompany.end(), showListDay);
            addCompaniesToListOfCompaniesFromConsole(listOfCompany, amountOfCompanies);
        } else if (yesNo == "n") {
        } else {
            cout << "It is wrong answer. Try again." << endl;
        }
    } while (yesNo != "y" && yesNo != "n");

}

/*bool ConferenceRoom::operator<(const Company &c1, const Company & c2) {
    if (c1.companyName < c2.companyName) {
        return true;
    } else if (c1.companyName == c2.companyName && c1.rentDayNumber < c2.rentDayNumber) {
        return true;
    } else {
        return false;
    }
}*/




bool sortByName(const Company &c1, const Company &c2) {
    if (c1.companyName < c2.companyName) {
        return true;
    } else if (c1.companyName == c2.companyName && c1.rentDayNumber < c2.rentDayNumber) {
        return true;
    } else {
        return false;
    }
}

bool sortByRentDay(const Company &c1, const Company &c2) {
    if (c1.rentDayNumber < c2.rentDayNumber) {
        return true;
    } else if (c1.rentDayNumber == c2.rentDayNumber && c1.companyName < c2.companyName) {
        return true;
    } else {
        return false;
    }
}

void showListName(const Company &cc) {
    cout << cc.companyName << "\t" << cc.rentDayNumber << endl;
}

void showListDay(const Company &cc) {
    cout << cc.rentDayNumber << "\t" << cc.companyName << endl;
}

void ConferenceRoom::readNumberOfChairs() {
    string yesNo;
    do {
        cout << "In this Conference Room are " << chairNumber
             << " chairs. Would you like to be another number of chairs? (Write y or n)" << endl;
        cin >> yesNo;
        cout << endl;
        if (yesNo == "y" || yesNo == "n") {
            if (yesNo == "y") {
                cout << "So how many chairs should be in this Conference Room: " << endl;

                do {
                    cin >> chairNumber;
                    cout << endl;
                    if (cin.fail()) {
                        chairNumber = 1000;
                        cin.clear();
                        string s;
                        cin >> s;
                    }
                    if (chairNumber >= 1 && chairNumber <= 500) {
                        cout << "You choose: " << chairNumber << " chairs." << endl;
                    } else {
                        cout << "Wrong answer. Try agin.  Value for number of chairs should be between 1 and 500: "
                             << endl;
                    }
                } while (chairNumber < 1 || chairNumber > 500);
            }
        } else {
            cout << "It is wrong answer. Try again." << endl;
        }
    } while (yesNo != "y" && yesNo != "n");
}

void ConferenceRoom::readOpenCloseWindowsFromConsole() {
    string yesNo;
    if (areWindowsOpen) {
        cout << "Windows are opened. Do you want to close them? (Write y or n)" << endl;
        do {
            cin >> yesNo;
            cout << endl;
            if (yesNo == "y" || yesNo == "n") {
                if (yesNo == "y")
                    closeWindows();
            } else {
                cout << "It is wrong answer. Try again." << endl;
            }
        } while (yesNo != "y" && yesNo != "n");
    } else {
        cout << " Windows are closed. Do you want to open it? (Write y or n)" << endl;
        do {
            cin >> yesNo;
            cout << endl;
            if (yesNo == "y" || yesNo == "n") {
                if (yesNo == "y")
                    openWindows();
            } else {
                cout << "It is wrong answer. Try again." << endl;
            }
        } while (yesNo != "y" && yesNo != "n");
    }
}

void ConferenceRoom::write(ostream &os) const {
    cout << "Saving conference room" << endl;
    Room::write(os);
    os << chairNumber << endl;
}

void ConferenceRoom::read(istream &is) {
    Room::read(is);
    is >> chairNumber;
    cout << "Reading conference room" << endl;
}

// Method for getting new projector in cinema room
void ConferenceRoom::operator+=(Projector *proj) {
    if (projectorDigital == NULL) {
        projectorDigital = proj;
        cout << "There is " << projectorDigital->getProjectorType() << " projector set in this cinema room." << endl;
    } else {
        cout << "Cinema room has already " << projectorDigital->getProjectorType() << " projector." << endl;
    }
}

// Method used for example when projector is borken and must be removed
/*void ConferenceRoom::operator-= (Projector* projDel) {
        if (projDel != NULL) {
            cout << "Projector " << projectorDigital->getProjectorType() << " was removed." << endl;
            projDel = NULL;
        } else {
            cout << "Cinema room has no" << projectorDigital->getProjectorType() << " projector." << endl;
        }
}*/

bool ConferenceRoom::operator==(ConferenceRoom const &cro1) const {
    //ro1.chairNumber== chairNumber
    if (Room::operator==(cro1) /* && co tam jeszce chce*/) {
        cout << "Saved object and read object are equal." << endl;
        return true;
    } else {
        cout << "Saved objcet and read object are not equal." << endl;
        return false;
    }
}
