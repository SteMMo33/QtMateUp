#include "sendemail.h"

SendEmail::SendEmail()
{
    qDebug() << "[SendEmail] C'tor";
}



int SendEmail::send()
{
    qDebug() << "[SendEmail] send";

    // First we need to create an SmtpClient object
    SmtpClient smtp("cp3.pcsgroup.solutions", 465, SmtpClient::SslConnection);

    // We need to set the username (your email address) and password
    // for smtp authentification.
    smtp.setUser("atk");
    smtp.setPassword("AmteK_2017$");

    // Now we create a MimeMessage object. This is the email.
    MimeMessage message;

    EmailAddress sender("s.mora@amtek.it", "Your Name");
    message.setSender(&sender);

    EmailAddress to("s.mora@amtek.it", "Recipient's Name");
    message.addRecipient(&to);

    message.setSubject("SmtpClient for Qt - Demo");

    // Now add some text to the email.
    // First we create a MimeText object.
    MimeText text;
    text.setText("Hi,\nThis is a simple email message from AMtek Locker.\n");

    // Now add it to the mail
    message.addPart(&text);

    // Now we can send the mail
    if (!smtp.connectToHost()) {
        qDebug() << "Failed to connect to host!" << endl;
        return -1;
    }

    if (!smtp.login()) {
        qDebug() << "Failed to login!" << endl;
        return -2;
    }

    if (!smtp.sendMail(message)) {
        qDebug() << "Failed to send mail!" << endl;
        return -3;
    }

    smtp.quit();
    return 1;
}
