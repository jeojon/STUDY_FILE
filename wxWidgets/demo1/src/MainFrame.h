#pragma once
#include<wx/wx.h>

class MainFrame : public wxFrame
{
    public:
        explicit MainFrame(wxWindow* parent = nullptr);

    private:
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);

};