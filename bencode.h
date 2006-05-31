//
// Copyright (C) 2003-2004 Trevor Hogan
//

#ifndef BENCODE_H
 #define BENCODE_H
#include <stdio.h>
#include <time.h>
#include <map>
#include <string>
#include <vector>
#include <utility>
 typedef __int64 int64;
 typedef unsigned __int64 uint64;

std::string EncodeInt( const CAtomInt &x );
std::string EncodeLong( const CAtomLong &x );
std::string EncodeString( const CAtomString &x );
std::string EncodeList( const CAtomList &x );
std::string EncodeDicti( const CAtomDicti &x );
std::string Encode( CAtom *pAtom );

// the decode functions allocate memory, so be SURE to delete it

// CAtomInt *DecodeInt( const string &x, unsigned long iStart = 0 );
CAtomLong *DecodeLong( const std::string &x, unsigned long iStart = 0 );
CAtomString *DecodeString( const std::string &x, unsigned long iStart = 0 );
CAtomList *DecodeList( const std::string &x, unsigned long iStart = 0 );
CAtomDicti *DecodeDicti( const std::string &x, unsigned long iStart = 0 );
CAtom *Decode( const std::string &x, unsigned long iStart = 0 );

CAtom *DecodeFile( const char *szFile );

#endif
