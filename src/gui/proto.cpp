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
	
	wxFlexGridSizer* pathBaseSizer;
	pathBaseSizer = new wxFlexGridSizer( 4, 1, 0, 0 );
	pathBaseSizer->AddGrowableCol( 0 );
	pathBaseSizer->AddGrowableRow( 3 );
	pathBaseSizer->SetFlexibleDirection( wxBOTH );
	pathBaseSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticText* cloneInfoText;
	cloneInfoText = new wxStaticText( pathPage, wxID_ANY, wxT("For clone operation, the following information is required."), wxDefaultPosition, wxDefaultSize, 0 );
	cloneInfoText->Wrap( -1 );
	pathBaseSizer->Add( cloneInfoText, 0, wxALL, 5 );
	
	wxStaticBoxSizer* dsPathInfo;
	dsPathInfo = new wxStaticBoxSizer( new wxStaticBox( pathPage, wxID_ANY, wxT("Local Directory") ), wxHORIZONTAL );
	
	localDir = new wxTextCtrl( pathPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dsPathInfo->Add( localDir, 1, wxALL, 5 );
	
	selectLocalDirButton = new wxButton( pathPage, wxID_ANY, wxT("Select ..."), wxDefaultPosition, wxDefaultSize, 0 );
	dsPathInfo->Add( selectLocalDirButton, 0, wxALL, 5 );
	
	
	pathBaseSizer->Add( dsPathInfo, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* usPathInfo;
	usPathInfo = new wxStaticBoxSizer( new wxStaticBox( pathPage, wxID_ANY, wxT("Remote Directory") ), wxHORIZONTAL );
	
	remoteDir = new wxTextCtrl( pathPage, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	usPathInfo->Add( remoteDir, 1, wxALL, 5 );
	
	selectRemoteDirButton = new wxButton( pathPage, wxID_ANY, wxT("Select ..."), wxDefaultPosition, wxDefaultSize, 0 );
	usPathInfo->Add( selectRemoteDirButton, 0, wxALL, 5 );
	
	
	pathBaseSizer->Add( usPathInfo, 1, wxEXPAND, 5 );
	
	
	pathBaseSizer->Add( 0, 0, 1, wxEXPAND, 5 );
	
	
	pathPage->SetSizer( pathBaseSizer );
	pathPage->Layout();
	pathBaseSizer->Fit( pathPage );
	wxWizardPageSimple* importPage = new wxWizardPageSimple( this );
	m_pages.Add( importPage );
	
	wxFlexGridSizer* importPageSizer;
	importPageSizer = new wxFlexGridSizer( 3, 1, 0, 0 );
	importPageSizer->AddGrowableCol( 0 );
	importPageSizer->AddGrowableRow( 2 );
	importPageSizer->SetFlexibleDirection( wxBOTH );
	importPageSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticText* cloneHelpText;
	cloneHelpText = new wxStaticText( importPage, wxID_ANY, wxT("Cloning repository, please wait ..."), wxDefaultPosition, wxDefaultSize, 0 );
	cloneHelpText->Wrap( -1 );
	importPageSizer->Add( cloneHelpText, 0, wxALL, 5 );
	
	cloneProgress = new wxGauge( importPage, wxID_ANY, 100, wxDefaultPosition, wxSize( -1,25 ), wxGA_HORIZONTAL );
	importPageSizer->Add( cloneProgress, 0, wxALL|wxEXPAND, 5 );
	
	wxScrolledWindow* importScroller;
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

GitCommitDialogProto::GitCommitDialogProto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxFlexGridSizer* baseSizer;
	baseSizer = new wxFlexGridSizer( 3, 1, 0, 0 );
	baseSizer->AddGrowableCol( 0 );
	baseSizer->AddGrowableRow( 1 );
	baseSizer->AddGrowableRow( 2 );
	baseSizer->SetFlexibleDirection( wxBOTH );
	baseSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* infoSizer;
	infoSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Information") ), wxVERTICAL );
	
	wxFlexGridSizer* infoHSizer;
	infoHSizer = new wxFlexGridSizer( 1, 1, 0, 0 );
	infoHSizer->AddGrowableCol( 0 );
	infoHSizer->AddGrowableRow( 0 );
	infoHSizer->SetFlexibleDirection( wxBOTH );
	infoHSizer->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	branchLabel = new wxStaticText( this, wxID_ANY, wxT("Commit to branch: master"), wxDefaultPosition, wxDefaultSize, 0 );
	branchLabel->Wrap( -1 );
	infoHSizer->Add( branchLabel, 0, wxALL, 5 );
	
	
	infoSizer->Add( infoHSizer, 1, wxEXPAND, 5 );
	
	
	baseSizer->Add( infoSizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* commentSizer;
	commentSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Comment") ), wxVERTICAL );
	
	commentText = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	commentSizer->Add( commentText, 1, wxALL|wxEXPAND, 5 );
	
	
	baseSizer->Add( commentSizer, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* changesSizer;
	changesSizer = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Changes Made") ), wxVERTICAL );
	
	changesTree = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	changesSizer->Add( changesTree, 1, wxALL|wxEXPAND, 5 );
	
	
	baseSizer->Add( changesSizer, 1, wxEXPAND, 5 );
	
	bottomButtonSizer = new wxStdDialogButtonSizer();
	bottomButtonSizerOK = new wxButton( this, wxID_OK );
	bottomButtonSizer->AddButton( bottomButtonSizerOK );
	bottomButtonSizerCancel = new wxButton( this, wxID_CANCEL );
	bottomButtonSizer->AddButton( bottomButtonSizerCancel );
	bottomButtonSizer->Realize();
	
	baseSizer->Add( bottomButtonSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( baseSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
}

GitCommitDialogProto::~GitCommitDialogProto()
{
}
