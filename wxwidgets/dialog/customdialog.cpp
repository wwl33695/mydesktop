#include "customdialog.h"

CustomDialog::CustomDialog(const wxString & title)
            : wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 230))
{
    wxPanel * panel = new wxPanel(this, wxID_ANY);

    wxBoxSizer * vbox = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer * hbox = new wxBoxSizer(wxHORIZONTAL);

    wxStaticBox   * st  = new wxStaticBox(panel,   wxID_ANY, _T("Colors"), wxPoint(5, 5), wxSize(240, 150));
    wxRadioButton * rb1 = new wxRadioButton(panel, wxID_ANY, _T("16 Colors"), wxPoint(15, 55));
    wxRadioButton * rb2 = new wxRadioButton(panel, wxID_ANY, _T("2 Colors"), wxPoint(15, 80));
    wxRadioButton * rb3 = new wxRadioButton(panel, wxID_ANY, _T("Custom"), wxPoint(15, 105));
    wxTextCtrl    * tc  = new wxTextCtrl(panel, wxID_ANY, _T(""), wxPoint(95, 105));

    wxButton * okButton    = new wxButton(this, wxID_ANY, _T("OK"), wxDefaultPosition, wxSize(70, 30));
    wxButton * closeButton = new wxButton(this, wxID_ANY, _T("Close"), wxDefaultPosition, wxSize(70, 30));
    
    Connect(okButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CustomDialog::ShowMessage1));
    Connect(closeButton->GetId(), wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CustomDialog::ShowMessage2));

    hbox->Add(okButton, 1);
    hbox->Add(closeButton, 1, wxLEFT, 5);

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