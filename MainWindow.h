#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "FilmasterClient.h"
#include "MovieListModel.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(FilmasterClient *client, QWidget *parent = 0);
  ~MainWindow();

 private slots:
  void movieSelected(const QModelIndex &index);

  void showAllReservationsDialog();

 private:
  Ui::MainWindow *ui;
  FilmasterClient *mClient;
  MovieListModel mMovieListModel;
};

#endif  // MAINWINDOW_H
