#include "Reservation.h"

Reservation::Reservation() {}

int Reservation::x() const { return mX; }

void Reservation::setX(int x) { mX = x; }

int Reservation::y() const { return mY; }

void Reservation::setY(int y) { mY = y; }

unsigned long Reservation::userId() const { return mUserId; }

void Reservation::setUserId(unsigned long userId) { mUserId = userId; }

unsigned long Reservation::screeningId() const { return mScreeningId; }

void Reservation::setScreeningId(unsigned long screeningId) {
  mScreeningId = screeningId;
}

QString Reservation::movieTitle() const { return mMovieTitle; }

void Reservation::setMovieTitle(const QString &movieTitle) {
  mMovieTitle = movieTitle;
}

QDateTime Reservation::screeningTimestamp() const {
  return mScreeningTimestamp;
}

void Reservation::setScreeningTimestamp(const QDateTime &screeningTimestamp) {
  mScreeningTimestamp = screeningTimestamp;
}

unsigned long Reservation::movieId() const { return mMovieId; }

void Reservation::setMovieId(unsigned long movieId) { mMovieId = movieId; }
