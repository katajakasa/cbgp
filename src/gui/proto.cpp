///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "proto.h"

///////////////////////////////////////////////////////////////////////////

GitImportDialogProto::GitImportDialogProto( wxWindow* parent, wxWindowID id, const wxString& title, const wxBitmap& bitmap, const wxPoint& pos, long style ) 
{
	this->Create( parent, id, title, bitmap, pos, style );
	this->SetSizeHints( wxSize( 500,350 ), wxDefaultSize );
	
	wxWizardPageSimple* pathPage = new wxWizardPageSimple( this );
	m_pages.Add( pathPage );
	
	pathPage->SetMinSize( wxSize( 500,350 ) );
	pathPage->SetMaxSize( wxSize( 500,350 ) );
	
	wxGridBagSizer* pathPageSizer;
	pathPageSizer = new wxGridBagSizer( 0, 0 );
	pathPageSizer->SetFlexibleDirection( wxBOTH );
	pathPageSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	cloneInfoText = new wxStaticText( pathPage, wxID_ANY, wxT("For clone operation, the following information is required."), wxDefaultPosition, wxDefaultSize, 0 );
	cloneInfoText->Wrap( -1 );
	pathPageSizer->Add( cloneInfoText, wxGBPosition( 0, 0 ), wxGBSpan( 1, 1 ), wxALL, 5 );
	
	wxStaticBoxSizer* dsPathInfo;
	dsPathInfo = new wxStaticBoxSizer( new wxStaticBox( pathPage, wxID_ANY, wxT("Local Directory") ), wxHORIZONTAL );
	
	localDir = new wxTextCtrl( pathPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dsPathInfo->Add( localDir, 1, wxALL, 5 );
	
	selectLocalDirButton = new wxButton( pathPage, wxID_ANY, wxT("Select ..."), wxDefaultPosition, wxDefaultSize, 0 );
	dsPathInfo->Add( selectLocalDirButton, 0, wxALL, 5 );
	
	
	pathPageSizer->Add( dsPathInfo, wxGBPosition( 1, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	wxStaticBoxSizer* usPathInfo;
	usPathInfo = new wxStaticBoxSizer( new wxStaticBox( pathPage, wxID_ANY, wxT("Remote Directory") ), wxHORIZONTAL );
	
	remoteDir = new wxTextCtrl( pathPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	usPathInfo->Add( remoteDir, 1, wxALL, 5 );
	
	selectRemoteDirButton = new wxButton( pathPage, wxID_ANY, wxT("Select ..."), wxDefaultPosition, wxDefaultSize, 0 );
	usPathInfo->Add( selectRemoteDirButton, 0, wxALL, 5 );
	
	
	pathPageSizer->Add( usPathInfo, wxGBPosition( 2, 0 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	pathPageSizer->Add( 0, 0, wxGBPosition( 3, 1 ), wxGBSpan( 1, 1 ), wxEXPAND, 5 );
	
	
	pathPageSizer->AddGrowableCol( 0 );
	pathPageSizer->AddGrowableRow( 3 );
	
	pathPage->SetSizer( pathPageSizer );
	pathPage->Layout();
	pathPageSizer->Fit( pathPage );
	wxWizardPageSimple* importPage = new wxWizardPageSimple( this );
	m_pages.Add( importPage );
	
	wxFlexGridSizer* importPageSizer;
	importPageSizer = new wxFlexGridSizer( 0, 2, 0, 0 );
	importPageSizer->AddGrowableCol( 0 );
	importPageSizer->AddGrowableRow( 0 );
	importPageSizer->SetFlexibleDirection( wxBOTH );
	importPageSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	importScroller = new wxScrolledWindow( importPage, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxSUNKEN_BORDER|wxVSCROLL );
	importScroller->SetScrollRate( 5, 5 );
	wxBoxSizer* importScrollerSizer;
	importScrollerSizer = new wxBoxSizer( wxVERTICAL );
	
	importLog = new wxRichTextCtrl( importScroller, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0|wxVSCROLL|wxHSCROLL|wxNO_BORDER|wxWANTS_CHARS );
	importScrollerSizer->Add( importLog, 1, wxEXPAND | wxALL, 0 );
	
	
	importScroller->SetSizer( importScrollerSizer );
	importScroller->Layout();
	importScrollerSizer->Fit( importScroller );
	importPageSizer->Add( importScroller, 1, wxEXPAND | wxALL, 5 );
	
	
	importPage->SetSizer( importPageSizer );
	importPage->Layout();
	importPageSizer->Fit( importPage );
	wxWizardPageSimple* completePage = new wxWizardPageSimple( this );
	m_pages.Add( completePage );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	allDoneLabel = new wxStaticText( completePage, wxID_ANY, wxT("zomg! All done!"), wxDefaultPosition, wxDefaultSize, 0 );
	allDoneLabel->Wrap( -1 );
	bSizer1->Add( allDoneLabel, 0, wxALL, 5 );
	
	
	completePage->SetSizer( bSizer1 );
	completePage->Layout();
	bSizer1->Fit( completePage );
	
	this->Centre( wxBOTH );
	
	for ( unsigned int i = 1; i < m_pages.GetCount(); i++ )
	{
		m_pages.Item( i )->SetPrev( m_pages.Item( i - 1 ) );
		m_pages.Item( i - 1 )->SetNext( m_pages.Item( i ) );
	}
	
	// Connect Events
	this->Connect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGED, wxWizardEventHandler( GitImportDialogProto::OnPageChanged ) );
	this->Connect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler( GitImportDialogProto::OnPageChanging ) );
	selectLocalDirButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GitImportDialogProto::OnLocalDirClick ), NULL, this );
	selectRemoteDirButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GitImportDialogProto::OnRemoteDirClick ), NULL, this );
}

GitImportDialogProto::~GitImportDialogProto()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGED, wxWizardEventHandler( GitImportDialogProto::OnPageChanged ) );
	this->Disconnect( wxID_ANY, wxEVT_WIZARD_PAGE_CHANGING, wxWizardEventHandler( GitImportDialogProto::OnPageChanging ) );
	selectLocalDirButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GitImportDialogProto::OnLocalDirClick ), NULL, this );
	selectRemoteDirButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GitImportDialogProto::OnRemoteDirClick ), NULL, this );
	
	m_pages.Clear();
}
