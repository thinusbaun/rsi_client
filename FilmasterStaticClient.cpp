#include "FilmasterStaticClient.h"

#include <QDateTime>
#include <QString>

FilmasterStaticClient::FilmasterStaticClient() {
  unsigned long directorId = 0;
  {
    auto director = new Director();
    director->setId(++directorId);
    director->setName("Roman Polański");
    mDirectorsReg.insert(director);
  }
  {
    auto director = new Director();
    director->setId(++directorId);
    director->setName("Dżej Dżej Abrams");
    mDirectorsReg.insert(director);
  }
  unsigned long actorId = 0;
  {
    auto actor = new Actor();
    actor->setId(++actorId);
    actor->setName("Małgorzata Kożuchowska");
    actor->setSex(SexObj::Female);
    mActorsReg.insert(actor);
  }
  {
    auto actor = new Actor();
    actor->setId(++actorId);
    actor->setName("Dżony Depp");
    actor->setSex(SexObj::Male);
    mActorsReg.insert(actor);
  }
  {
    auto actor = new Actor();
    actor->setId(++actorId);
    actor->setName("Michael Cera");
    actor->setSex(SexObj::Male);
    mActorsReg.insert(actor);
  }
  unsigned long movieId = 0;
  {
    auto movie = new Movie();
    movie->setId(++movieId);
    movie->setName("Grejowie kontratakują");
    movie->setDirectorId(2);
    movie->setActorIds(QVector<unsigned long>() << 1 << 2 << 3);
    movie->setPoster(QImage(":/test/poster.jpg"));
    movie->setDescription(
        "The passive nature of models provides new challenges for programmers. "
        "Inconsistencies in the model can cause the application to crash. "
        "Since the model is hit by numerous calls from the view, it is hard to "
        "find out which call has crashed the application and which operation "
        "has introduced the problem."
        "Qt Labs provides software called ModelTest, which checks models while "
        "your programming is running. Every time the model is changed, "
        "ModelTest scans the model and reports errors with an assert. This is "
        "especially important for tree models, since their hierarchical nature "
        "leaves many possibilities for subtle inconsistencies."
        "Unlike view classes, ModelTest uses out of range indexes to test the "
        "model. This means your application may crash with ModelTest even if "
        "it runs perfectly without it. So you also need to handle all of the "
        "indexes that are out of range when using ModelTest.");

    mMoviesReg.insert(movie);
  }
}

unsigned long FilmasterStaticClient::getCurrentUserId() { return -1; }

Movie *FilmasterStaticClient::getMovieWithId(unsigned long id) {
  return mMoviesReg.get(id);
}

QVector<Movie *> FilmasterStaticClient::getAllMovies() {
  QVector<Movie *> result;
  for (const auto &item : mMoviesReg.getAll()) {
    result.push_back(item);
  }
  return result;
}

Actor *FilmasterStaticClient::getActorWithId(unsigned long id) {
  return mActorsReg.get(id);
}

QVector<Actor *> FilmasterStaticClient::getAllActors() {
  QVector<Actor *> result;
  for (const auto &item : mActorsReg.getAll()) {
    result.push_back(item);
  }
  return result;
}

Director *FilmasterStaticClient::getDirectorWithId(unsigned long id) {
  return mDirectorsReg.get(id);
}

QVector<Director *> FilmasterStaticClient::getAllDirectors() {
  QVector<Director *> result;
  for (const auto &item : mDirectorsReg.getAll()) {
    result.push_back(item);
  }
  return result;
}

QVector<Screening *> FilmasterStaticClient::getScreeningsFor(
    unsigned long movieId) {
  QVector<Screening *> result;
  for (int i = 1; i < 10; i++) {
    auto screening = new Screening();
    screening->setId(i);
    screening->setTimeStamp(
        QDateTime(QDate::currentDate().addDays(i)).addSecs(i * 60 * 60));
    screening->setMovieId(movieId);
    result.push_back(screening);
  }
  return result;
}

QVector<Reservation *> FilmasterStaticClient::getReservationsFor(
    unsigned long screeningId) {
  QVector<Reservation *> result;
  for (int x = 0; x < 20; x += 2) {
    for (int y = 0; y < 20; y += 2) {
      auto reservation = new Reservation();
      reservation->setId(x * 20 + y);
      reservation->setX(x);
      reservation->setY(y);
      reservation->setUserId(y <= 10 ? -1 : 2);
      reservation->setScreeningId(screeningId);
      result.push_back(reservation);
    }
  }
  return result;
}

void FilmasterStaticClient::addReservations(
    unsigned long screeningId, const QSet<QPair<int, int> > &reservations) {
  Q_UNUSED(screeningId);
  Q_UNUSED(reservations);
}

void FilmasterStaticClient::removeReservations(
    unsigned long screeningId, const QSet<QPair<int, int> > &reservations) {
  Q_UNUSED(screeningId);
  Q_UNUSED(reservations);
}

QByteArray FilmasterStaticClient::getReservationTickets(
    unsigned long screeningId) {
  return QByteArray("Tickets for: ")
      .append(QString::number(screeningId).toLocal8Bit());
}

QVector<Reservation *> FilmasterStaticClient::getAllReservations() {
  QVector<Reservation *> result;
  for (const auto &movie : getAllMovies()) {
    for (const auto &screening : getScreeningsFor(movie->id())) {
      for (const auto &reservation : getReservationsFor(screening->id())) {
        if (reservation->userId() == getCurrentUserId()) {
          reservation->setMovieTitle(movie->name());
          reservation->setMovieId(movie->id());
          reservation->setScreeningId(screening->id());
          reservation->setScreeningTimestamp(screening->timeStamp());
          result.push_back(reservation);
        }
      }
    }
  }
  return result;
}

QByteArray FilmasterStaticClient::getReservationTicket(
    unsigned long reservationId) {
  return QByteArray("This is ticket for reservation id: ")
      .append(QString::number(reservationId).toLocal8Bit());
}
