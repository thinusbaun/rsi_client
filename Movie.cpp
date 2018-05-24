#include "Movie.h"

Movie::Movie() {}

QString Movie::name() const { return mName; }

void Movie::setName(const QString &name) { mName = name; }

QString Movie::description() const { return mDescription; }

void Movie::setDescription(const QString &description) {
  mDescription = description;
}

QImage Movie::poster() const { return mPoster; }

void Movie::setPoster(const QImage &poster) { mPoster = poster; }

unsigned long Movie::directorId() const { return mDirectorId; }

void Movie::setDirectorId(unsigned long directorId) {
  mDirectorId = directorId;
}

QVector<unsigned long> Movie::actorIds() const { return mActorIds; }

void Movie::setActorIds(const QVector<unsigned long> &actorIds) {
  mActorIds = actorIds;
}
