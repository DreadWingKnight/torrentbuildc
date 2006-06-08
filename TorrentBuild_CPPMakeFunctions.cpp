#include "atom.h"
#include "bencode.h"
#include "util.h"
#include "stringsplit.h"

#include "TorrentBuild_CPPFunctions.h"
#include "TorrentBuild_CPPDlg.h"
#include "SHA1.h"
#include "md5.hh"

void TorrentBuild_CPPDlg::MakeTorrentFromFile( string fileToMake , int pieceSize, string announceurl, CAtom *announcelist,
string comment, bool privateTorrent, bool gensha1, bool gencrc32,
bool genmd5, bool gened2k, bool gentth, bool genexternals)
{
     CAtomDicti *pTorrentRoot = new CAtomDicti();
     CAtomDicti *pTorrentInfo = new CAtomDicti();
     pTorrentRoot->setItem( "info" , pTorrentInfo );
     vector<string> sFileName;
     StringUtils::SplitString( fileToMake, "\\", sFileName, false);
     pTorrentInfo->setItem( "name", new CAtomString( sFileName[sFileName.size()-1] ) );
     pTorrentInfo->setItem( "length", new CAtomLong( FileSize( fileToMake.c_str() ) ) );
     pTorrentInfo->setItem( "piece length", new CAtomLong( pieceSize ) );
     if( privateTorrent == true )
          pTorrentInfo->setItem( "private", new CAtomLong( 1 ) );
     if( announceurl != string() )
          pTorrentRoot->setItem( "announce", new CAtomString( announceurl ) );
     if( comment != string () )
          pTorrentRoot->setItem( "comment", new CAtomString( comment ) );
     if( announcelist && announcelist->isList() )
          pTorrentRoot->setItem( "announce-list", announcelist );
     
     // Begin Optional Hashing
     
     int OptionalHashes = 0;
     if( gensha1 == true )
     {
         CSHA1 *filesha1 = new CSHA1();
         filesha1->HashFile( (char *)(fileToMake.c_str()) );
         filesha1->Final();
         char filehash[40];
       	 memset( filehash, 0, sizeof( char ) * 40 );
         filesha1->ReportHash( filehash );
         pTorrentInfo->setItem( "sha1", new CAtomString( UTIL_StringToHash ( string( filehash ) ) ) );
         OptionalHashes++;
         OptionalHashProgress->SetValue( OptionalHashes );
     }
/*     if( genmd5 == true )
     {
         MD5 *filemd5 = new MD5();
         FILE *fIn;
         fIn = fopen(fileToMake.c_str(), "rb");
         //if(fIn == NULL) return false;
         filemd5->update( fIn );
         filemd5->finalize();
         pTorrentInfo->setItem( "md5", new CAtomString( UTIL_StringToHash ( string( filemd5->hex_digest() ) ) ) );
         OptionalHashes++;
         OptionalHashProgress->SetValue( OptionalHashes );
     }
*/
     string pathForTorrent = fileToMake + string(".torrent");
     UTIL_MakeFile( pathForTorrent.c_str() , Encode( pTorrentRoot ) );
}
