#ifndef IDENTIFIEDOBJECT_H
#define IDENTIFIEDOBJECT_H

#include "GenericRegistry.h"

class IdentifiedObject {
 public:
  IdentifiedObject();
  void setId(unsigned long newId);
  unsigned long id() const;

 private:
  unsigned long mId;
};

// template GenericRegistry<IdentifiedObject>;
#endif  // IDENTIFIEDOBJECT_H
