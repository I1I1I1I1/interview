#include "account.hpp"

Status Account::deposit( unsigned int payment )
{
    balance += payment;
    transaction_history.emplace_back( std::to_string( payment ) );

    return Status::OK;
}

Status Account::withdrawal( unsigned int payment )
{
    if( balance < payment )
    {
        return Status::LACK_OF_FOUNDS;
    }

    balance -= payment;
    transaction_history.emplace_back( "-" + std::to_string( payment ) );

    return Status::OK;
}

Status Account::transfer_to( unsigned int payment, I_Account& account )
{
    if( balance < payment )
    {
        return Status::LACK_OF_FOUNDS;
    }

    balance -= payment;
    transaction_history.emplace_back( "-" + std::to_string( payment ) );

    return Status::OK;
}

unsigned int Account::check_balance() const
{
    return balance;
}
