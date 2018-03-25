/// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#ifndef PROPOSALVOTEDIALOG_H
#define PROPOSALVOTEDIALOG_H
#include <QDialog>


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

private:
    Ui::ProposalVoteDialog* ui;
};


#endif // PROPOSALVOTEDIALOG_H
