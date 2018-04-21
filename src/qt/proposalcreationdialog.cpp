#include "proposalcreationdialog.h"
#include "ui_proposalcreationdialog.h"


ProposalCreationDialog::ProposalCreationDialog(QWidget *parent, bool enableWallet) : QDialog(parent), ui(new Ui::ProposalCreationDialog)
{
    ui->setupUi(this);
}

ProposalCreationDialog::~ProposalCreationDialog()
{
    delete ui;
}
