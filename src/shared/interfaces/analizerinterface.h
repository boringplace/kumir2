#ifndef ANALIZER_INTERFACE_H
#define ANALIZER_INTERFACE_H

#include "error.h"
#include "lineprop.h"
#include "dataformats/ast.h"

#include "analizer_instanceinterface.h"

#include <QtCore>

namespace Shared {

class AnalizerInterface {
public:
    virtual bool primaryAlphabetIsLatin() const = 0;
    virtual bool caseInsensitiveGrammatic() const = 0;
    virtual bool indentsSignificant() const = 0;
    virtual QString languageName() const = 0;
    virtual QString defaultDocumentFileNameSuffix() const = 0;

    virtual Analizer::InstanceInterface * createInstance() = 0;
};

}

Q_DECLARE_INTERFACE(Shared::AnalizerInterface, "kumir2.Analizer")

#endif
