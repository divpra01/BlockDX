// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "forms/ui_proposalvotedialog.h"
#include "proposalvotedialog.h"

#include "../rpcserver.h"
#include "proposalvotemodel.h"
//#include "stdlib.h"

using namespace json_spirit;
using namespace std;


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

    propsModel = new ProposalVoteModel(0);

    // const Object& addr_array = value.get_obj();
    //vector<Value> proposalsJsonObj = value2.get_array();
    //vector<Value>::iterator it;
    //vector<proposals> final;
    //QString name;
    int index = 0;
    //Object::size_type i=0;
    //const Pair& rowPair = proposals.get_obj()[0];
    Object jsonObject = proposals.get_obj(); //rowPair.value_.get_obj();
    //const Array& addr_array = proposals.get_array();
    //auto jsonEntry = jsonObject.at(i);
    //json_spirit::Value jsonValue = jsonArray.at(i);
    //Object jsonEntry = jsonValue.get_obj();
    const QString name;
    const QString value;
    //vector<Value>::iterator &it;

    //for(it = jsonObject.begin(); it!=jsonObject.end(); it++) {
        //auto valObj = it.;
        for (auto entry : jsonObject) {
        //for( unsigned int i = 0; i < addr_array.size(); ++i ) {
            //Object obj = addr_array[i].get_obj();
            //for( Object::size_type i = 0; i != jsonObject.size(); ++i ) {
                    //const Pair& pair = jsonObject[i];

                    const string& namestr = entry.name_;
                    Object proposal = entry.value_.get_obj();

         //Object row = entry.find(entry.name_)->second.get_obj();
        //Pair entryPair = entry;
        for (const Pair& propEntry : proposal) {
        //for (Object::size_type i=0; i != jsonObject.size(); ++i) {

            //const Pair& pair = jsonObject[i];
            //name = QString::fromStdString(pair.name_);
            //value = QString::fromStdString(pair.value_);

        //if (entry.name_ != "") { // && entry.value_.type() == json_spirit::Value_type::str_type) {
            //propsModel->propsData[index].name = name;

            //pair = jsonObject[++i];
            //name = QString::fromStdString(pair.name_);
            //propsModel->propsData[index].URL = name; //QString::fromStdString(entry.url_);
            //json_spirit::Object& objError;
            //name = QString::fromStdString(namestr);
            //name = find_value(jsonObject.find(, "name").get_str();
            //QString::fromStdString(find_value(entry.value_.get_obj(), "name").get_str());

            if (propEntry.name_ == "Name")
                propsModel->propsData[index].Name = QString::fromStdString(propEntry.value_.get_str());
            else if (propEntry.name_ == "URL")
                propsModel->propsData[index].URL = QString::fromStdString(propEntry.value_.get_str());
            else if (propEntry.name_ == "Hash")
                propsModel->propsData[index].Hash = QString::fromStdString(propEntry.value_.get_str());
            else if (propEntry.name_ == "FeeHash")
                propsModel->propsData[index].FeeHash = QString::fromStdString(propEntry.value_.get_str());
            else if (propEntry.name_ == "BlockStart")
                propsModel->propsData[index].BlockStart = propEntry.value_.get_int64();
            else if (propEntry.name_ == "BlockEnd")
                propsModel->propsData[index].BlockEnd = propEntry.value_.get_int64();
            else if (propEntry.name_ == "TotalPaymentCount")
                propsModel->propsData[index].TotalPaymentCount = propEntry.value_.get_int64();
            else if (propEntry.name_ == "RemainingPaymentCount")
                propsModel->propsData[index].RemainingPaymentCount = propEntry.value_.get_int64();
            else if (propEntry.name_ == "PaymentAddress")
                propsModel->propsData[index].PaymentAddress = QString::fromStdString(propEntry.value_.get_str());
            else if (propEntry.name_ == "Ratio")
                propsModel->propsData[index].Ratio = propEntry.value_.get_real();
            else if (propEntry.name_ == "Yeas")
                propsModel->propsData[index].Yeas = propEntry.value_.get_int64();
            else if (propEntry.name_ == "Nays")
                propsModel->propsData[index].Nays = propEntry.value_.get_int64();
            else if (propEntry.name_ == "Abstains")
                propsModel->propsData[index].Abstains = propEntry.value_.get_int64();
            else if (propEntry.name_ == "TotalPayment")
                propsModel->propsData[index].TotalPayment = propEntry.value_.get_real();
            else if (propEntry.name_ == "MonthlyPayment")
                propsModel->propsData[index].MonthlyPayment = propEntry.value_.get_real();
            else if (propEntry.name_ == "Alloted")
                propsModel->propsData[index].Alloted = propEntry.value_.get_real();
            else if (propEntry.name_ == "IsEstablished")
                propsModel->propsData[index].IsEstablished = propEntry.value_.get_bool();
            //else if (propEntry.name_ == "TotalBudgetAlloted")
            //    propsModel->propsData[index].TotalBudgetAlloted = propEntry.value_.get_int64();
            else if (propEntry.name_ == "IsValid")
                propsModel->propsData[index].IsValid = propEntry.value_.get_bool();
            else if (propEntry.name_ == "IsValidReason")
                propsModel->propsData[index].IsValidReason = QString::fromStdString(propEntry.value_.get_str());
            else if (propEntry.name_ == "fValid")
                propsModel->propsData[index].fValid = propEntry.value_.get_bool();

        }
        index++;
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


void ProposalVoteDialog::on_btnVoteYesForAll_clicked()
{
    Array voteParams;

    voteParams.push_back("vote");
    voteParams.push_back(propsModel->currentSelectionHash.toStdString().c_str());
    voteParams.push_back("yes");

    json_spirit::Value retVal = mnbudget(voteParams, false);

    propsModel->propsData[47].Hash = propsModel->currentSelectionHash;
}


void ProposalVoteDialog::on_btnVoteNoForAll_clicked()
{
    const Array voteParams;

    voteParams.push_back("vote");
    voteParams.push_back(propsModel->currentSelectionHash.toStdString().c_str());
    voteParams.push_back("no");

    json_spirit::Value retVal = mnbudget(voteParams, false);
}


void ProposalVoteDialog::on_btnVoteAbstainForAll_clicked()
{
    Array voteParams;

    voteParams.push_back("vote");
    voteParams.push_back(propsModel->currentSelectionHash.toStdString().c_str());
    voteParams.push_back("");

    json_spirit::Value retVal = mnbudget(voteParams, false);
}

void ProposalVoteDialog::on_propsView_clicked(const QModelIndex &index)
{
    int row = index.row();
    propsModel->currentSelectionHash = propsModel->propsData[row].Hash;
}
