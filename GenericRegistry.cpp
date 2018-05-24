#include "GenericRegistry.h"

template <class T>
GenericRegistry<T>::GenericRegistry() {}

template <class T>
void GenericRegistry<T>::clear() {
  QDeleteAll(mObjects);
  mObjects.clear();
}

template <class T>
void GenericRegistry<T>::insert(T* object) {
  assert(!mObjects.contains(object->getId()));
  mObjects[object->getId()] = object;
}

template <class T>
T* GenericRegistry<T>::get(unsigned long id) {
  if (mObjects.contains(id)) {
    return mObjects[id];
  } else {
    return nullptr;
  }
}
