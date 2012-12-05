#ifndef STDLIBMODULES_H
#define STDLIBMODULES_H
#include <QtCore>
#include "interfaces/actorinterface.h"
#include "stdlib/kumirstdlib.hpp"

namespace StdLibModules {

class RTL
        : public Shared::ActorInterface

{
public:
    inline QString name() const {return QString::fromUtf8("Стандартные функции");}
    QStringList funcList() const {
        QStringList result;
        // TODO implement non-russian headers
        // (check system locale)

        /* 0x0000 */ result << QString::fromUtf8("алг вещ abs(вещ x)");
        /* 0x0001 */ result << QString::fromUtf8("алг вещ arccos(вещ x)");
        /* 0x0002 */ result << QString::fromUtf8("алг вещ arcctg(вещ x)");
        /* 0x0003 */ result << QString::fromUtf8("алг вещ arcsin(вещ x)");
        /* 0x0004 */ result << QString::fromUtf8("алг вещ arctg(вещ x)");
        /* 0x0005 */ result << QString::fromUtf8("алг вещ cos(вещ x)");
        /* 0x0006 */ result << QString::fromUtf8("алг вещ ctg(вещ x)");
        /* 0x0007 */ result << QString::fromUtf8("алг delay(цел x)");
        /* 0x0008 */ result << QString::fromUtf8("алг цел div(цел x, цел y)");
        /* 0x0009 */ result << QString::fromUtf8("алг вещ exp(вещ x)");
        /* 0x000a */ result << QString::fromUtf8("алг цел iabs(цел x)");
        /* 0x000b */ result << QString::fromUtf8("алг цел imax(цел x, цел y)");
        /* 0x000c */ result << QString::fromUtf8("алг цел imin(цел x, цел y)");
        /* 0x000d */ result << QString::fromUtf8("алг цел int(вещ x)");
        /* 0x000e */ result << QString::fromUtf8("алг цел irand(цел x, цел y)");
        /* 0x000f */ result << QString::fromUtf8("алг цел irnd(цел x)");
        /* 0x0010 */ result << QString::fromUtf8("алг вещ lg(вещ x)");
        /* 0x0011 */ result << QString::fromUtf8("алг вещ ln(вещ x)");
        /* 0x0012 */ result << QString::fromUtf8("алг вещ max(вещ x, вещ y)");
        /* 0x0013 */ result << QString::fromUtf8("алг вещ min(вещ x, вещ y)");
        /* 0x0014 */ result << QString::fromUtf8("алг цел mod(цел x, цел y)");
        /* 0x0015 */ result << QString::fromUtf8("алг вещ rand(вещ x, вещ y)");
        /* 0x0016 */ result << QString::fromUtf8("алг вещ rnd(вещ x)");
        /* 0x0017 */ result << QString::fromUtf8("алг цел sign(вещ x)");
        /* 0x0018 */ result << QString::fromUtf8("алг вещ sin(вещ x)");
        /* 0x0019 */ result << QString::fromUtf8("алг вещ sqrt(вещ x)");
        /* 0x001a */ result << QString::fromUtf8("алг вещ tg(вещ x)");
        /* 0x001b */ result << QString::fromUtf8("алг вещ МАКСВЕЩ");
        /* 0x001c */ result << QString::fromUtf8("алг цел МАКСЦЕЛ");
        /* 0x001d */ result << QString::fromUtf8("алг лит вещ_в_лит(вещ x)");
        /* 0x001e */ result << QString::fromUtf8("алг цел время");
        /* 0x001f */ result << QString::fromUtf8("алг цел длин(лит s)");
        /* 0x0020 */ result << QString::fromUtf8("алг цел код(сим ch)");
        /* 0x0021 */ result << QString::fromUtf8("алг вещ лит_в_вещ(лит s, рез лог success)");
        /* 0x0022 */ result << QString::fromUtf8("алг цел лит_в_цел(лит s, рез лог success)");
        /* 0x0023 */ result << QString::fromUtf8("алг сим символ(цел n)");
        /* 0x0024 */ result << QString::fromUtf8("алг сим символ2(цел n)");
        /* 0x0025 */ result << QString::fromUtf8("алг лит цел_в_лит(цел n)");
        /* 0x0026 */ result << QString::fromUtf8("алг цел юникод(сим ch)");


        return result;
    }
};

class Files
        : public Shared::ActorInterface
{
    inline QString name() const {return QString::fromUtf8("Файлы");}
    inline TypeList typeList() const {
        // TODO implement non-russian headers
        // (check system locale)

        TypeList result;
        CustomType fileType;
        fileType.first = QString::fromUtf8("файл");
        fileType.second = sizeof(Kumir::FileType);
        result << fileType;
        return result;
    }
    QStringList funcList() const {
        QStringList result;
        // TODO implement non-russian headers
        // (check system locale)

        /* 0x0000 */ result << QString::fromUtf8("алг файл открыть на чтение(лит имя файла)");
        /* 0x0001 */ result << QString::fromUtf8("алг файл открыть на запись(лит имя файла)");
        /* 0x0002 */ result << QString::fromUtf8("алг файл открыть на добавление(лит имя файла)");
        /* 0x0003 */ result << QString::fromUtf8("алг закрыть(файл ключ)");
        /* 0x0004 */ result << QString::fromUtf8("алг начать чтение(файл ключ)");
        /* 0x0005 */ result << QString::fromUtf8("алг лог конец файла(файл ключ)");

        /* 0x0006 */ result << QString::fromUtf8("алг установить кодировку(лит кодировка)");

        return result;
    }
};

}



#endif