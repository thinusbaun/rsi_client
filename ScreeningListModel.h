#ifndef SCREENINGLISTMODEL_H
#define SCREENINGLISTMODEL_H

#include <QAbstractTableModel>
#include "FilmasterClient.h"
class ScreeningListModel : public QAbstractTableModel {
  Q_OBJECT

 public:
  explicit ScreeningListModel(FilmasterClient *client, unsigned long movieId,
                              QObject *parent = nullptr);

  // Header:
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const override;

  // Basic functionality:
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;

  QVariant data(const QModelIndex &index,
                int role = Qt::DisplayRole) const override;

 private:
  FilmasterClient *mClient;
  unsigned long mMovieId;
};

#endif  // SCREENINGLISTMODEL_H
