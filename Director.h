#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QString>
#include "GenericRegistry.h"
#include "IdentifiedObject.h"
#include "SexObj.h"

class Director : public IdentifiedObject {
 public:
  Director();

  QString name() const;
  void setName(const QString &name);

  SexObj::Sex sex() const;
  void setSex(const SexObj::Sex &sex);

 private:
  QString mName;
  SexObj::Sex mSex;
};

template class GenericRegistry<Director>;
#endif  // DIRECTOR_H
