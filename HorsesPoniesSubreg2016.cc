#include "HorsesPoniesSubreg2016.h"

HorsesPoniesSubreg2016::HorsesPoniesSubreg2016() {
    DescBehaviour<int>* descB = new DescBehaviour<int>();
    repData = new ReportData<int>(descB);
}

HorsesPoniesSubreg2016::~HorsesPoniesSubreg2016() {
    delete repData;
}

void HorsesPoniesSubreg2016::compute() {
    vector<string> regKeys = regionMap.getKeys();
    vector<Record*> animRecSet;
    try {
        animRecSet = animalMap["Horses-Ponies"];
    } catch (string err) {
        cout << err << " in compute() function of HorsesPoniesSubreg.cc" << endl;
    }

    for (int i = 0; i < regKeys.size(); ++i) {
        if (regKeys.at(i) == "CAN") continue;

        stringstream ss;
        string row;

        int maxSubRegionIndex = 0;
        int maxSubRegionVal = 0;
        string maxRegion;
        for (int j = 0; j < animRecSet.size(); ++j) {
            if (animRecSet.at(j)->getRegion() != regKeys.at(i) || animRecSet.at(j)->getSubRegion() == "All" || animRecSet.at(j)->getYear() != 2016) continue;
            if (animRecSet.at(j)->getNumAnimals() > maxSubRegionVal) {
                maxSubRegionVal = animRecSet.at(j)->getNumAnimals();
                maxSubRegionIndex = j;
            }
        }
        if (maxSubRegionVal == 0) {
            maxRegion = " ";
        } else {
            maxRegion = animRecSet.at(maxSubRegionIndex)->getSubRegion();
        }
        ss << setw(8) << regKeys.at(i)
           << setw(35) << maxRegion << setw(10) << maxSubRegionVal << endl;
        row = ss.str();
        formatData(maxSubRegionVal, row);
    }
}

void HorsesPoniesSubreg2016::formatData(int key, string row) {
    repData->add(key, row);
}

void HorsesPoniesSubreg2016::printReport() {
    ofstream outfile("Report3.txt", ios::out);
    if (!outfile) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    stringstream ss;
    ss << setw(5) << ' ' << "SUB-REGION WITH MOST HORSES/PONIES BY REGION IN 2016" << endl
       << setw(5) << ' ' << "----------------------------------------------------" << endl
       << endl
       << *repData;

    outfile << ss.str();
    cout << endl
         << ss.str();

    repData->del();
}