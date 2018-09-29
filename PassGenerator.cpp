#include "PassGenerator.h"

using namespace std;

QString g_english =
"pr: e i o ay \n"
"lw: ay \n"
"tm: - \n"
"ps: - \n"
"oya: g l \n"
"ea: rth ll lm ms - ns c d k l p r s t v rd rn rs rt ch df st ds th tl ts \n"
"pt: - \n"
"nst: - a e ea \n"
"ayi: ng \n"
"ai: d l n r s t nst ns \n"
"lth: ou \n"
"tr: ie u ou oy ea ee ue \n"
"ee: - c d k l m n p s t ds th ks \n"
"lls: - \n"
"nsw: e \n"
"ts: - \n"
"ia: g s t nt nts - \n"
"tt: e i \n"
"sth: eu \n"
"ndl: y \n"
"rch: i \n"
"ei: ng g th r v z gn \n"
"tw: a e o ee \n"
"ie: lds ld - ndl mh nds nd d r s gfr rc \n"
"xt: - \n"
"stl: e \n"
"spr: ea i \n"
"ndr: e \n"
"rchb: i \n"
"nds: - \n"
"eo: pl n w \n"
"eei: ng \n"
"au: r s rs ts ght \n"
"wsk: i \n"
"mh: i \n"
"str: u oy ea a e i o \n"
"ght: - e y \n"
"sts: - \n"
"ay: - l s \n"
"io: n r lch ns rs b f \n"
"ua: rds \n"
"eu: r s \n"
"eau: t \n"
"mm: e \n"
"nth: e \n"
"mn: o \n"
"ey: - \n"
"ue: sts - d \n"
"mp: - a \n"
"mr: a \n"
"tch: - \n"
"ms: - e \n"
"ui: ckl cks t \n"
"rks: - \n"
"ye: - t \n"
"ntr: y \n"
"yi: ng \n"
"dst: - \n"
"nts: - \n"
"uee: n \n"
"eye: - s \n"
"ff: - e \n"
"you: ng - rs r \n"
"bl: a e i o oo \n"
"rst: - \n"
"fl: ee a e i yi u y \n"
"nb: e \n"
"-: yea pl pr ai bl br ch cl str cr sc sh sk sl sm sn sp st sw dr dw th tm ea tr ei tw eu fl fr gl a b c d e f gr g h i j k l m n o wh p q r s t u v w wr hr eye thr io ye kn you kr spr oa oe ou \n"
"rdl: y \n"
"nc: e ou \n"
"br: ou a i o u ea \n"
"nd: - a e i ee \n"
"bt: - \n"
"ppr: oa \n"
"rld: - \n"
"ng: - e i \n"
"rc: e u \n"
"fr: ee ie a i o ai \n"
"nh: i \n"
"rd: - e i o \n"
"ft: - e y \n"
"rds: - \n"
"nk: - i \n"
"rf: u \n"
"nl: e y \n"
"rg: - o \n"
"nn: o \n"
"rk: - o \n"
"rl: e i o \n"
"rm: - a e o y \n"
"rth: - e u \n"
"ns: - e \n"
"rn: - e i ey \n"
"nt: ai au - e i o u \n"
"cc: e o \n"
"rp: - o \n"
"thg: a \n"
"rr: ia ie io i o y \n"
"rs: o eu - e \n"
"rt: - a e y ai \n"
"ch: - a e i \n"
"rv: e \n"
"rw: a \n"
"ckl: y \n"
"yea: r rs \n"
"ck: - e \n"
"cl: oa ou o \n"
"ghts: - \n"
"gh: - e \n"
"thr: ou e o u ee \n"
"oa: k rs ch \n"
"mpl: e \n"
"gfr: ie \n"
"gl: a \n"
"cks: - i \n"
"cr: ea eo ie yi e i o y \n"
"lch: i o \n"
"gn: - \n"
"ct: e o - \n"
"oe: d s \n"
"sb: a \n"
"sc: a o \n"
"gr: ee a e o ou ay ea \n"
"oi: ng nt c \n"
"kn: e i o ee \n"
"ttl: e \n"
"fts: - \n"
"kr: ie \n"
"ngth: - \n"
"sh: a e i o ie ou - \n"
"ks: - \n"
"oo: rs - d k m n r t ks \n"
"sk: - e i y \n"
"sl: ay ee a e i ai \n"
"sm: a i o \n"
"wh: a e i o y \n"
"sn: a \n"
"rms: - \n"
"sp: a o ea \n"
"a: rdl rth lf lk ll lm lr ls lt lw stl lth mp tch nc nd ng nn nt ttl nch ph pp nsw nds bl rc rd ppr rg rk rl rm rp cc rr rs rt ch ck cr sk rms - ss st dv th ngr tt lls b c d g j k l m n p ff r s t v w z fr ft gr ws rchb rch \n"
"ou: th gh nds ntr - d r s t ght ld nd nt bl bt rn rt ch \n"
"nch: e \n"
"dd: e \n"
"b: ea ee ei eo ey a e i o u y eau oo ou oy \n"
"ngd: o \n"
"c: o u y ou au - ei a e i \n"
"df: u \n"
"ss: - e io \n"
"d: - a oe e i oo o ou u y au ay ea ee ia ie \n"
"wn: - \n"
"oy: - \n"
"st: - a e oo i o y \n"
"e: ss st th nds tt tw ngth - ft rms b c ngr d f g h l m n p r s t v w xc xt ld lf ll lm lp ls lt lv ctr mn ms nb nc nd nl ns nt mpl mbl str pl pt rc rf rg rl rm rn rr rs rt rv ck cr ct sh \n"
"f: - oo ou a e i o ai u ea ee ie \n"
"g: ai ea ua ue - ia a e i o u oi oo \n"
"wr: a o \n"
"h: ou - ai a e i o u ea \n"
"sw: i o ee \n"
"ws: - \n"
"i: mm ms nc nd ng nk nt ph rst pp ps rds rth dst bl rd ch ck ghts ct sc sh ldr sl str dd st th ts ttl ff ft fts gh nst - b c d f g k l m n p r ngd s t v ngl ngs ld ll ght lt lv \n"
"j: ou oy a e u \n"
"ngl: e \n"
"k: e i ee - \n"
"ld: - e i \n"
"l: ai ay - a e i o y ea ia ie io oo ou \n"
"m: - a e i o u y oo ou ai ay ea ee \n"
"lf: - \n"
"n: ou au - ea ee a e i o ue y ia io \n"
"mphs: - \n"
"o: cks dd ss st dr ds nst th rks rld ff thg wn ws wsk - ld ll mp mr b d f g rds h j k l m n rth p r nc s nd t v ng w nl ns nt lch ph ps bl rc rd rg rk rl rm rn rr rs rt rw ck \n"
"p: oi oo ai ay - ea eo a e i o u y ie \n"
"dr: ea a e i o y \n"
"ngr: i y \n"
"ds: - \n"
"q: ui uee \n"
"ngs: - \n"
"r: a e i o u y ie oya oe ou ai ea ei - \n"
"lk: e i \n"
"s: - oo ou a e i o u ayi ai ay eei ea ee ei eu ie \n"
"dv: e i \n"
"ll: - e o u y ey \n"
"t: ea ee - a e i o u y io oo ou \n"
"hr: o \n"
"lm: - e o \n"
"dw: e \n"
"ph: - e i \n"
"u: rth lf ll str nd ng nh nl nt l n p r s t ndr bl nth rn rp ch ck sb dd st th lls ff \n"
"v: ou a e i y oya oi \n"
"w: oo ou - ai ay a e i o u ea ee \n"
"lp: - e \n"
"ctr: o \n"
"pl: ea ie a e \n"
"y: cl d l ss r s mphs sth - \n"
"lr: ea \n"
"xc: a \n"
"ldr: e \n"
"th: io ou - a e i o u y ee ei eu ey \n"
"z: e \n"
"mbl: e \n"
"lds: - \n"
"ls: - a e o \n"
"lt: - a \n"
"pp: e i y ea \n"
"lv: e \n"
"tl: y \n";


