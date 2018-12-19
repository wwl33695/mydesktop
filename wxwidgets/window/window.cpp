#include <wx/fontdlg.h>
#include "window.h"

// MyFrame类的事件表
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT,  MyFrame::OnQuit)
END_EVENT_TABLE()
void MyFrame::OnAbout(wxCommandEvent& event)
{    
    wxString msg;   
    msg.Printf(wxT("Hello and welcome to %s"),  wxVERSION_STRING);  
      wxMessageBox(msg, wxT("About Minimal"),  wxOK | wxICON_INFORMATION, this);

}
void MyFrame::OnQuit(wxCommandEvent& event)
{
    // 释放主窗口
    Close();
}

//#include "mondrian.xpm"
MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{  

    // 设置窗口图标 
    //   SetIcon(wxIcon(mondrian_xpm)); 

    // 创建菜单条   
    wxMenu *fileMenu = new wxMenu; 
    fileMenu->Append(wxID_OPEN, _T("&Open"));
    fileMenu->Append(ID_FONTDIALOG, _T("&Change Font"));
    fileMenu->Append(wxID_EXIT, wxT("E&xit/tAlt-X"),  wxT("Quit this program")); 
    Connect(wxID_OPEN, wxEVT_COMMAND_MENU_SELECTED,
            wxCommandEventHandler(MyFrame::OnOpenFile));
    Connect(ID_FONTDIALOG, wxEVT_COMMAND_MENU_SELECTED,
            wxCommandEventHandler(MyFrame::OnOpenFont));

    // 添加“关于”菜单项 
    wxMenu *helpMenu = new wxMenu; 
    helpMenu->Append(wxID_ABOUT, wxT("&About.../tF1"),  wxT("Show about dialog"));    

    // 将菜单项添加到菜单条中  
    wxMenuBar *menuBar = new wxMenuBar();  
    menuBar->Append(fileMenu, wxT("&File")); 
    menuBar->Append(helpMenu, wxT("&Help")); 

    // ...然后将菜单条放置在主窗口上
    SetMenuBar(menuBar);
    
    tc = new wxTextCtrl(this, wxID_ANY, _T(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
    
    // 创建一个状态条来让一切更有趣些。  
    CreateStatusBar(2);  
    SetStatusText(wxT("Welcome to wxWidgets!"));
}

void MyFrame::OnOpenFile(wxCommandEvent & event)
{
    wxFileDialog * openFileDialog = new wxFileDialog(this);

    if(openFileDialog->ShowModal() == wxID_OK)
    {
        wxString fileName = openFileDialog->GetPath();
        tc->LoadFile(fileName);
    }
}
void MyFrame::OnOpenFont(wxCommandEvent & WXUNUSED(event))
{
    wxFontDialog * fontDialog = new wxFontDialog(this);

    if(fontDialog->ShowModal() == wxID_OK)
    {
        tc->SetFont(fontDialog->GetFontData().GetChosenFont());
    }
}