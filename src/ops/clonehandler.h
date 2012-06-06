#ifndef CLONEHANDLER_H
#define CLONEHANDLER_H

#include <wx/thread.h>
#include <wx/string.h>
#include <wx/richtext/richtextctrl.h>
#include <git2.h>

class CloneHandler : public wxThread {
public:
    CloneHandler(wxString &local, wxString &remote, wxRichTextCtrl* log);
    virtual ~CloneHandler();

protected:
    void* Entry();

    git_repository *m_repo;
    git_remote *m_remote;

    wxString m_localPath;
    wxString m_remotePath;
    wxRichTextCtrl* m_log;
};

#endif // CLONEHANDLER_H
