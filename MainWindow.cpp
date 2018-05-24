#include "MainWindow.h"
#include <QAction>
#include <QListView>
#include "AllReservationsDialog.h"
#include "MovieDetailsDialog.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(FilmasterClient* client, QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mClient(client),
      mMovieListModel(client) {
  ui->setupUi(this);
  ui->listView->setModel(&mMovieListModel);
  connect(ui->listView, &QListView::doubleClicked, this,
          &MainWindow::movieSelected);
  connect(ui->actionPoka_wszystkie, &QAction::triggered, this,
          &MainWindow::showAllReservationsDialog);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::movieSelected(const QModelIndex& index) {
  auto movieId = mMovieListModel.data(index, Qt::UserRole + 1).toULongLong();
  auto movie = mClient->getMovieWithId(movieId);
  auto dialog = new MovieDetailsDialog(mClient, movie, this);
  dialog->exec();
}

void MainWindow::showAllReservationsDialog() {
  auto dialog = new AllReservationsDialog(mClient, this);
  dialog->exec();
}
