#ifndef ALLRESERVATIONSMODEL_H
#define ALLRESERVATIONSMODEL_H

#include "FilmasterClient.h"

#include <QAbstractTableModel>

class AllReservationsModel : public QAbstractTableModel {
  Q_OBJECT

 public:
  explicit AllReservationsModel(FilmasterClient *client,
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
};

#endif  // ALLRESERVATIONSMODEL_H
