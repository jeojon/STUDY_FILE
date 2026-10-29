#pragma once
#include<iostream>
#include<wx/wx.h>

class App : public wxApp
{
    public:
        bool OnInit() override;
};

wxDECLARE_APP(App);