#ifndef MOVIEDETAILSDIALOG_H
#define MOVIEDETAILSDIALOG_H

#include <QDialog>
#include "FilmasterClient.h"
#include "Movie.h"

namespace Ui {
class MovieDetailsDialog;
}

class MovieDetailsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit MovieDetailsDialog(FilmasterClient* client, Movie* movie,
                              QWidget* parent = 0);
  ~MovieDetailsDialog();

 private slots:
  void openScreeningsDialog();

 private:
  Ui::MovieDetailsDialog* ui;
  Movie* mMovie;
  FilmasterClient* mClient;
};

#endif  // MOVIEDETAILSDIALOG_H
