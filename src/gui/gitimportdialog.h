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
    CloneHandler *m_handler;

    void OnPageChanged(wxWizardEvent& event);
    void OnPageChanging(wxWizardEvent& event);
    void OnLocalDirClick(wxCommandEvent& event);
    void OnRemoteDirClick(wxCommandEvent& event);
};

#endif // GITIMPORTDIALOG_H
