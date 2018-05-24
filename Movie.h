#ifndef MOVIE_H
#define MOVIE_H
#include <QImage>
#include <QString>
#include <QVector>

#include "GenericRegistry.h"
#include "IdentifiedObject.h"
class Movie : public IdentifiedObject {
 public:
  Movie();

  QString name() const;
  void setName(const QString &name);

  QString description() const;
  void setDescription(const QString &description);

  QImage poster() const;
  void setPoster(const QImage &poster);

  unsigned long directorId() const;
  void setDirectorId(unsigned long directorId);

  QVector<unsigned long> actorIds() const;
  void setActorIds(const QVector<unsigned long> &actorIds);

 private:
  QString mName;
  QString mDescription;
  QImage mPoster;
  unsigned long mDirectorId;
  QVector<unsigned long> mActorIds;
};

template class GenericRegistry<Movie>;
#endif  // MOVIE_H
