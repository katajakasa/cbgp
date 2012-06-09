///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __PROTO_H__
#define __PROTO_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gauge.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/scrolwin.h>
#include <wx/wizard.h>
#include <wx/dynarray.h>
WX_DEFINE_ARRAY_PTR( wxWizardPageSimple*, WizardPages );
#include <wx/treectrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GitImportDialogProto
///////////////////////////////////////////////////////////////////////////////
class GitImportDialogProto : public wxWizard 
{
	private:
	
	protected:
		wxTextCtrl* localDir;
		wxButton* selectLocalDirButton;
		wxTextCtrl* remoteDir;
		wxButton* selectRemoteDirButton;
		wxGauge* cloneProgress;
		wxRichTextCtrl* importLog;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnPageChanged( wxWizardEvent& event ) { event.Skip(); }
		virtual void OnPageChanging( wxWizardEvent& event ) { event.Skip(); }
		virtual void OnLocalDirectoryChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnLocalDirClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoteDirectoryChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoteDirClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GitImportDialogProto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Clone Repository"), const wxBitmap& bitmap = wxNullBitmap, const wxPoint& pos = wxDefaultPosition, long style = wxDEFAULT_DIALOG_STYLE );
		WizardPages m_pages;
		~GitImportDialogProto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class GitCommitDialogProto
///////////////////////////////////////////////////////////////////////////////
class GitCommitDialogProto : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* branchLabel;
		wxTextCtrl* commentText;
		wxTreeCtrl* changesTree;
		wxStdDialogButtonSizer* bottomButtonSizer;
		wxButton* bottomButtonSizerOK;
		wxButton* bottomButtonSizerCancel;
	
	public:
		
		GitCommitDialogProto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Commit"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 649,534 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~GitCommitDialogProto();
	
};

#endif //__PROTO_H__
