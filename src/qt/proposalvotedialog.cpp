// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "forms/ui_proposalvotedialog.h"
#include "proposalvotedialog.h"


ProposalVoteDialog::ProposalVoteDialog(QWidget* parent, bool enableWallet) : QDialog(parent),  ui(new Ui::ProposalVoteDialog)
{
    ui->setupUi(this);
}


ProposalVoteDialog::~ProposalVoteDialog()
{
    delete ui;
}
