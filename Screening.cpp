#include "Screening.h"

Screening::Screening() {}

QDateTime Screening::timeStamp() const { return mTimeStamp; }

void Screening::setTimeStamp(const QDateTime &timeStamp) {
  mTimeStamp = timeStamp;
}

unsigned long Screening::movieId() const
{
    return mMovieId;
}

void Screening::setMovieId(unsigned long movieId)
{
    mMovieId = movieId;
}
