//---------------------------------------------------------------------------
//
// Name:        TorrentBuild_CPPDlg.cpp
// Author:      Harold Feit
// Created:     5/19/2006 11:09:52 AM
// Description: 
//
//---------------------------------------------------------------------------

#include "TorrentBuild_CPPDlg.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include "TorrentBuild_CPPDlg_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// TorrentBuild_CPPDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(TorrentBuild_CPPDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(TorrentBuild_CPPDlg::TorrentBuild_CPPDlgClose)
END_EVENT_TABLE()
////Event Table End

TorrentBuild_CPPDlg::TorrentBuild_CPPDlg(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
    CreateGUIControls();
}

TorrentBuild_CPPDlg::~TorrentBuild_CPPDlg() {} 

void TorrentBuild_CPPDlg::CreateGUIControls(void)
{
    //Do not add custom code here
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	this->SetSize(8,8,512,472);
	this->SetTitle(wxT("Build A Torrent"));
	this->Center();
	wxIcon TorrentBuild_CPPDlg_ICON (TorrentBuild_CPPDlg_XPM);
	this->SetIcon(TorrentBuild_CPPDlg_XPM);
	

	WxGauge2 = new wxGauge(this, ID_WXGAUGE2, 100, wxPoint(0,384), wxSize(504,16), wxGA_HORIZONTAL, wxDefaultValidator, wxT("WxGauge2"));
	WxGauge2->SetRange(100);
	WxGauge2->SetValue(0);

	HashProgress = new wxGauge(this, ID_HASHPROGRESS, 100, wxPoint(0,352), wxSize(504,16), wxGA_HORIZONTAL, wxDefaultValidator, wxT("HashProgress"));
	HashProgress->SetRange(100);
	HashProgress->SetValue(0);

	OptionalHashProgress = new wxGauge(this, ID_OPTIONALHASHPROGRESS, 100, wxPoint(0,320), wxSize(504,16), wxGA_HORIZONTAL, wxDefaultValidator, wxT("OptionalHashProgress"));
	OptionalHashProgress->SetRange(100);
	OptionalHashProgress->SetValue(0);

	WxStaticText7 = new wxStaticText(this, ID_WXSTATICTEXT7, wxT("Progress - Torrent Data Hashing"), wxPoint(0,368), wxSize(504,16), 0, wxT("WxStaticText7"));

	WxStaticText6 = new wxStaticText(this, ID_WXSTATICTEXT6, wxT("Progress - Current file's ED2K hash"), wxPoint(0,336), wxSize(504,16), 0, wxT("WxStaticText6"));

	WxStaticText5 = new wxStaticText(this, ID_WXSTATICTEXT5, wxT("Progress - Optiona Data Hashes"), wxPoint(0,304), wxSize(504,16), 0, wxT("WxStaticText5"));

	BuildTorrentNow = new wxButton(this, ID_BUILDTORRENTNOW, wxT("Build Torrent"), wxPoint(360,272), wxSize(144,25), 0, wxDefaultValidator, wxT("BuildTorrentNow"));
	BuildTorrentNow->SetDefault();

	MakeExternals = new wxCheckBox(this, ID_MAKEEXTERNALS, wxT("Make External Hash Files"), wxPoint(0,272), wxSize(216,16), 0, wxDefaultValidator, wxT("MakeExternals"));

	MakeTiger = new wxCheckBox(this, ID_MAKETIGER, wxT("TTH"), wxPoint(144,240), wxSize(72,16), 0, wxDefaultValidator, wxT("MakeTiger"));

	MakeED2K = new wxCheckBox(this, ID_MAKEED2K, wxT("ED2K"), wxPoint(72,256), wxSize(72,16), 0, wxDefaultValidator, wxT("MakeED2K"));

	MakeSHA1 = new wxCheckBox(this, ID_MAKESHA1, wxT("SHA1"), wxPoint(0,256), wxSize(72,16), 0, wxDefaultValidator, wxT("MakeSHA1"));

	MakeCRC32 = new wxCheckBox(this, ID_MAKECRC32, wxT("CRC32"), wxPoint(72,240), wxSize(72,16), 0, wxDefaultValidator, wxT("MakeCRC32"));

	MakeMD5 = new wxCheckBox(this, ID_MD5, wxT("MD5"), wxPoint(0,240), wxSize(72,16), 0, wxDefaultValidator, wxT("MakeMD5"));

	WxStaticText4 = new wxStaticText(this, ID_WXSTATICTEXT4, wxT("Optional hashes (Used by non-torrent peer to peer networks):"), wxPoint(0,224), wxSize(300,16), 0, wxT("WxStaticText4"));

	PrivateTorrent = new wxCheckBox(this, ID_PRIVATETORRENT, wxT("Private Torrent"), wxPoint(400,224), wxSize(104,16), 0, wxDefaultValidator, wxT("PrivateTorrent"));

	AnnounceURL = new wxTextCtrl(this, ID_ANNOUNCEURL, wxT(""), wxPoint(0,160), wxSize(376,21), 0, wxDefaultValidator, wxT("AnnounceURL"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("Announce URL:"), wxPoint(0,144), wxSize(81,16), 0, wxT("WxStaticText3"));

	AutomaticPieceSize = new wxCheckBox(this, ID_AUTOMATICPIECESIZE, wxT("Automatic Piece Size"), wxPoint(0,112), wxSize(136,16), 0, wxDefaultValidator, wxT("AutomaticPieceSize"));
	AutomaticPieceSize->SetValue(true);

	wxArrayString arrayStringFor_PieceSize;
	arrayStringFor_PieceSize.Add(wxT("32768"));
	arrayStringFor_PieceSize.Add(wxT("65536"));
	arrayStringFor_PieceSize.Add(wxT("121072"));
	arrayStringFor_PieceSize.Add(wxT("262144"));
	arrayStringFor_PieceSize.Add(wxT("524288"));
	arrayStringFor_PieceSize.Add(wxT("1048576"));
	arrayStringFor_PieceSize.Add(wxT("2097152"));
	PieceSize = new wxComboBox(this, ID_PIECESIZE, wxT("262144"), wxPoint(0,88), wxSize(120,21), arrayStringFor_PieceSize, 0, wxDefaultValidator, wxT("PieceSize"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Piece Size"), wxPoint(0,72), wxSize(54,16), 0, wxT("WxStaticText2"));

	SelectFolder = new wxButton(this, ID_SELECTFOLDER, wxT("Select Folder To Generate Torrent For"), wxPoint(248,48), wxSize(256,24), 0, wxDefaultValidator, wxT("SelectFolder"));

	SelectFile = new wxButton(this, ID_SELECTFILE, wxT("Select File To Generate Torrent For"), wxPoint(0,48), wxSize(248,24), 0, wxDefaultValidator, wxT("SelectFile"));

	FileNameToMake = new wxTextCtrl(this, ID_FileNameToMake, wxT(""), wxPoint(0,24), wxSize(504,21), 0, wxDefaultValidator, wxT("FileNameToMake"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Full path to the file or folder you want to generate torrent(s) for:"), wxPoint(0,8), wxSize(320,16), 0, wxT("WxStaticText1"));
	////GUI Items Creation End
}

void TorrentBuild_CPPDlg::TorrentBuild_CPPDlgClose(wxCloseEvent& event)
{
    Destroy();
}
 
