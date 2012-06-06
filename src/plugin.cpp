#include <sdk.h>
#include <configurationpanel.h>
#include <logmanager.h>
#include <git2.h>
#include "plugin.h"
#include "gui/gitimportdialog.h"

namespace {
    PluginRegistrant<GitPlugin> reg(_T("Codeblocks_Git_Plugin"));
}

// IDs
int idGitImportEntry = wxNewId();

// Event table
BEGIN_EVENT_TABLE(GitPlugin, cbPlugin)
    EVT_MENU(idGitImportEntry, GitPlugin::OnMenuImport)
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

void GitPlugin::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data) {
    //Some library module is ready to display a pop-up menu.
    //Check the parameter \"type\" and see which module it is
    //and append any items you need in the menu...
    //TIP: for consistency, add a separator as the first item...
    NotImplemented(_T("Codeblocks_Git_Plugin::BuildModuleMenu()"));
}
