#ifndef SCREENING_H
#define SCREENING_H

#include "IdentifiedObject.h"

#include <QDateTime>

class Screening : public IdentifiedObject {
 public:
  Screening();

  QDateTime timeStamp() const;
  void setTimeStamp(const QDateTime &timeStamp);

  unsigned long movieId() const;
  void setMovieId(unsigned long movieId);

 private:
  QDateTime mTimeStamp;
  unsigned long mMovieId;
};

#endif  // SCREENING_H
