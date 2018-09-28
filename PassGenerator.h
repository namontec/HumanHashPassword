#ifndef PASSGENERATOR_H
#define PASSGENERATOR_H

#include <QVariant>
#include <QString>
#include <QStringList>
#include <QCryptographicHash>
#include <QMap>
#include <QVector>
#include <iostream>


class PassGenerator
{
public:
    PassGenerator();
    QString GeneratePass(const QString &masterPhrase, const QString &webSiteName);

    QCryptographicHash::Algorithm hashAlgorithm() const;
    void setHashAlgorithm(const QCryptographicHash::Algorithm &hashAlgorithm);

private:
    void CreateWord(QString &out, quint64 num);
    void Humanize(const QString &in, QString &out);

private:
    QCryptographicHash::Algorithm hashAlgorithm_ = QCryptographicHash::Md5;
    QMap<QString, QStringList*> map_;

};

#endif // PASSGENERATOR_H
