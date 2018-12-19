#include <wx/wx.h>

// 定义主窗口类
class MyFrame : public wxFrame
{
public:    // 主窗口类的构造函数    
    MyFrame(const wxString& title);    // 事件处理函数    
    void OnQuit(wxCommandEvent& event); 
    void OnAbout(wxCommandEvent& event);
    private:    // 声明事件表    
    DECLARE_EVENT_TABLE()

    void OnOpenFile(wxCommandEvent & event);

    wxTextCtrl * tc;

	void OnOpenFont(wxCommandEvent & WXUNUSED(event));

    enum{ID_FONTDIALOG};
};
