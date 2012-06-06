#include "gitimportdialog.h"
#include <wx/dirdlg.h>
#include <logmanager.h>

GitImportDialog::GitImportDialog(wxWindow* parent) : GitImportDialogProto(parent) {
    m_handler = 0;
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
    if(event.GetPage() == m_pages.Item(1)) {
        // Start clone handler
        wxString localPath = localDir->GetValue();
        wxString remotePath = remoteDir->GetValue();
        m_handler = new CloneHandler(localPath, remotePath, importLog);
        m_handler->Run();
    }
}

void GitImportDialog::OnPageChanging(wxWizardEvent& event) {
    if(event.GetPage() == m_pages.Item(0) && event.GetDirection()) {
        // Check that everything is valid !


    }
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

