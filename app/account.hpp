#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <vector>

enum class Status
{
    OK,
    NOK,
    LACK_OF_FOUNDS
};

class I_Account
{
    public:
        virtual ~I_Account() = default;

        virtual Status deposit( unsigned int payment ) = 0;
        virtual Status withdrawal( unsigned int payment ) = 0;
        virtual Status transfer_to( unsigned int value, I_Account& account ) = 0;

        virtual unsigned int check_balance() const = 0;
};

class Account final : public I_Account
{
    public:
        Status deposit( unsigned int payment ) override;
        Status withdrawal( unsigned int payment ) override;
        Status transfer_to( unsigned int payment, I_Account& account ) override;

        unsigned int check_balance() const;

    private:
        unsigned int balance = 0;
        std::vector< std::string > transaction_history;
};

#endif // ACCOUNT_HPP
