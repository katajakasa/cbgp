#ifndef GITCOMMITDIALOG_H
#define GITCOMMITDIALOG_H

#include "gui/proto.h"

class GitCommitDialog : public GitCommitDialogProto {
public:
    GitCommitDialog(wxWindow *parent);
    virtual ~GitCommitDialog();

protected:

};

#endif // GITCOMMITDIALOG_H
