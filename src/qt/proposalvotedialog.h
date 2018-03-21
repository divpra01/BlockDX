/********************************************************************************
** Form generated from reading UI file 'proposalvotedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

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

private:
    Ui::ProposalVoteDialog* ui;
};


#endif // PROPOSALVOTEDIALOG_H
