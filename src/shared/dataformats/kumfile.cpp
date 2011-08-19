#include "kumfile.h"


QString KumFile::toString(const Data &data)
{
    QString result;
    const QStringList lines = data.visibleText.split("\n", QString::KeepEmptyParts);
    for (int i=0; i<lines.count(); i++) {
        result += lines[i];
        if (data.protectedLineNumbers.contains(i)) {
            result += "|@protected";
        }
        if (i<lines.count()-1)
            result += "\n";
    }
    const QStringList hiddenLines = !data.hiddenText.isEmpty()? data.hiddenText.split("\n", QString::KeepEmptyParts) : QStringList();
    if (!result.isEmpty())
        result += "\n";
    for (int i=0; i<hiddenLines.count(); i++) {
        result += hiddenLines[i];
        result += "|@hidden";
        if (i<hiddenLines.count()-1)
            result += "\n";
    }
    return result;
}


QTextStream & operator <<(QTextStream & ts, const KumFile::Data & data)
{
    ts.setCodec("UTF-8");
    ts.setGenerateByteOrderMark(true);
    ts << KumFile::toString(data);
    return ts;
}

KumFile::Data KumFile::fromString(const QString &s)
{
    const QStringList lines = s.split("\n", QString::KeepEmptyParts);
    KumFile::Data data;
    data.hasHiddenText = false;
    int lineNo = -1;
    for (int i=0; i<lines.count(); i++) {
        QString line = lines[i];
        if (line.endsWith("|@hidden")) {
            data.hasHiddenText = true;
            if (!data.hiddenText.isEmpty() && data.visibleText.isEmpty())
                data.hiddenText += "\n";
            data.hiddenText += line.left(line.length()-8);
            if (i<lines.count()-1 && lines[i+1].endsWith("|@hidden"))
                data.hiddenText += "\n";
        }
        else {
            lineNo ++;
            if (line.endsWith("|@protected")) {
                data.protectedLineNumbers.insert(lineNo);
                data.visibleText += line.left(line.length()-11);
            }
            else {
                data.visibleText += line;
            }
            if (i<lines.count()-1 && !lines[i+1].endsWith("|@hidden"))
                data.visibleText += "\n";
        }
    }
    return data;
}

QTextStream & operator >>(QTextStream & ts, KumFile::Data & data)
{
    ts.setAutoDetectUnicode(true);
    QString s = ts.readAll();
    data = KumFile::fromString(s);
    return ts;
}


