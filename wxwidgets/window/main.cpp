#include "main.h"
#include "window.h"

IMPLEMENT_APP(MyApp)

// 初始化程序

bool MyApp::OnInit()
{
    // 创建主窗口
    MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"));   

    // 显示主窗口
    frame->Show(true);  

    // 开始事件处理循环
    return true;
}