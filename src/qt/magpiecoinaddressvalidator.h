// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MAGPIECOIN_QT_MAGPIECOINADDRESSVALIDATOR_H
#define MAGPIECOIN_QT_MAGPIECOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class MagpieCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MagpieCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** MagpieCoin address widget validator, checks for a valid magpiecoin address.
 */
class MagpieCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit MagpieCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // MAGPIECOIN_QT_MAGPIECOINADDRESSVALIDATOR_H
