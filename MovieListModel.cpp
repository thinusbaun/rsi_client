#include "MovieListModel.h"

MovieListModel::MovieListModel(FilmasterClient* client) : mClient(client) {}

MovieListModel::~MovieListModel() {}

int MovieListModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return mClient->getAllMovies().count();
}

int MovieListModel::columnCount(const QModelIndex& parent) const {
  Q_UNUSED(parent);
  return 1;
}

QVariant MovieListModel::data(const QModelIndex& index, int role) const {
  Q_UNUSED(index);
  Q_UNUSED(role);
  auto movies = mClient->getAllMovies();
  if (role == Qt::DisplayRole) {
    return movies[index.row()]->name();
  } else if (role == Qt::UserRole + 1) {
    return QVariant::fromValue(movies[index.row()]->id());
  }
  return QVariant();
}
