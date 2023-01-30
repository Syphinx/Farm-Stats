#include "Control.h"

Control::Control() {
    FarmRegBreakdown *r1 = new FarmRegBreakdown();
    reports.push_back(r1);
    AnimalCanBreakdown *r2 = new AnimalCanBreakdown();
    reports.push_back(r2);
    HorsesPoniesSubreg2016 *r3 = new HorsesPoniesSubreg2016();
    reports.push_back(r3);
}

Control::~Control() {
    for (int i = 0; i < reports.size(); i++) {
        delete reports.at(i);
    }
}

void Control::launch() {
    int choice = 1;
    string userInput;
    string userInstruction = "Enter your selection: ";

    ReportGenerator::populateCollection();

    view.showMenu(choice);

    while (choice != 0) {
        reports.at(choice - 1)->compute();
        reports.at(choice - 1)->printReport();
        view.showMenu(choice);
    }

    ReportGenerator::cleanup();
}