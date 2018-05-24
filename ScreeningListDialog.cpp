#include "ScreeningListDialog.h"
#include "ReservationDialog.h"
#include "ScreeningListModel.h"
#include "ui_ScreeningListDialog.h"

ScreeningListDialog::ScreeningListDialog(FilmasterClient* client,
                                         unsigned long movieId, QWidget* parent)
    : QDialog(parent),
      ui(new Ui::ScreeningListDialog),
      mClient(client),
      mMovieId(movieId) {
  ui->setupUi(this);
  ui->tableView->setModel(new ScreeningListModel(client, movieId, this));
  connect(ui->tableView, &QTableView::doubleClicked, this,
          &ScreeningListDialog::cellDoubleClicked);
}

ScreeningListDialog::~ScreeningListDialog() { delete ui; }

void ScreeningListDialog::cellDoubleClicked(const QModelIndex& index) {
  if (index.column() == 3) {
    auto screeningId =
        ui->tableView->model()->data(index, Qt::UserRole + 1).toULongLong();
    auto dialog = new ReservationDialog(mClient, screeningId, this);
    dialog->exec();
  }
}
