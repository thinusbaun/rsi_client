#ifndef RESERVATIONDIALOG_H
#define RESERVATIONDIALOG_H

#include <QAbstractButton>
#include <QDialog>
#include <QSet>
#include "FilmasterClient.h"

namespace Ui {
class ReservationDialog;
}

class ReservationDialog : public QDialog {
  Q_OBJECT

 public:
  explicit ReservationDialog(FilmasterClient* client, unsigned long screeningId,
                             QWidget* parent = 0);
  ~ReservationDialog();

 private slots:
  void applyReservationsToWidgets();
  void buttonToggled();

  void buttonBoxClicked(QAbstractButton* button);

  void downloadReservations();

 private:
  Ui::ReservationDialog* ui;
  FilmasterClient* mClient;
  unsigned long mScreeningId;
  QSet<QPair<int, int>> mAddedReservations;
  QSet<QPair<int, int>> mRemovedReservations;
};

#endif  // RESERVATIONDIALOG_H
