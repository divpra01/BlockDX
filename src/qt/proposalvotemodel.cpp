// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "proposalvotemodel.h"


ProposalVoteModel::ProposalVoteModel(QObject *parent):QAbstractTableModel(parent)
{
    std::vector<float> column1;
      column1.push_back(10);
      column1.push_back(20);
      column1.push_back(30);
      column1.push_back(40);

      Columns.push_back(column1);

      std::vector<float> column2;
      column2.push_back(50);
      column2.push_back(60);
      column2.push_back(70);
      column2.push_back(80);

      Columns.push_back(column2);

      //QString propData[] = new QString[1000];

      //QTimer *timer = new QTimer(this);
      //timer->setInterval(1000);
      //connect(timer, SIGNAL(timeout()) , this, SLOT(timerHit()));
      //timer->start();
}


//ProposalVoteModel::~ProposalVoteModel()
//{
//}


void ProposalVoteModel::timerHit()
{
    //we identify the top left cell
    QModelIndex topLeft = createIndex(0,0);
    //emit a signal to make the view reread identified data
    emit dataChanged(topLeft, topLeft);
}


int ProposalVoteModel::rowCount(const QModelIndex & /*parent*/) const
{
   return 48;
}


int ProposalVoteModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 4;
}


QVariant ProposalVoteModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole)
    {
        //return QString("Row%1, Column%2")
        //            .arg(index.row() + 1)
        //            .arg(index.column() +1);

        if (col == 0)
        {
            return propData[row];
        //    return QTime::currentTime().toString();
        }
    }
    return QVariant();
}


QVariant ProposalVoteModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        std::stringstream ss;
        if (orientation == Qt::Horizontal)
        {
        switch (section)
        {
            case 0:
                ss << "Name";
                return QString(ss.str().c_str());
            case 1:
                return QString("Title");
            case 2:
                return QString("Owner");
            case 3:
                return QString("Details");
        }

      }
    else if(orientation == Qt::Vertical)
      {
      ss << "V_" << section;
      return QString(ss.str().c_str());
      }

    }

  return QVariant::Invalid;
}
