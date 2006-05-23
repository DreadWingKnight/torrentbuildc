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
	

	wxArrayString arrayStringFor_PieceSize;
	arrayStringFor_PieceSize.Add(wxT("32768"));
	arrayStringFor_PieceSize.Add(wxT("65536"));
	arrayStringFor_PieceSize.Add(wxT("121072"));
	arrayStringFor_PieceSize.Add(wxT("262144"));
	arrayStringFor_PieceSize.Add(wxT("524288"));
	arrayStringFor_PieceSize.Add(wxT("1048576"));
	arrayStringFor_PieceSize.Add(wxT("2097152"));
	PieceSize = new wxComboBox(this, ID_PIECESIZE, wxT("262144"), wxPoint(0,88), wxSize(120,21), arrayStringFor_PieceSize, 0, wxDefaultValidator, wxT("PieceSize"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, wxT("Piece Size"), wxPoint(0,72), wxSize(120,16), 0, wxT("WxStaticText2"));

	SelectFolder = new wxButton(this, ID_SELECTFOLDER, wxT("Select Folder To Generate Torrent For"), wxPoint(248,48), wxSize(256,24), 0, wxDefaultValidator, wxT("SelectFolder"));

	SelectFile = new wxButton(this, ID_SELECTFILE, wxT("Select File To Generate Torrent For"), wxPoint(0,48), wxSize(248,24), 0, wxDefaultValidator, wxT("SelectFile"));

	FileNameToMake = new wxTextCtrl(this, ID_FileNameToMake, wxT(""), wxPoint(0,24), wxSize(504,20), 0, wxDefaultValidator, wxT("FileNameToMake"));

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, wxT("Full path to the file or folder you want to generate torrent(s) for:"), wxPoint(0,8), wxSize(296,17), 0, wxT("WxStaticText1"));
	////GUI Items Creation End
}

void TorrentBuild_CPPDlg::TorrentBuild_CPPDlgClose(wxCloseEvent& event)
{
    Destroy();
}
 
