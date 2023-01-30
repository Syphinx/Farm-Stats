#include "AnimalCanBreakdown.h"

AnimalCanBreakdown::AnimalCanBreakdown() {
    AscBehaviour<float>* ascB = new AscBehaviour<float>();
    repData = new ReportData<float>(ascB);
}

AnimalCanBreakdown::~AnimalCanBreakdown() {
    delete repData;
}

void AnimalCanBreakdown::compute() {
    vector<int> yearKeys = yearMap.getKeys();
    vector<string> animKeys = animalMap.getKeys();
    float denom11, denom16 = 0;
    getAnimDenom(2011, denom11);
    getAnimDenom(2016, denom16);

    for (int i = 0; i < animKeys.size(); ++i) {
        stringstream ss;
        string row;

        ss << setw(20) << setfill(' ') << animKeys.at(i) << " ";
        float nume11, nume16, pChange = 0;
        bool flag = false;
        for (int j = 0; j < yearKeys.size(); ++j) {
            vector<Record*> currRecSet;
            try {
                currRecSet = yearMap[yearKeys.at(j)];
            } catch (string err) {
                cout << err << " in compute() function of AnimalCanBreakdown.cc" << endl;
            }
            for (int k = 0; k < currRecSet.size(); ++k) {
                if (currRecSet.at(k)->getRegion() != "CAN" || currRecSet.at(k)->getAnimalType() != animKeys.at(i)) continue;
                if (yearKeys.at(j) == 2011) {
                    flag = true;
                    nume11 = currRecSet.at(k)->getNumAnimals() / denom11 * 100;
                    ss << setw(6) << setprecision(1) << fixed << nume11 << " ";
                } else {
                    flag = false;
                    nume16 = currRecSet.at(k)->getNumAnimals() / denom16 * 100;
                    ss << setw(6) << setprecision(1) << fixed << nume16 << " ";
                }
            }
        }
        if (flag) {
            nume16 = 0;
            ss << setw(6) << setprecision(1) << fixed << nume16 << " ";
        }
        pChange = nume16 - nume11;
        ss << showpos << setw(7) << pChange << endl;
        row = ss.str();
        formatData(pChange, row);
    }
}

void AnimalCanBreakdown::getAnimDenom(int year, float& denom) {
    float currDenom = 0;

    vector<Record*> currRecSet;
    try {
        currRecSet = yearMap[year];
    } catch (string err) {
        cout << err << " in getAnimDenom() function of AnimalCanBreakdown.cc" << endl;
    }
    for (int i = 0; i < currRecSet.size(); ++i) {
        if (currRecSet.at(i)->getRegion() != "CAN") continue;
        currDenom += currRecSet.at(i)->getNumAnimals();
    }
    denom = (currDenom == 0) ? 1 : currDenom;
}

void AnimalCanBreakdown::formatData(float key, string row) {
    repData->add(key, row);
}

void AnimalCanBreakdown::printReport() {
    ofstream outfile("Report2.txt", ios::out);
    if (!outfile) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    stringstream ss;
    ss << setw(5) << ' ' << "PERCENTAGE CHANGE OF ANIMALS (2011-2016)" << endl
       << setw(5) << ' ' << "----------------------------------------" << endl
       << endl
       << setw(23) << " " << 2011 << setw(7) << 2016 << setw(10) << "Change" << endl
       << endl
       << *repData;

    outfile << ss.str();
    cout << endl
         << ss.str();

    repData->del();
}