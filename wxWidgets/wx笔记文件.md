# 整体结构
1. 应用层
    对象:wxapp
2. 顶层窗口层
    对象:wxFrame, wxDialog
3. 容器层
    对象:wxPanel, wxNotebook, wxSplitterWindow
4. 控件层
    对象: wxButton, wxTestCtrl, wxDataViewCtrl

    ### minidemo
    wxapp 应用层
    - 管理这个程序启动和初始化,全局资源和事件循环
    - **使用**: 通常是派生一个子类, 并且调用 OnInit();
        `OnInit()`: 应用初始化入口, 返回true代表开始循环
        `wxDECLARE_APP(子类名)`: 声明一个接口`wxGetApp()`,可以访问应用类的全局数据

    wxFrame 顶层窗口层
    - 承载主窗口的菜单,工具栏和状态栏, 主要内容(*注意不要把业务逻辑都写到Frame*)

        `wxIMPLEMENT_APP`: 宏, 实现wxApp的入口,不需要额外手写`main()`

        `wxID_ANY` : 标准id,让菜单/按钮/事件 绑定使用稳定的标准命令编号

        `wxDeFaultSize`: 默认常量,默认位置与尺寸, 交给布局系统自动决定
        `wxDeFaultPosition` : 默认位置, 交给布局系统决定

        `wxSize`: 二维结构表示宽与高

    wxPanel 容器层
    - 用于承载控件,由sizer布局
        `SetSizer()`: 用于设置布局器

    wxFont 字体类, 用于表示字体的大小,字体族,粗细
        `wxFONTWEIGHT_BOLD` : 常量表示粗细, 用`wxFont::SetWeight()`设置粗细

    wxStaticText 静态文本类, 显示说明文字

    wxBoxSizer 类/线性sizer 用于水平或者垂直方向布件
    - `Add()`: 添加控件
        `wxVERTICAL`: 垂直布件常量
        `wxALIGN_CENTER`: 对齐???
        `wxALL` : 边距


    ### demo1(分文件编写)
    1. c++补充
    - `explicit`: 关键字,用于禁止隐式转换

    2.结构
    -src
        -App.cpp
        -App.h
        -MainFrame.cpp
        -MainFrame.h
    
    Frame:
    `wxWindow`: 类,所有窗口对象的基类,提供位置尺寸等信息,很多空间和窗口的基类
    `wxCommandEvent`: 事件类,表示按钮,菜单,文本框等命令型操作
    `wxMenu`: 类&菜单, 保存菜单项和子菜单
        - `Append`:向菜单追加项目
    `wxMenuBar`:类和菜单栏,把多个菜单安装到FRAME
        先利用Append方法添加子菜单/菜单, 最后利用`SetMenuBar()`把添加的成员设置好(实际上,setmenubar是针对frame的函数,是把菜单栏安装到frame)

    `wxID_ANY`: 标准ID, 让菜单,按钮,事件绑定使用标准命令
        - `wxID_EXIT`
        - `wxID_ABOUT`

    `wxPanel()`: 类&容器窗口, 用来承载一组控件,与Sizer布局接受子控件事件,主窗口的内容先放进Panel. 填写的指针是当前的Frame
        `wxStaticText`:类&静态文本, 显示文字但是不修改
        `wxButton`:类&按钮控件,触发一次事件,通常绑定
        **方法:**
        - `SetSizer()`:根据布局器设置控件布局
        - `Bind()`:用来绑定事件和处理函数,通常绑定到档期那
        
        Frame
            - `wxEVT_MENU`:监听菜单事件
        ```cpp
            Bind(
            事件类型,
            处理函数,
            处理函数所属对象,
            控件或菜单项 ID
            );
        ```

    `wxMessageBox()`: 函数&显示一个消息框, 四个参数(消息内容,消息框标题,处理结果/按钮样式,父窗口(mainframe))
    - wxOK                → 显示“确定”按钮,wxICON_INFORMATION  → 显示信息图标

    `wxBoxSizer()`: 类&线性Sizer, 按照水平/竖直方向布局
    - 填写的是布局方向
    - `AddStretchSpacer()`:添加可伸缩的空白
    - `Add()方法`:把一个控件、另一个 Sizer 或空白区域加入当前 Sizer，由当前 Sizer 决定它的位置和大小
        - flag表示对齐方式: `wxALIGN_CENTER`就是居中对齐

    ```cpp
    sizer->Add(
    item,        // 控件、Sizer 或空白项
    proportion,  // 随窗口缩放的伸缩比例
    flag,        // 对齐、扩展、边距等规则
    border       // 边距大小
    );
    ```
    
   - **方法**:在Frame下的方法
        `CreateStutasBar()`:在FRAME底部创建状态栏,里面可以填写参数表示几个字段
        `SetStatusText()`:设置字段的内容

    App:
    - `wxIMPLEMENT_APP(App);`
        创建App类,调用`OnInit()`函数,若返回值位ture,进入时间主循环
    - `OnInit()`:初始化app类,返回ture则代表初始化成功可以进入主循环
    - 方法:
        - `SetAppName()`:设置应用名字,为以后要调用用户配置时使用,不写也不影响使用
        - `SetVendorName()`:设置厂商/开发者名字,为以后要调用用户配置时使用,不写也不影响使用


    ### 1. 事件处理
    让特定的菜单和按钮出发特定的行为和事件