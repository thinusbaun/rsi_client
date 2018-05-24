#include "AllReservationsModel.h"

AllReservationsModel::AllReservationsModel(FilmasterClient *client,
                                           QObject *parent)
    : QAbstractTableModel(parent), mClient(client) {}

QVariant AllReservationsModel::headerData(int section,
                                          Qt::Orientation orientation,
                                          int role) const {
  if (orientation == Qt::Horizontal) {
    if (role == Qt::DisplayRole) {
      switch (section) {
        case 0:
          return "Data i godzina";
          break;
        case 1:
          return "Tytuł filmu";
          break;
        case 2:
          return "Miejsce";
          break;
        default:
          return QVariant();
      }
    }
  }
  return QVariant();
}

int AllReservationsModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return mClient->getAllReservations().size();
}

int AllReservationsModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent);
  return 5;
}

QVariant AllReservationsModel::data(const QModelIndex &index, int role) const {
  auto reservations = mClient->getAllReservations();
  if (role == Qt::UserRole + 1) {
    return QVariant::fromValue(reservations[index.row()]->id());
  }

  if (role == Qt::DisplayRole) {
    switch (index.column()) {
      case 0:
        return reservations[index.row()]->screeningTimestamp().toString();
        break;
      case 1:
        return reservations[index.row()]->movieTitle();
        break;
      case 2:
        return QString("%1, %2")
            .arg(reservations[index.row()]->x())
            .arg(reservations[index.row()]->y());
        break;
      case 3:
        return "Anuluj";
        break;
      case 4:
        return "Pobierz bilet";
        break;
    }
  }
  return QVariant();
}
