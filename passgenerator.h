#ifndef PASSGENERATOR_H
#define PASSGENERATOR_H

#include <QString>

class PassGenerator
{
public:
    PassGenerator();
    QString GeneratePass(QString &masterPhrase, QString &webSiteName);

private:
    void CreateWord(QString &out, quint64 num);
    void Humanize(QString &in, QString &out);


};

#endif // PASSGENERATOR_H
