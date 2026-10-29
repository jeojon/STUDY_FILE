#include "MainFrame.h"


MainFrame::MainFrame(wxWindow* parent)
: wxFrame(parent,wxID_ANY, "the first app", wxDefaultPosition, wxSize(760,520))
{
    auto* menuFile = new wxMenu();
    menuFile->Append(wxID_EXIT, "Exit(Q)");
// 创建一个菜单类,并且绑定一个ID,显示一段文字

    auto*  menuHelp = new wxMenu();
    menuHelp->Append(wxID_ABOUT, "About(A)");
//第二个菜单

    auto* menuBar = new wxMenuBar();
    menuBar->Append(menuFile, "File(F)");
    menuBar->Append(menuHelp, "Help(H)");
    SetMenuBar(menuBar); //把菜单栏装载到Frame窗口
//设置菜单栏,并且添加之前设置好的小菜单

CreateStatusBar();
SetStatusText("Ready!");

//设置panel承载一些控件内容
auto* panel = new wxPanel(this);
//设置 panel下的控件
auto* sizer = new wxBoxSizer(wxVERTICAL);
auto* title = new wxStaticText(panel, wxID_ANY, "hello, world");
auto* button = new wxButton(panel, wxID_ANY, "click  me!!!");

//利用布局器布置控件的位置
sizer->AddStretchSpacer();
sizer->Add(title, 0, wxALIGN_CENTER | wxALL, 12);
sizer->Add(button, 0, wxALIGN_CENTER | wxALL, 12);
sizer->AddStretchSpacer();
panel->SetSizer(sizer);

Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
//绑定事件与对应的处理函数,以及绑定到父窗口
button->Bind(wxEVT_BUTTON, &MainFrame::OnHello, this);

Centre();

}

void MainFrame::OnHello(wxCommandEvent& event)
{
    wxMessageBox("located in MainFrame successfully!", "something", wxOK | wxICON_INFORMATION, this);
}

void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("there's something might help you~", "about", wxOK | wxICON_INFORMATION, this);

}

void MainFrame::OnExit(wxCommandEvent&)
{
    Close(true);
}