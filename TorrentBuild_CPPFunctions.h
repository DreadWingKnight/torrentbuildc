//---------------------------------------------------------------------------
//
// Name:        TorrentBuild_CPPFunctions.h
// Author:      Harold Feit
// Created:     5/19/2006 11:09:52 AM
// Description: 
//
//---------------------------------------------------------------------------

#include "atom.h"
#include "bencode.h"

#ifndef __TorrentBuild_CPPFunctions_h__
#define __TorrentBuild_CPPFunctions_h__

void MakeTorrentFromFile();
CAtom *GetConfig();
int GetAutoPieceSize ( long TotalSize );
#endif
