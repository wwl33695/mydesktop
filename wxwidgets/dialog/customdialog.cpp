#include <wx/fontdlg.h>
#include "customdialog.h"

CustomDialog::CustomDialog(const wxString & title)
            : wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(350, 230))
{
    wxPanel * panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer * vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer * hbox = new wxBoxSizer(wxHORIZONTAL);

    wxStaticBox   * st  = new wxStaticBox(panel,   wxID_ANY, _T("Colors"), wxPoint(5, 5), wxSize(340, 150));
    wxRadioButton * rb1 = new wxRadioButton(panel, wxID_ANY, _T("16 Colors"), wxPoint(15, 55));
    wxRadioButton * rb2 = new wxRadioButton(panel, wxID_ANY, _T("2 Colors"), wxPoint(15, 80));
    wxRadioButton * rb3 = new wxRadioButton(panel, wxID_ANY, _T("Custom"), wxPoint(15, 105));
    wxTextCtrl    * tc  = new wxTextCtrl(panel, wxID_ANY, _T(""), wxPoint(95, 105));

    wxButton * okButton    = new wxButton(this, wxID_ANY, _T("OK"), wxDefaultPosition, wxSize(70, 30));
    wxButton * closeButton = new wxButton(this, wxID_ANY, _T("Close"), wxDefaultPosition, wxSize(70, 30));
    wxButton * fontButton = new wxButton(this, wxID_ANY, _T("openfont"), wxDefaultPosition, wxSize(70, 30));
    wxButton * fileButton = new wxButton(this, wxID_ANY, _T("openfile"), wxDefaultPosition, wxSize(70, 30));
    
    Connect(okButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CustomDialog::ShowMessage1));
    Connect(closeButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CustomDialog::ShowMessage2));
    Connect(fontButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CustomDialog::ShowFontDialog));
    Connect(fileButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CustomDialog::ShowFileDialog));

    hbox->Add(okButton, 1);
    hbox->Add(closeButton, 1, wxLEFT, 5);
    hbox->Add(fontButton, 1, wxLEFT, 5);
    hbox->Add(fileButton, 1, wxLEFT, 5);

    vbox->Add(panel, 1);
    vbox->Add(hbox, 0, wxALIGN_CENTRE | wxTOP | wxBOTTOM, 10);

    SetSizer(vbox);

    Centre();
    ShowModal();

    Destroy();
}

void CustomDialog::ShowMessage1(wxCommandEvent & event)
{
    wxMessageDialog * dial = new wxMessageDialog(NULL, _T("ok buffon"), _T("Info"), wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
    dial->ShowModal();
}
void CustomDialog::ShowMessage2(wxCommandEvent & event)
{
    wxMessageDialog * dial = new wxMessageDialog(NULL, _T("cancel buffon"), _T("Exclamation"), wxOK | wxICON_EXCLAMATION);
    dial->ShowModal();
}
void CustomDialog::ShowFontDialog(wxCommandEvent & event)
{
    wxFontDialog * fontDialog = new wxFontDialog(this);

    if(fontDialog->ShowModal() == wxID_OK)
    {
//        st->SetFont(fontDialog->GetFontData().GetChosenFont());
    }
}
void CustomDialog::ShowFileDialog(wxCommandEvent & event)
{
    wxFileDialog * openFileDialog = new wxFileDialog(this);

    if(openFileDialog->ShowModal() == wxID_OK)
    {
//        wxString fileName = openFileDialog->GetPath();
//        tc->LoadFile(fileName);
    }
}