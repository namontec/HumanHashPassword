#ifndef PASSGENERATOR_H
#define PASSGENERATOR_H

#include <QString>

class PassGenerator
{
public:
    PassGenerator();
    QString GeneratePass(QString& masterPhrase, QString& webSiteName);

private:
    void CreateWord();
    void Humanize();


};

#endif // PASSGENERATOR_H
