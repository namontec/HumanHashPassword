#include "passgenerator.h"

PassGenerator::PassGenerator()
{

}



void PassGenerator::CreateWord(QString &out, quint64 num)
{

}



void PassGenerator::Humanize(QString &in, QString &out)
{

}



QString PassGenerator::GeneratePass(QString &masterPhrase, QString &webSiteName)
{
  QString str;
  str = masterPhrase;
  for (int i = 0; i < 10 ; i++) {
    str = MD5(str).HexDigest();
  }
  str += webSiteName;
  for (int i = 0; i < 10 ; i++) {
    str = MD5(str).HexDigest();
  }
  QString out;
  Humanize(&str, &out);
  return out;
}


