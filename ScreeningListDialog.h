#ifndef SCREENINGLISTDIALOG_H
#define SCREENINGLISTDIALOG_H

#include "FilmasterClient.h"

#include <QDialog>

namespace Ui {
class ScreeningListDialog;
}

class ScreeningListDialog : public QDialog {
  Q_OBJECT

 public:
  explicit ScreeningListDialog(FilmasterClient* client, unsigned long movieId,
                               QWidget* parent = 0);
  ~ScreeningListDialog();

 private slots:
  void cellDoubleClicked(const QModelIndex& index);

 private:
  Ui::ScreeningListDialog* ui;
  FilmasterClient* mClient;
  unsigned long mMovieId;
};

#endif  // SCREENINGLISTDIALOG_H
