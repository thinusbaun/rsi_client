#include "IdentifiedObject.h"

IdentifiedObject::IdentifiedObject() {}

void IdentifiedObject::setId(unsigned long newId) { mId = newId; }

unsigned long IdentifiedObject::id() const { return mId; }
