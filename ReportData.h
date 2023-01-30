#include "CompareBehaviour.h"
#include "defs.h"

/*
    Class       : ReportData
    Description : This template class is responsible for containing the results for one report
                  organized as an ordered collection of keys and formatted strings.
*/
template <class T>
class ReportData {
    /*
        Function: operator<<
        Purpose : This is an overloaded stream insertion operator, 
                  which prints out to the output stream all the rows of the report.
    */
    template <class V>
    friend ostream& operator<<(ostream&, ReportData<V>&);

   public:
    ReportData(CompareBehaviour<T>*);
    ~ReportData();
    void add(T, string);
    void del();

   private:
    /*
        Class       : ReportRow
        Description : This class is responsible for holding one row of a whole report       
    */
    template <class G>
    class ReportRow {
       public:
        ReportRow(G k, string str) : rowKey(k), rowStr(str){};
        G rowKey;
        string rowStr;
    };
    vector<ReportRow<T>> rows;
    CompareBehaviour<T>* compareObj;
};

template <class T>
ReportData<T>::ReportData(CompareBehaviour<T>* cmp)
    : compareObj(cmp) {
}
template <class T>
ReportData<T>::~ReportData() {
    delete compareObj;
}

template <class T>
void ReportData<T>::add(T key, string row) {
    typename vector<ReportRow<T>>::iterator itr;
    ReportRow<T> newR(key, row);
    for (itr = rows.begin(); itr != rows.end(); ++itr) {
        if (compareObj->compare(key, (*itr).rowKey)) {
            rows.insert(itr, newR);
            return;
        }
    }
    rows.insert(itr, newR);
    return;
}

template <class T>
void ReportData<T>::del() {
    rows.clear();
}

template <class V>
ostream& operator<<(ostream& output, ReportData<V>& data) {
    for (int i = 0; i < data.rows.size(); i++) {
        output << data.rows.at(i).rowStr;
    }
    return output;
}