#include "Record.h"

Record::Record(int y, string reg, string subreg, string a, int numF, int numA)
    : year(y), region(reg), subRegion(subreg), animalType(a), numFarms(numF), numAnimals(numA) {
}

Record::~Record() {
}

int Record::getYear() const { return year; }
string Record::getRegion() const { return region; }
string Record::getSubRegion() const { return subRegion; }
string Record::getAnimalType() const { return animalType; }
int Record::getNumFarms() const { return numFarms; }
int Record::getNumAnimals() const { return numAnimals; }

ostream& operator<<(ostream& output, Record& r) {
    output << r.year << " "
           << r.region << " "
           << r.subRegion << " "
           << r.animalType << " "
           << r.numFarms << " "
           << r.numAnimals << " ";

    return output;
}