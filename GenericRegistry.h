#ifndef GENERICREGISTRY_H
#define GENERICREGISTRY_H
#include <assert.h>
#include <QMap>
template <class T>
class GenericRegistry {
 public:
  GenericRegistry();
  ~GenericRegistry();
  void clear();
  void insert(T* object);

  T* get(unsigned long id) const;
  QMap<unsigned long, T*> getAll() const;

 private:
  QMap<unsigned long, T*> mObjects;
};

template <class T>
GenericRegistry<T>::GenericRegistry() {}

template <class T>
GenericRegistry<T>::~GenericRegistry() {
  clear();
}
template <class T>
void GenericRegistry<T>::clear() {
  //  QDeleteAll(mObjects);
  mObjects.clear();
}

template <class T>
void GenericRegistry<T>::insert(T* object) {
  assert(!mObjects.contains(object->id()));
  mObjects[object->id()] = object;
}

template <class T>
T* GenericRegistry<T>::get(unsigned long id) const {
  if (mObjects.contains(id)) {
    return mObjects[id];
  } else {
    return nullptr;
  }
}

template <class T>
QMap<unsigned long, T*> GenericRegistry<T>::getAll() const {
  return mObjects;
}

#endif  // GENERICREGISTRY_H
