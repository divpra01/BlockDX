// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "forms/ui_proposalvotedialog.h"
#include "proposalvotedialog.h"

#include "../rpcserver.h"
#include "proposalvotemodel.h"


ProposalVoteDialog::ProposalVoteDialog(QWidget* parent, bool enableWallet) : QDialog(parent),  ui(new Ui::ProposalVoteDialog)
{
    ui->setupUi(this);
    Init();
}


ProposalVoteDialog::~ProposalVoteDialog()
{
    delete ui;
}


void ProposalVoteDialog::Init(void)
{
    QString strPrint;
    //const json_spirit::Array params;
    json_spirit::Value proposals = mnbudget({"show"}, false);
    //json_spirit::Pair proposalsPairs = proposals.get_obj[0];

    ProposalVoteModel *propsModel = new ProposalVoteModel(0);

    // const Object& addr_array = value.get_obj();
    //vector<Value> proposalsJsonObj = value2.get_array();
    //vector<Value>::iterator it;
    //vector<proposals> final;
    QString name;
    int index = 0;
    auto jsonObject = proposals.get_obj();
    for (auto entry : jsonObject) {
        if (entry.name_ != "") { // && entry.value_.type() == json_spirit::Value_type::str_type) {
               name = QString::fromStdString(entry.name_); //entry.value_.get_str());
               propsModel->propData[index++] = name;
        }
    }

    // Format result reply
    if (proposals.type() == json_spirit::null_type)
        strPrint = "Null Object";
    else if (proposals.type() == json_spirit::str_type)
        strPrint = QString::fromStdString(proposals.get_str());
    else
        strPrint = name; //write_string(result, true);

    ui->propsView->setModel(propsModel);
    //propsModel->propData = strPrint; // QString::fromStdString(proposals.get_str());
    //propsModel->data(propsModel->index(0, 0));
    ui->propsView->show();
}

void ProposalVoteDialog::on_btnProposalsRefresh_clicked()
{
    Init();
}
