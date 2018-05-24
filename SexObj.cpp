#include "SexObj.h"
#include <assert.h>

QString SexObj::sexToPresentation(SexObj::Sex sex) {
  switch (sex) {
    case SexObj::Male:
      return "Male";
      break;
    case SexObj::Female:
      return "Female";
      break;
    default:
      assert(0 == "Invalid sex");
      break;
  }
}
