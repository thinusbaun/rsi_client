#ifndef ACTOR_H
#define ACTOR_H
//#include <QString>
#include <qt/QtCore/qstring.h>
#include "GenericRegistry.h"
#include "IdentifiedObject.h"
#include "SexObj.h"
class Actor : public IdentifiedObject {
 public:
  Actor();

  QString name() const;
  void setName(const QString &name);

  SexObj::Sex sex() const;
  void setSex(const SexObj::Sex &sex);

 private:
  QString mName;
  SexObj::Sex mSex;
};

template class GenericRegistry<Actor>;
#endif  // ACTOR_H
