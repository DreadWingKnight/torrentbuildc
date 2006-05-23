//---------------------------------------------------------------------------
//
// Name:        TorrentBuild_CPPDlg.h
// Author:      Harold Feit
// Created:     5/19/2006 11:09:52 AM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __TorrentBuild_CPPDLG_h__
#define __TorrentBuild_CPPDLG_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
#include <wx/gauge.h>
#include <wx/checkbox.h>
#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
////Header Include End

//Compatibility for 2.4 code
#ifndef wxCLOSE_BOX
	#define wxCLOSE_BOX 0x1000
#endif
#ifndef wxFIXED_MINSIZE
	#define wxFIXED_MINSIZE 0
#endif

////Dialog Style Start
#undef TorrentBuild_CPPDlg_STYLE
#define TorrentBuild_CPPDlg_STYLE wxCAPTION | wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class TorrentBuild_CPPDlg : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		TorrentBuild_CPPDlg(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("TorrentBuild_CPP"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = TorrentBuild_CPPDlg_STYLE);
		virtual ~TorrentBuild_CPPDlg();
	
	public:
		//Do not add custom control declarations
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxGauge *WxGauge2;
		wxGauge *HashProgress;
		wxGauge *OptionalHashProgress;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxButton *BuildTorrentNow;
		wxCheckBox *MakeExternals;
		wxCheckBox *MakeTiger;
		wxCheckBox *MakeED2K;
		wxCheckBox *MakeSHA1;
		wxCheckBox *MakeCRC32;
		wxCheckBox *MakeMD5;
		wxStaticText *WxStaticText4;
		wxCheckBox *PrivateTorrent;
		wxTextCtrl *AnnounceURL;
		wxStaticText *WxStaticText3;
		wxCheckBox *AutomaticPieceSize;
		wxComboBox *PieceSize;
		wxStaticText *WxStaticText2;
		wxButton *SelectFolder;
		wxButton *SelectFile;
		wxTextCtrl *FileNameToMake;
		wxStaticText *WxStaticText1;
		////GUI Control Declaration End
		
	public:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXGAUGE2 = 1025,
			ID_HASHPROGRESS = 1024,
			ID_OPTIONALHASHPROGRESS = 1023,
			ID_WXSTATICTEXT7 = 1022,
			ID_WXSTATICTEXT6 = 1021,
			ID_WXSTATICTEXT5 = 1020,
			ID_BUILDTORRENTNOW = 1019,
			ID_MAKEEXTERNALS = 1018,
			ID_MAKETIGER = 1017,
			ID_MAKEED2K = 1016,
			ID_MAKESHA1 = 1015,
			ID_MAKECRC32 = 1014,
			ID_MD5 = 1013,
			ID_WXSTATICTEXT4 = 1012,
			ID_PRIVATETORRENT = 1011,
			ID_ANNOUNCEURL = 1010,
			ID_WXSTATICTEXT3 = 1009,
			ID_AUTOMATICPIECESIZE = 1008,
			ID_PIECESIZE = 1007,
			ID_WXSTATICTEXT2 = 1006,
			ID_SELECTFOLDER = 1005,
			ID_SELECTFILE = 1004,
			ID_FileNameToMake = 1003,
			ID_WXSTATICTEXT1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		}; //End of Enum
	
	public:
		void TorrentBuild_CPPDlgClose(wxCloseEvent& event);
		void CreateGUIControls(void);
};

#endif
