#ifndef MOVIELISTMODEL_H
#define MOVIELISTMODEL_H

#include "FilmasterClient.h"

#include <QAbstractListModel>

class MovieListModel : public QAbstractListModel {
 public:
  MovieListModel(FilmasterClient *client);
  ~MovieListModel();

  //  virtual QModelIndex index(int row, int column,
  //                            const QModelIndex &parent = QModelIndex())
  //                            const;
  //  virtual QModelIndex parent(const QModelIndex &child) const;

  //      virtual QModelIndex
  //      sibling(int row, int column, const QModelIndex &idx) const;
  virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
  virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
  //  virtual bool hasChildren(const QModelIndex &parent = QModelIndex()) const;

  virtual QVariant data(const QModelIndex &index,
                        int role = Qt::DisplayRole) const;

 private:
  FilmasterClient *mClient;
};

#endif  // MOVIELISTMODEL_H
