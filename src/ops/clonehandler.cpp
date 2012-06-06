#include "ops/clonehandler.h"

CloneHandler::CloneHandler(wxString &local, wxString &remote, wxRichTextCtrl* log)
    : m_localPath(local), m_remotePath(remote), m_log(log), wxThread(wxTHREAD_JOINABLE) {
    m_repo = 0;
    m_remote = 0;
    Create();
}

CloneHandler::~CloneHandler() {
    if(m_repo) {
        git_repository_free(m_repo);
    }
    if(m_remote) {
        git_remote_free(m_remote);
    }
}

void* CloneHandler::Entry() {
    m_log->AppendText(_("Cloning ...\n"));

    // Init repo
    if(git_repository_init(&m_repo, m_localPath.mb_str(), false)) {
        m_log->AppendText(_("Error while initializing local repository!\n"));
        return 0;
    }
    m_log->AppendText(_("Local repository created.\n"));

    // Set remote
    if(git_remote_load(&m_remote, m_repo, m_remotePath.mb_str())) {
        if(git_remote_new(&m_remote, m_repo, 0, m_remotePath.mb_str(), 0)) {
            m_log->AppendText(_("Error while loading remote information!\n"));
            return 0;
        }
    }

    // Connect to remote
    if (git_remote_connect(m_remote, GIT_DIR_FETCH) < 0) {
        m_log->AppendText(_("Unable to connect to remote repository!\n"));
        return 0;
    }
    m_log->AppendText(_("Connected to repository.\n"));

    // Download
	git_off_t bytes = 0;
    git_indexer_stats stats;
    memset(&stats, 0, sizeof(stats));
    if(git_remote_download(m_remote, &bytes, &stats) < 0) {
        m_log->AppendText(_("Unable to download!\n"));
        git_remote_disconnect(m_remote);
        m_log->AppendText(_("Disconnected.\n"));
        return 0;
    }
    m_log->AppendText(_("Data downloaded.\n"));

    // Disconnect
	git_remote_disconnect(m_remote);
	m_log->AppendText(_("Disconnected.\n"));



    return 0;
}
