#ifndef ANALIZER_P_H
#define ANALIZER_P_H

#include "abstractsyntaxtree/lexem.h"
#include "statement.h"
#include "interfaces/lexemtype.h"
#include "interfaces/error.h"
#include "interfaces/lineprop.h"
#include "abstractsyntaxtree/ast.h"

#include <QtCore>

using AST::Lexem;

typedef AST::Data AST_Data;

namespace KumirAnalizer {

typedef QList<AST::Statement*> * LAS;

struct AnalizerPrivate
{

    explicit AnalizerPrivate(class Analizer *);
    ~AnalizerPrivate();

    enum AnalizeSubject {
        SubjWholeText,
        SubjAlgorhtitm,
        SubjStatements
    };

    class Analizer * q;
    class Lexer * lexer;
    class PDAutomata * pdAutomata;
    class SyntaxAnalizer * analizer;
    AST_Data * ast;

    QStringList sourceText;
    QList<Statement*> statements;
    static QLocale::Language nativeLanguage;

    /** Find algorhitm in AST by real line number */
    static AST::Algorhitm * findAlgorhitmByPos(AST::Data * data, int pos);

    /** Find begin/end iterators in AST instructions list,
      * containing provided lexem groups
      * @param IN data - AST
      * @param IN statements - list of lexem groups
      * @param OUT lst - list of AST instructions
      * @param OUT begin - begin iterator
      * @param OUT end - end iterator
      * @param OUT mod - module reference
      * @param OUT alg - algorhitm reference
      * @return true on found, false if not found
      */
    static bool findInstructionsBlock(AST::Data * data
                                      , const QList<Statement*> statements
                                      , LAS & lst
                                      , int & begin
                                      , int & end
                                      , AST::Module* & mod
                                      , AST::Algorhitm* & alg
                                      );
    /** Find context of AST instructions list,
      * containing provided lexem groups
      * @param IN data - AST
      * @param IN statements - list of lexem groups
      * @param IN pos - position, where lexems inserted
      * @param OUT lst - list of AST instructions
      * @param OUT outPos - position, where statements to be insert
      * @param OUT mod - module reference
      * @param OUT alg - algorhitm reference
      * @return true on found, false if not found
      */
    static bool findInstructionsBlock(AST::Data * data
                                      , const QList<Statement*> statements
                                      , int pos
                                      , LAS & lst
                                      , int & outPos
                                      , AST::Module* & mod
                                      , AST::Algorhitm* & alg
                                      );

    AnalizeSubject analizeSubject(const QList<Statement*> & statements) const;


    void doCompilation(AnalizeSubject whatToCompile
                       , QList<Statement*> & oldStatements
                       , QList<Statement*> & newStatements
                       , QList<Statement*> & allStatements
                       , int whereInserted
                       );

};

extern AnalizerPrivate::AnalizeSubject operator * ( const AnalizerPrivate::AnalizeSubject &first
                                                   , const AnalizerPrivate::AnalizeSubject &second );


}

#endif // ANALIZER_P_H
