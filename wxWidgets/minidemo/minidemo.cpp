#include<iostream>
#include<wx/wx.h>

class TurtorialApp : public wxApp {
    public:
        bool OnInit() override;
};
//创建应用程序

class MainFrame : public wxFrame {
    public:
        MainFrame();
}; // 创建主窗口

wxIMPLEMENT_APP(TurtorialApp); // 实例化窗口

bool TurtorialApp::OnInit() {
    MainFrame* frame = new MainFrame();
    frame->Show(); //展示主窗口
    return true;
} // 初始化应用程序

MainFrame::MainFrame(): wxFrame(nullptr, wxID_ANY, "EDA Demo", wxDefaultPosition, wxDefaultSize)
{
    SetClientSize(800, 600);
    auto* panel = new wxPanel(this, wxID_ANY); //设置页面容器
    auto* text = new wxStaticText(panel, wxID_ANY, "Hello EDA!", wxPoint(10, 10)); //设置文本

    wxFont font = text->GetFont(); //字体类
    font.SetPointSize(24);
    font.SetWeight(wxFONTWEIGHT_BOLD);
    text->SetFont(font); //设置字体

    auto* sizer = new wxBoxSizer(wxVERTICAL); //设置布局,垂直
    sizer->AddStretchSpacer(); //添加弹性空间
    sizer->Add(text, 0, wxALIGN_CENTER); //添加文本
    sizer->AddStretchSpacer(); //添加弹性空间
    panel->SetSizer(sizer); //设置布局
}
