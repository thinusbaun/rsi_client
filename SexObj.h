#ifndef SEXOBJ_H
#define SEXOBJ_H

#include <QString>

class SexObj {
 public:
  enum Sex { Male, Female };
  SexObj() = delete;

  static QString sexToPresentation(SexObj::Sex sez);
};

#endif  // SEXOBJ_H
