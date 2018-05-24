#ifndef RESERVATION_H
#define RESERVATION_H

#include "IdentifiedObject.h"

#include <QDateTime>

class Reservation : public IdentifiedObject {
 public:
  Reservation();

  int x() const;
  void setX(int x);

  int y() const;
  void setY(int y);

  unsigned long userId() const;
  void setUserId(unsigned long userId);

  unsigned long screeningId() const;
  void setScreeningId(unsigned long screeningId);

  QString movieTitle() const;
  void setMovieTitle(const QString &movieTitle);

  QDateTime screeningTimestamp() const;
  void setScreeningTimestamp(const QDateTime &screeningTimestamp);

  unsigned long movieId() const;
  void setMovieId(unsigned long movieId);

 private:
  int mX;
  int mY;
  unsigned long mScreeningId;
  unsigned long mMovieId;
  unsigned long mUserId;
  QString mMovieTitle;
  QDateTime mScreeningTimestamp;
};

#endif  // RESERVATION_H
