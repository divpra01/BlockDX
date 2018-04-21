#ifndef PROPOSALCREATIONDIALOG_H
#define PROPOSALCREATIONDIALOG_H

#include <QDialog>

namespace Ui {
class ProposalCreationDialog;
}

class ProposalCreationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProposalCreationDialog(QWidget *parent = 0, bool enableWallet = false);
    ~ProposalCreationDialog();

private:
    Ui::ProposalCreationDialog *ui;
};

#endif // PROPOSALCREATIONDIALOG_H
