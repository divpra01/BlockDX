/// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#ifndef PROPOSALVOTEDIALOG_H
#define PROPOSALVOTEDIALOG_H
#include <QDialog>
#include "proposalvotemodel.h"


namespace Ui {
    class ProposalVoteDialog;
} // namespace Ui


// Proposal Vote dialog
class ProposalVoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProposalVoteDialog(QWidget* parent, bool enableWallet);
    ~ProposalVoteDialog();
    void Init(void);


private slots:
    void on_btnProposalsRefresh_clicked();

    void on_btnVoteYesForAll_clicked();

    void on_btnVoteNoForAll_clicked();

    void on_btnVoteAbstainForAll_clicked();

    void on_propsView_clicked(const QModelIndex &index);

private:
    Ui::ProposalVoteDialog* ui;
    ProposalVoteModel *propsModel;
};


#endif // PROPOSALVOTEDIALOG_H
