#ifndef FILMASTERCLIENT_H
#define FILMASTERCLIENT_H

#include <QObject>
#include <QVector>
#include "Actor.h"
#include "Director.h"
#include "Movie.h"
#include "Reservation.h"
#include "Screening.h"

class FilmasterClient {
 public:
  FilmasterClient();
  virtual ~FilmasterClient();

  virtual unsigned long getCurrentUserId() = 0;
  virtual Movie* getMovieWithId(unsigned long id) = 0;
  virtual QVector<Movie*> getAllMovies() = 0;
  virtual Actor* getActorWithId(unsigned long id) = 0;
  virtual QVector<Actor*> getAllActors() = 0;
  virtual Director* getDirectorWithId(unsigned long id) = 0;
  virtual QVector<Director*> getAllDirectors() = 0;

  virtual QVector<Screening*> getScreeningsFor(unsigned long movieId) = 0;
  virtual QVector<Reservation*> getReservationsFor(
      unsigned long screeningId) = 0;

  virtual void addReservations(unsigned long screeningId,
                               const QSet<QPair<int, int>>& reservations) = 0;
  virtual void removeReservations(
      unsigned long screeningId, const QSet<QPair<int, int>>& reservations) = 0;
  virtual QByteArray getReservationTickets(unsigned long screeningId) = 0;
  virtual QVector<Reservation*> getAllReservations() = 0;
  virtual QByteArray getReservationTicket(unsigned long reservationId) = 0;
};

#endif  // FILMASTERCLIENT_H
