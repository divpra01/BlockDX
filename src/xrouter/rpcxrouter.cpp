#include "json/json_spirit_reader_template.h"
#include "json/json_spirit_writer_template.h"
#include "json/json_spirit_utils.h"

#include <exception>
#include <iostream>

#include "xrouterapp.h"
#include "uint256.h"
using namespace json_spirit;

//******************************************************************************
//******************************************************************************
Value xrGetBlock(const Array & params, bool fHelp)
{
    if (fHelp) {
        throw std::runtime_error("xrGetBlock\nLookup blocks in a specified blockchain.");
    }

    if (params.size() < 1)
    {
        Object error;
        error.emplace_back(Pair("error", "Currency not specified"));
        error.emplace_back(Pair("name",     __FUNCTION__));
        return error;
    }

    if (params.size() < 2)
    {
        Object error;
        error.emplace_back(Pair("error", "Block hash not specified"));
        error.emplace_back(Pair("name",     __FUNCTION__));
        return error;
    }

    std::string currency    = params[0].get_str();
    Object result;

    std::string reply = xrouter::App::instance().getBlock(currency, params[1].get_str());
    Object obj;
    obj.emplace_back(Pair("reply", reply));
    return obj;
}

Value xrGetTransaction(const Array & params, bool fHelp)
{
    if (fHelp) {
        throw std::runtime_error("xrGetTransaction\nLookup blocks in a specified blockchain.");
    }

    if (params.size() < 1)
    {
        Object error;
        error.emplace_back(Pair("error", "Currency not specified"));
        error.emplace_back(Pair("name",     __FUNCTION__));
        return error;
    }

    if (params.size() < 2)
    {
        Object error;
        error.emplace_back(Pair("error", "Tx hash not specified"));
        error.emplace_back(Pair("name",     __FUNCTION__));
        return error;
    }

    std::string currency    = params[0].get_str();
    Object result;

    std::string reply = xrouter::App::instance().getTransaction(currency, params[1].get_str());
    Object obj;
    obj.emplace_back(Pair("reply", reply));
    return obj;
}

Value xrGetBalance(const Array & params, bool fHelp)
{
    if (fHelp) {
        throw std::runtime_error("xrGetBalance\nReturns balances for selected currency.");
    }

    if (params.size() < 1)
    {
        Object error;
        error.emplace_back(Pair("error", "Currency not specified"));
        error.emplace_back(Pair("name",     __FUNCTION__));
        return error;
    }

    if (params.size() < 2)
    {
        Object error;
        error.emplace_back(Pair("error", "Auth data not specified"));
        error.emplace_back(Pair("name",     __FUNCTION__));
        return error;
    }

    std::string currency = params[0].get_str();
    std::string auth = params[1].get_str();
    Object result;

    std::string reply = xrouter::App::instance().getBalances(currency, auth);
    Object obj;
    obj.emplace_back(Pair("reply", reply));
    return obj;
}
