#ifndef ALLRESERVATIONSDIALOG_H
#define ALLRESERVATIONSDIALOG_H

#include "FilmasterClient.h"

#include <QDialog>

namespace Ui {
class AllReservationsDialog;
}

class AllReservationsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit AllReservationsDialog(FilmasterClient* client, QWidget* parent = 0);
  ~AllReservationsDialog();

 private slots:
  void cellDoubleClicked(const QModelIndex& index);

 private:
  Ui::AllReservationsDialog* ui;
  FilmasterClient* mClient;
};

#endif  // ALLRESERVATIONSDIALOG_H
