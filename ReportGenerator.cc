#include "ReportGenerator.h"

vector<Record*> ReportGenerator::recordCollection;
Map<string> ReportGenerator::regionMap;
Map<string> ReportGenerator::animalMap;
Map<int> ReportGenerator::yearMap;

ReportGenerator::~ReportGenerator() {
}

void ReportGenerator::populateCollection() {
    int y, numF, numA;
    string reg, subreg, a;

    ifstream farmData("farms.dat", ios::in);
    if (!farmData) {
        cout << "Error: could not open file" << endl;
        exit(1);
    }

    while (farmData >> y >> reg >> subreg >> a >> numF >> numA) {
        Record* newRecord = new Record(y, reg, subreg, a, numF, numA);

        yearMap.add(newRecord->getYear(), newRecord);
        regionMap.add(newRecord->getRegion(), newRecord);
        animalMap.add(newRecord->getAnimalType(), newRecord);

        recordCollection.push_back(newRecord);
    }
}

void ReportGenerator::cleanup() {
    for (int i = 0; i < recordCollection.size(); ++i) {
        delete recordCollection.at(i);
    }
}