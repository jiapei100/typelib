/*
 * PUBLIC DOMAIN PCCTS-BASED C++ GRAMMAR (cplusplus.g, stat.g, expr.g)
 *
 * Authors: Sumana Srinivasan, NeXT Inc.;            sumana_srinivasan@next.com
 *          Terence Parr, Parr Research Corporation; parrt@parr-research.com
 *          Russell Quong, Purdue University;        quong@ecn.purdue.edu
 *
 * SOFTWARE RIGHTS
 *
 * This file is a part of the ANTLR-based C++ grammar and is free
 * software.  We do not reserve any LEGAL rights to its use or
 * distribution, but you may NOT claim ownership or authorship of this
 * grammar or support code.  An individual or company may otherwise do
 * whatever they wish with the grammar distributed herewith including the
 * incorporation of the grammar or the output generated by ANTLR into
 * commerical software.  You may redistribute in source or binary form
 * without payment of royalties to us as long as this header remains
 * in all source distributions.
 *
 * We encourage users to develop parsers/tools using this grammar.
 * In return, we ask that credit is given to us for developing this
 * grammar.  By "credit", we mean that if you incorporate our grammar or
 * the generated code into one of your programs (commercial product,
 * research project, or otherwise) that you acknowledge this fact in the
 * documentation, research report, etc....  In addition, you should say nice
 * things about us at every opportunity.
 *
 * As long as these guidelines are kept, we expect to continue enhancing
 * this grammar.  Feel free to send us enhancements, fixes, bug reports,
 * suggestions, or general words of encouragement at parrt@parr-research.com.
 * 
 * NeXT Computer Inc.
 * 900 Chesapeake Dr.
 * Redwood City, CA 94555
 * 12/02/1994
 * 
 * Restructured for public consumption by Terence Parr late February, 1995.
 *
 * Requires PCCTS 1.32b4 or higher to get past ANTLR. 
 * 
 * DISCLAIMER: we make no guarantees that this grammar works, makes sense,
 *             or can be used to do anything useful.
 */
/*
 * Dictionary.h -- A cool hash table
 *
 * Terence Parr
 * Parr Research Corporation
 * January 1995
 */
/* 1999-2004 Version 3.0 July 2004
 * Modified by David Wigg at London South Bank University for CPP_parser.g
 *
 * See MyReadMe.txt for further information
 *
 * This file is best viewed in courier font with tabs set to 4 spaces
 */

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <iostream>
#include "DictEntry.hh"

class Dictionary 
{
    protected:
        DictEntry **scope, **endScope;
        int nscopes, currentScope;
        DictEntry **bucket;
        int nbuckets;
        static unsigned char randomNumbers[];
//        static char *strings;
//        static char *strp;
//        static unsigned strsize;

        virtual void dumpSymbol(FILE *, DictEntry *);

        virtual int hash(const std::string& s);

    public:
        Dictionary(int nb=43, int ns=60, int nc=30000);
        virtual ~Dictionary();
        DictEntry *lookup(const std::string&);

        void define(const std::string&, DictEntry *);
        void defineInScope(const std::string&, DictEntry *, int);

        void saveScope();
        void restoreScope();

        DictEntry *getCurrentScope();
        int getCurrentScopeIndex();
        
        DictEntry *removeScope(int scope=-1);
        DictEntry *remove(const std::string&);
        DictEntry *remove(DictEntry *);

        void dumpScope(FILE *, int scope=-1);
        void dumpScopes();

        virtual void panic(char const *);
};

#endif

