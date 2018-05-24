#include "AllReservationsDialog.h"
#include "AllReservationsModel.h"
#include "ui_AllReservationsDialog.h"

#include <QFileDialog>
#include <QTableView>

AllReservationsDialog::AllReservationsDialog(FilmasterClient *client,
                                             QWidget *parent)
    : QDialog(parent), ui(new Ui::AllReservationsDialog), mClient(client) {
  ui->setupUi(this);
  ui->tableView->setModel(new AllReservationsModel(client));
  connect(ui->tableView, &QTableView::doubleClicked, this,
          &AllReservationsDialog::cellDoubleClicked);
}

AllReservationsDialog::~AllReservationsDialog() { delete ui; }

void AllReservationsDialog::cellDoubleClicked(const QModelIndex &index) {
  if (index.column() == 4) {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"));
    if (!filePath.isEmpty()) {
      unsigned long reservationId =
          ui->tableView->model()->data(index, Qt::UserRole + 1).toULongLong();
      QByteArray data = mClient->getReservationTicket(reservationId);
      QFile file(filePath);
      file.open(QFile::WriteOnly);
      file.write(data);
      file.close();
    }
  }
}
