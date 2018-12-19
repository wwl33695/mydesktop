#include <wx/wx.h>

class CustomDialog : public wxDialog
{
public:
    CustomDialog(const wxString & title);

    void ShowMessage1(wxCommandEvent & event);
    void ShowMessage2(wxCommandEvent & event);
};
