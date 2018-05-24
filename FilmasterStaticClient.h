#ifndef FILMASTERSTATICCLIENT_H
#define FILMASTERSTATICCLIENT_H

#include "FilmasterClient.h"

class FilmasterStaticClient : public FilmasterClient {
 public:
  FilmasterStaticClient();

  unsigned long getCurrentUserId() override;
  Movie* getMovieWithId(unsigned long id) override;
  QVector<Movie*> getAllMovies() override;
  Actor* getActorWithId(unsigned long id) override;
  QVector<Actor*> getAllActors() override;
  Director* getDirectorWithId(unsigned long id) override;
  QVector<Director*> getAllDirectors() override;

  QVector<Screening*> getScreeningsFor(unsigned long movieId) override;
  QVector<Reservation*> getReservationsFor(unsigned long screeningId) override;
  void addReservations(unsigned long screeningId,
                       const QSet<QPair<int, int>>& reservations) override;
  void removeReservations(unsigned long screeningId,
                          const QSet<QPair<int, int>>& reservations) override;
  QByteArray getReservationTickets(unsigned long screeningId) override;
  QVector<Reservation*> getAllReservations() override;
  QByteArray getReservationTicket(unsigned long reservationId) override;

 private:
  GenericRegistry<Actor> mActorsReg;
  GenericRegistry<Director> mDirectorsReg;
  GenericRegistry<Movie> mMoviesReg;
};

#endif  // FILMASTERSTATICCLIENT_H
