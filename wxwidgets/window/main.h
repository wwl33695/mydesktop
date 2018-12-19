#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

// 有了这一行就可以使用 MyApp& wxGetApp()了
DECLARE_APP(MyApp)