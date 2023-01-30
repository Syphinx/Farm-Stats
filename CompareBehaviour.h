#ifndef COMPAREBEHAVIOUR_H
#define COMPAREBEHAVIOUR_H

/*
    Class       : CompareBehaviour
    Description : This abstract template class serves as a base class for an inheritance hierarchy of comparison behaviour class templates.
*/
template <class T>
class CompareBehaviour {
   public:
    virtual bool compare(T, T) const = 0;
};

template <class T>
class AscBehaviour : public CompareBehaviour<T> {
   public:
    virtual bool compare(T, T) const;
};

template <class T>
class DescBehaviour : public CompareBehaviour<T> {
   public:
    virtual bool compare(T, T) const;
};

template <class T>
bool AscBehaviour<T>::compare(T ob1, T ob2) const {
    return ob1 < ob2;
};

template <class T>
bool DescBehaviour<T>::compare(T ob1, T ob2) const {
    return ob1 > ob2;
};

#endif