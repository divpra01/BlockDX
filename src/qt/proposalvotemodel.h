// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PROPOSALVOTEMODEL_H
#define PROPOSALVOTEMODEL_H

#include <QAbstractTableModel>
#include <QtGui>

#include <iostream>
#include <sstream>


class ProposalVoteModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ProposalVoteModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

protected slots:
    void timerHit();

protected:
     std::vector<std::vector<float> > Columns;

public:
    QString propData[1000];
};

#endif // PROPOSALVOTEMODEL_H
