#include <sdk.h>
#include <configurationpanel.h>
#include <logmanager.h>
#include <git2.h>
#include "plugin.h"
#include "gui/gitimportdialog.h"
#include "gui/gitcommitdialog.h"

namespace {
    PluginRegistrant<GitPlugin> reg(_T("Codeblocks_Git_Plugin"));
}

// IDs
int idGitImportEntry = wxNewId();
int idGitCommitEntry = wxNewId();
int idGitPushEntry = wxNewId();
int idGitPullEntry = wxNewId();
int idGitInitEntry = wxNewId();

// Event table
BEGIN_EVENT_TABLE(GitPlugin, cbPlugin)
    EVT_MENU(idGitImportEntry, GitPlugin::OnMenuImport)
    EVT_MENU(idGitCommitEntry, GitPlugin::OnMenuCommit)
END_EVENT_TABLE()

// Constructor, load resources
GitPlugin::GitPlugin() {
    if(!Manager::LoadResource(_T("Codeblocks_Git_Plugin.zip"))) {
        NotifyMissingFile(_T("Codeblocks_Git_Plugin.zip"));
    }
}

GitPlugin::~GitPlugin() {
}

void GitPlugin::OnAttach() {
    git_threads_init();
}

void GitPlugin::OnRelease(bool appShutDown) {
    git_threads_shutdown();
}

int GitPlugin::Configure() {
    if(!IsAttached()) return -1;

    cbConfigurationDialog dlg(Manager::Get()->GetAppWindow(), wxID_ANY, _("GIT Plugin Configuration"));
    cbConfigurationPanel* panel = GetConfigurationPanel(&dlg);
    if(panel) {
        dlg.AttachConfigurationPanel(panel);
        PlaceWindow(&dlg);
        return dlg.ShowModal() == wxID_OK ? 0 : -1;
    }
    return -1;
}

void GitPlugin::BuildMenu(wxMenuBar* menuBar) {
    if(!IsAttached()) return;

    // Find import menu
    wxMenu* fileMenu = menuBar->GetMenu(0);
    int importMenuPos = fileMenu->FindItem(_("Import project"));
    if(importMenuPos == wxNOT_FOUND) {
        return;
    }
    wxMenu* importMenu = fileMenu->FindItem(importMenuPos, NULL)->GetSubMenu();

    // Add import item for Git
    wxMenuItem* gitItem = new wxMenuItem(importMenu, idGitImportEntry, _("Git Repository ..."));
    wxMenuItem* spacer = new wxMenuItem(importMenu, wxID_SEPARATOR, _(""), _(""), wxITEM_SEPARATOR);
    importMenu->Append(spacer);
    importMenu->Append(gitItem);
}

void GitPlugin::OnMenuImport(wxCommandEvent& event) {
    GitImportDialog dialog(Manager::Get()->GetAppWindow());
    if(dialog.run()) {

    }
}

void GitPlugin::OnMenuCommit(wxCommandEvent& event) {
    GitCommitDialog dialog(Manager::Get()->GetAppWindow());
    if(dialog.ShowModal() == wxID_OK) {

    }
}

void GitPlugin::buildFileMenu(wxMenu* menu) {
    // TODO: File menu
}

void GitPlugin::buildFolderMenu(wxMenu* menu) {
    // TODO: Folder menu
}

void GitPlugin::buildProjectMenu(wxMenu* menu) {
    wxMenu* gitMenu = new wxMenu();
    wxMenuItem* initItem = new wxMenuItem(gitMenu, idGitInitEntry, _("Init"));
    wxMenuItem* commitItem = new wxMenuItem(gitMenu, idGitCommitEntry, _("Commit"));
    wxMenuItem* pushItem = new wxMenuItem(gitMenu, idGitPushEntry, _("Push"));
    wxMenuItem* pullItem = new wxMenuItem(gitMenu, idGitPullEntry, _("Pull"));

    gitMenu->Append(initItem);
    gitMenu->Append(commitItem);
    gitMenu->Append(pushItem);
    gitMenu->Append(pullItem);

    menu->AppendSubMenu(gitMenu, _("Git"));
}

void GitPlugin::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data) {
    if(!IsAttached()) return;
    if(type != mtProjectManager) return;

    switch(data->GetKind()) {
        case FileTreeData::ftdkProject: buildProjectMenu(menu); break;
        case FileTreeData::ftdkFile:    buildFileMenu(menu);    break;
        case FileTreeData::ftdkFolder:  buildFolderMenu(menu);  break;
    }
}
