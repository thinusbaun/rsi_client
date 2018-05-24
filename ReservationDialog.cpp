#include "ReservationDialog.h"
#include "ui_ReservationDialog.h"

#include <QDialogButtonBox>
#include <QFileDialog>
#include <QPushButton>
#include <QTimer>

ReservationDialog::ReservationDialog(FilmasterClient *client,
                                     unsigned long screeningId, QWidget *parent)
    : QDialog(parent),
      ui(new Ui::ReservationDialog),
      mClient(client),
      mScreeningId(screeningId) {
  ui->setupUi(this);
  connect(ui->buttonBox, &QDialogButtonBox::clicked, this,
          &ReservationDialog::buttonBoxClicked);
  connect(ui->downloadDocumentButton, &QPushButton::clicked, this,
          &ReservationDialog::downloadReservations);
  for (int x = 0; x < 20; x++) {
    for (int y = 0; y < 20; y++) {
      auto button = new QPushButton();
      button->setText("");
      button->setFixedSize(22, 22);
      button->setToolTip(QString("(%1, %2)").arg(x).arg(y));
      button->setStyleSheet(
          "QPushButton{border: 1px solid black}\n"
          "QPushButton:unchecked{background: white}\n"
          "QPushButton:checked{background: green}\n"
          "QPushButton:disabled{background: grey}");
      button->setCheckable(true);
      connect(button, &QPushButton::clicked, this,
              &ReservationDialog::buttonToggled);
      ui->grid->addWidget(button, x, y);
    }
  }
  QTimer::singleShot(0, this, SLOT(applyReservationsToWidgets()));
}

ReservationDialog::~ReservationDialog() { delete ui; }

void ReservationDialog::applyReservationsToWidgets() {
  auto reservations = mClient->getReservationsFor(mScreeningId);
  auto currentUserId = mClient->getCurrentUserId();

  for (int x = 0; x < 20; x++) {
    for (int y = 0; y < 20; y++) {
      QPushButton *button =
          qobject_cast<QPushButton *>(ui->grid->itemAtPosition(x, y)->widget());
      auto reservation = std::find_if(
          reservations.begin(), reservations.end(),
          [&](auto res) { return res->x() == x && res->y() == y; });
      if (reservation == reservations.end()) {
        button->setChecked(false);
        button->setDisabled(false);
      } else {
        if ((*reservation)->userId() == currentUserId) {
          button->setChecked(true);
          button->setDisabled(false);
        } else {
          button->setChecked(false);
          button->setDisabled(true);
        }
      }
    }
  }
}

void ReservationDialog::buttonToggled() {
  QPushButton *button = qobject_cast<QPushButton *>(sender());
  auto index = ui->grid->indexOf(button);
  int x = index / 20;
  int y = index % 20;
  if (button->isChecked()) {
    mAddedReservations.insert(qMakePair(x, y));
    mRemovedReservations.remove(qMakePair(x, y));
  } else {
    mRemovedReservations.insert(qMakePair(x, y));
    mAddedReservations.remove(qMakePair(x, y));
  }
}

void ReservationDialog::buttonBoxClicked(QAbstractButton *button) {
  if (ui->buttonBox->button(QDialogButtonBox::SaveAll) == button) {
    mClient->addReservations(mScreeningId, mAddedReservations);
    mClient->removeReservations(mScreeningId, mRemovedReservations);
  }
}

void ReservationDialog::downloadReservations() {
  QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"));
  if (!filePath.isEmpty()) {
    QByteArray data = mClient->getReservationTickets(mScreeningId);
    QFile file(filePath);
    file.open(QFile::WriteOnly);
    file.write(data);
    file.close();
  }
}
