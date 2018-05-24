#include "MovieDetailsDialog.h"
#include <QPushButton>
#include "ScreeningListDialog.h"
#include "ui_MovieDetailsDialog.h"
MovieDetailsDialog::MovieDetailsDialog(FilmasterClient* client, Movie* movie,
                                       QWidget* parent)
    : QDialog(parent),
      ui(new Ui::MovieDetailsDialog),
      mMovie(movie),
      mClient(client) {
  ui->setupUi(this);
  ui->titleLabel->setText(movie->name());
  ui->descriptionLabel->setText(movie->description());
  ui->posterLabel->setPixmap(QPixmap::fromImage(movie->poster()));
  auto director = client->getDirectorWithId(movie->directorId());
  ui->directorLabel->setText(director->name());

  QStringList actors;
  for (const auto& actorId : movie->actorIds()) {
    actors << client->getActorWithId(actorId)->name();
  }
  ui->actorsListWidget->addItems(actors);
  connect(ui->screeningButton, &QPushButton::clicked, this,
          &MovieDetailsDialog::openScreeningsDialog);
}

MovieDetailsDialog::~MovieDetailsDialog() { delete ui; }

void MovieDetailsDialog::openScreeningsDialog() {
  auto dialog = new ScreeningListDialog(mClient, mMovie->id(), this);
  dialog->exec();
}
