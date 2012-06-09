#include "gitimportdialog.h"
#include <logmanager.h>
#include <wx/dirdlg.h>
#include <wx/url.h>
#include <wx/dir.h>

GitImportDialog::GitImportDialog(wxWindow* parent) : GitImportDialogProto(parent) {
    m_handler = 0;
    m_localok = false;
    m_remoteok = false;
    m_clonedone = false;
    setButtons();
    setColors();
}

GitImportDialog::~GitImportDialog() {
    if(m_handler) {
        m_handler->Wait(); // Join thread
        delete m_handler;
    }
}

bool GitImportDialog::run() {
    return RunWizard(m_pages.Item(0));
}

void GitImportDialog::OnPageChanged(wxWizardEvent& event) {
    setButtons();
    setColors();
    if(event.GetPage() == m_pages.Item(1)) {
        // Start clone handler
        wxString localPath = localDir->GetValue();
        wxString remotePath = remoteDir->GetValue();
        m_handler = new CloneHandler(localPath, remotePath, importLog);
        m_handler->Run();
    }
}

void GitImportDialog::setControlEnable(int id, bool state) {
	wxWindow *win = wxWindow::FindWindowById(id);
	if(win) {
        win->Enable(state);
	}
}

void GitImportDialog::setButtons() {
    setControlEnable(wxID_FORWARD, false);
    setControlEnable(wxID_BACKWARD, false);
    if(GetCurrentPage() == m_pages.Item(0)) {
        if(m_localok && m_remoteok) {
            setControlEnable(wxID_FORWARD, true);
        } else {
            setControlEnable(wxID_FORWARD, false);
        }
    } else if(GetCurrentPage() == m_pages.Item(1)) {
        if(m_clonedone) {
            setControlEnable(wxID_FORWARD, true);
        }
    }
}

void GitImportDialog::setColors() {
    wxColour c_g(205,255,205);
    wxColour c_r(255,205,205);
    remoteDir->SetBackgroundColour((m_remoteok ? c_g : c_r));
    localDir->SetBackgroundColour((m_localok ? c_g : c_r));
    remoteDir->Refresh();
    localDir->Refresh();
}

void GitImportDialog::OnLocalDirectoryChange(wxCommandEvent& event) {
    m_localok = wxDir::Exists(localDir->GetValue());
    setButtons();
    setColors();
}

void GitImportDialog::OnRemoteDirectoryChange(wxCommandEvent& event) {
    wxString url = remoteDir->GetValue();
    if(url.SubString(0, 6).CompareTo(_("http://")) == 0
       || url.SubString(0, 7).CompareTo(_("https://")) == 0
       || url.SubString(0, 5).CompareTo(_("git://")) == 0
       || url.SubString(0,5).CompareTo(_("ssh://")) == 0) {
        m_remoteok = true;
    } else {
        m_remoteok = false;
    }
    setButtons();
    setColors();
}

void GitImportDialog::OnLocalDirClick(wxCommandEvent& event) {
    wxDirDialog dialog(this);
    if(dialog.ShowModal() == wxID_OK) {
        localDir->SetValue(dialog.GetPath());
    }
}

void GitImportDialog::OnRemoteDirClick(wxCommandEvent& event) {
    wxDirDialog dialog(this);
    if(dialog.ShowModal() == wxID_OK) {
        remoteDir->SetValue(dialog.GetPath());
    }
}

