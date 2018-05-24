#include "ScreeningListModel.h"

ScreeningListModel::ScreeningListModel(FilmasterClient *client,
                                       unsigned long movieId, QObject *parent)
    : QAbstractTableModel(parent), mClient(client), mMovieId(movieId) {}

QVariant ScreeningListModel::headerData(int section,
                                        Qt::Orientation orientation,
                                        int role) const {
  if (orientation == Qt::Horizontal) {
    if (role == Qt::DisplayRole) {
      switch (section) {
        case 0:
          return "Dzień tygodnia";
          break;
        case 1:
          return "Data";
          break;
        case 2:
          return "Godzina";
          break;
        default:
          return QVariant();
      }
    }
  }
  return QVariant();
}

int ScreeningListModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return mClient->getScreeningsFor(mMovieId).size();
}

int ScreeningListModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return 4;
}

QVariant ScreeningListModel::data(const QModelIndex &index, int role) const {
  //  if (!index.isValid()) return QVariant();
  auto screenings = mClient->getScreeningsFor(mMovieId);
  if (role == Qt::UserRole + 1) {
    return QVariant::fromValue(screenings[index.row()]->id());
  }

  if (role == Qt::DisplayRole) {
    switch (index.column()) {
      case 0:
        return screenings[index.row()]->timeStamp().date().toString("dddd");
        break;
      case 1:
        return screenings[index.row()]->timeStamp().date().toString(
            "dd-MM-yyyy");
        break;
      case 2:
        return screenings[index.row()]->timeStamp().time().toString("hh:mm");
        break;
      case 3:
        return "Rezerwacja";
        break;
    }
  }

  // FIXME: Implement me!
  return QVariant();
}
