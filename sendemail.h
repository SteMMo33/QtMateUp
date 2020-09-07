#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QDebug>
#include "smtp/emailaddress.h"
#include "smtp/smtpclient.h"
#include "smtp/mimetext.h"



class SendEmail
{
public:
    SendEmail();

    int send();
};

#endif // SENDEMAIL_H
