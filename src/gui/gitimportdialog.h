#ifndef GITIMPORTDIALOG_H
#define GITIMPORTDIALOG_H

#include "gui/proto.h"
#include "ops/clonehandler.h"

class GitImportDialog : public GitImportDialogProto {
public:
    GitImportDialog(wxWindow* parent);
    virtual ~GitImportDialog();
    bool run();

protected:
    bool m_localok;
    bool m_remoteok;
    bool m_clonedone;
    CloneHandler *m_handler;

    void setButtons();
    void setColors();
    void setControlEnable(int id, bool state);

    void OnPageChanged(wxWizardEvent& event);
    void OnLocalDirClick(wxCommandEvent& event);
    void OnRemoteDirClick(wxCommandEvent& event);
	void OnLocalDirectoryChange(wxCommandEvent& event);
	void OnRemoteDirectoryChange(wxCommandEvent& event);
};

#endif // GITIMPORTDIALOG_H