QString empty_prefix {"-"};



PassGenerator::PassGenerator()
{
  //Fill "map_" map with parsed values from "g_english"
  QStringList mapList;
  mapList = g_english.split("\n");
  map_.clear();

  for (int i = 0; i < mapList.size(); i++) {
    QString currentLine = mapList.at(i);
    int semiconPosition = currentLine.indexOf(":");
    int afterSemicolonPosition = currentLine.size() - semiconPosition - 1;

    QString mapKey = currentLine.left(semiconPosition);

    QString line = currentLine.right(afterSemicolonPosition).simplified();
    QStringList *lineList = new QStringList(line.split(" "));

    map_[mapKey] = lineList;
  }
}



void PassGenerator::CreateWord(QString &out, quint64 num)
{
  num &= quint64(0xffffffffffffffff) >> 24;
  out.clear();

  QString prefix = empty_prefix;
  while (num > 0) {
    QStringList *ary = map_[prefix];
    if (num < 1000 || (!ary && prefix == empty_prefix)/*defensive*/) {
      out += "-";
      int number = num % 1000L;
      num /= 1000;
      out += QString::number(number);
      continue;
    }
    if (!ary || !ary->size()) {
      prefix = empty_prefix;// defensive, they were filtered out
      continue;
    }

    quint64 idx = num % static_cast<quint64>(ary->size());
    num /= static_cast<quint64>(ary->size());

    QString syllable = ary->at( static_cast<int>(idx) );
    out += syllable;
    prefix = syllable;
  }
};



void PassGenerator::Humanize(const QString &in, QString &out)
{
  QByteArray baString(in.toUtf8());
  QByteArray hash( QCryptographicHash::hash(baString, hashAlgorithm()) );
  quint64 hashRaw = *( reinterpret_cast<const quint64* >(hash.data()) );
  CreateWord(out, hashRaw);
}



QCryptographicHash::Algorithm PassGenerator::hashAlgorithm() const
{
  return hashAlgorithm_;
}



void PassGenerator::setHashAlgorithm(const QCryptographicHash::Algorithm &hashAlgorithm)
{
  hashAlgorithm_ = hashAlgorithm;
}



QString PassGenerator::GeneratePass(const QString &masterPhrase, const QString &webSiteName)
{
  QString str = masterPhrase;
  for (int i = 0; i < 10 ; i++) {
    QByteArray baString(str.toUtf8());
    QByteArray hash( QCryptographicHash::hash(baString, hashAlgorithm()) );
    str = hash.toHex();
  }

  str += webSiteName;

  for (int i = 0; i < 10 ; i++) {
    QByteArray baString(str.toUtf8());
    QByteArray hash( QCryptographicHash::hash(baString, hashAlgorithm()) );
    str = hash.toHex();
  }

  QString out;
  Humanize(str, out);

  return out;
}


