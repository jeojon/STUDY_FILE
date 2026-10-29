#include "App.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(App);//调用初始化函数并且进入主循环
bool App::OnInit()
{
    SetAppName("App"); //
    SetVendorName("learningTeam");

    auto* frame = new MainFrame(); //创建主窗口
    frame->Show(true); //显示主窗口
    return true; //返回ture表示初始化成功,进入主循环

}

