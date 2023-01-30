#include "FarmRegBreakdown.h"

FarmRegBreakdown::FarmRegBreakdown() {
    DescBehaviour<float>* descB = new DescBehaviour<float>();
    repData = new ReportData<float>(descB);
}

FarmRegBreakdown::~FarmRegBreakdown() {
    delete repData;
}

void FarmRegBreakdown::compute() {
    vector<string> regKeys = regionMap.getKeys();
    vector<string> animKeys = animalMap.getKeys();

    computeDenoms();

    float totalAnimDenom = 0;
    grabDenom("Total", totalAnimDenom);

    for (int i = 0; i < regKeys.size(); ++i) {
        if (regKeys.at(i) == "CAN") continue;
        vector<Record*> regRecSet;
        try {
            regRecSet = regionMap[regKeys.at(i)];
        } catch (string err) {
            cout << err << " in compute() function of FarmRegBreakdown.cc" << endl;
        }
        float totalAnimNumer = 0;
        stringstream ss;
        string row;

        ss << setw(6) << setfill(' ') << regKeys.at(i);

        for (int j = 0; j < animKeys.size(); ++j) {
            float currAnimNumer = 0;
            float currAnimDenom = 0;
            grabDenom(animKeys.at(j), currAnimDenom);

            for (int k = 0; k < regRecSet.size(); ++k) {
                if (regRecSet.at(k)->getSubRegion() == "All" && regRecSet.at(k)->getYear() == 2016 && regRecSet.at(k)->getAnimalType() == animKeys.at(j)) {
                    currAnimNumer += regRecSet.at(k)->getNumFarms();
                }
            }
            totalAnimNumer += currAnimNumer;
            ss << setw(12) << setfill(' ') << setprecision(1) << fixed << currAnimNumer / currAnimDenom * 100;
        }
        ss << setw(12) << setfill(' ') << setprecision(1) << fixed << totalAnimNumer / totalAnimDenom * 100 << endl;
        row = ss.str();
        formatData((totalAnimNumer / totalAnimDenom * 100), row);
    }
}

void FarmRegBreakdown::computeDenoms() {
    vector<string> regKeys = regionMap.getKeys();
    vector<string> animKeys = animalMap.getKeys();

    float totalAnimDenom = 0;

    for (int i = 0; i < animKeys.size(); ++i) {
        float currAnimDenom = 0;
        for (int j = 0; j < regKeys.size(); ++j) {
            if (regKeys.at(j) == "CAN") continue;
            vector<Record*> regRecSet;
            try {
                regRecSet = regionMap[regKeys.at(j)];
            } catch (string err) {
                cout << err << " in computeDenoms() function of FarmRegBreakdown.cc" << endl;
            }
            for (int k = 0; k < regRecSet.size(); ++k) {
                if (regRecSet.at(k)->getAnimalType() == animKeys.at(i) && regRecSet.at(k)->getSubRegion() == "All" && regRecSet.at(k)->getYear() == 2016) {
                    currAnimDenom += regRecSet.at(k)->getNumFarms();
                }
            }
        }
        totalAnimDenom += currAnimDenom;
        currAnimDenom = currAnimDenom == 0 ? 1 : currAnimDenom;
        reportDenoms.push_back(currAnimDenom);
    }
    reportDenoms.push_back(totalAnimDenom);
}

void FarmRegBreakdown::grabDenom(string anim, float& denom) {
    vector<string> animKeys = animalMap.getKeys();

    if (anim == "Total") {
        denom = reportDenoms.at(reportDenoms.size() - 1);
        return;
    }
    for (int i = 0; i < animKeys.size(); ++i) {
        if (animKeys.at(i) == anim) {
            denom = reportDenoms.at(i);
            return;
        }
    }

    cout << "ERROR: No recollection of a total for the given animaltype." << endl;
    return;
}

void FarmRegBreakdown::formatData(float key, string row) {
    repData->add(key, row);
}

void FarmRegBreakdown::printReport() {
    ofstream outfile("Report1.txt", ios::out);
    if (!outfile) {
        cout << "Error:  could not open file" << endl;
        exit(1);
    }
    stringstream ss;
    ss << setw(50) << ' ' << "PERCENTAGE OF FARMS BY REGION IN 2016" << endl
       << setw(50) << ' ' << "-------------------------------------" << endl
       << endl
       << "            Horses/      Goats      Llamas/     Rabbits      Bison/       Elk/      Domestic      Wild-       Mink      Totals" << endl
       << "            Ponies                  Alpacas                  Buffalo      Wapiti    Deer          Boars"
       << endl
       << endl
       << *repData;

    outfile << ss.str();
    cout << endl
         << ss.str();
    cleanup();
}

void FarmRegBreakdown::cleanup() {
    repData->del();
    reportDenoms.clear();
}