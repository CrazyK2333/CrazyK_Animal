// goBang.cpp : 定义应用程序的入口点。
//


#include"MainWindow.h"



 void DrawAPointColor(int inX,int inY,brushcolor color)
{
    SingleBoardBlocksinfo* OrderPoint;

    
    OrderPoint = Board::GetGlobalBoard().SearchBlockAtIndexXY(inX, inY);
   if(OrderPoint!=nullptr)
   {
       OrderPoint->blockcolor = color;

   }

   

    
    
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
 

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GOBANG, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    InitialGame();
    
    
    

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GOBANG));
    
    bool bGotMsg;
    MSG msg;
    msg.message = WM_NULL;
    PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);
    t_pre = GetTickCount64();
    while (WM_QUIT != msg.message)
    {
        t_now = timeGetTime();

        // Use PeekMessage() so we can use idle time to render the scene. 
        bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0);
        if (bGotMsg)
        {
            // Translate and dispatch the message
            if (MainWindow == NULL ||
                0 == TranslateAccelerator(MainWindow, NULL, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            t_now = GetTickCount64();
            if (t_now - t_pre> 0)
            {
                float IntervalTime = (float)(t_now - t_pre) / 1000.f;
                /*if(IntervalTime>=3.0)
                {
                    SayC("ERROR");
                
                }DeBugOutputW(L"RUNNING");*/
                PainAction();
                UpDateGame(IntervalTime);
                t_pre = t_now;
            }
        }
    }
    return (int)msg.wParam;

    
}
//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GOBANG));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GOBANG);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中
   MainWindow = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, WND_WIDTH,WND_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!MainWindow)
   {
      return FALSE;
   }

   ShowWindow(MainWindow, nCmdShow);
   UpdateWindow(MainWindow);
   
   



   return TRUE;
}
//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            int wmEvent = HIWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case IDC_BUTTON_STARTGAME:
                
                G_info.GameState = GMD_STARTED;
                
                Say(L"game Started")
                break;
            case IDC_BUTTON_GIVEUP:
                
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
          
          
        }
        break;
    case WM_PAINT:
        {
            /*DeBugOutputW(L"OK");*/
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        EndGame();
        break;
    case WM_CREATE:
        {
        StartGameButton = CreateWindow(TEXT("button"),//必须为：button    
                           TEXT("StartGame"),//按钮上显示的字符    
                          WS_CHILD | WS_VISIBLE,
                       BOARD_RIGHTLINE, 
			BUTTONS_Y_LINE_BOTTOM, 
			100, 
			50,  
                          
			hWnd, 
			(HMENU)IDC_BUTTON_STARTGAME,  
                     
			((LPCREATESTRUCT)lParam)->hInstance, 
			NULL);
        GiveUpButton= CreateWindow(TEXT("button"),//必须为：button    
            TEXT("GiveUp"),//按钮上显示的字符    
            WS_CHILD | WS_VISIBLE,
            BOARD_RIGHTLINE+200, 
			BUTTONS_Y_LINE_BOTTOM, 
			100, 
			50,
            hWnd, 
			(HMENU)IDC_BUTTON_GIVEUP,
            ((LPCREATESTRUCT)lParam)->hInstance, 
			NULL);
        
        TextCom = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), 
			TEXT(""),
            WS_VSCROLL | WS_VISIBLE | WS_CHILD | ES_AUTOVSCROLL | ES_MULTILINE| ES_READONLY,
            BOARD_RIGHTLINE,
			0, WND_WIDTH-BOARD_RIGHTLINE, 200, hWnd, (HMENU)TEXT_COM, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
        CreateWindow(TEXT("static"), TEXT("Computer Message↑↑↑↑↑"),
            WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
            BOARD_RIGHTLINE, 200, 240 , 100,
            hWnd , (HMENU)9999 , ((LPCREATESTRUCT)lParam)->hInstance, NULL
        );

        CreateWindow(TEXT("static"), 
			TEXT("UserMessage↓↓↓↓"),
            WS_CHILD | WS_VISIBLE | SS_CENTERIMAGE | SS_CENTER,
            BOARD_RIGHTLINE, 
			500, 
			240, 
			100,
            hWnd, 
			(HMENU)10000, 
			((LPCREATESTRUCT)lParam)->hInstance, 
			NULL
        );
      

        TextUser= CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""),
            WS_VSCROLL | WS_VISIBLE | WS_CHILD | ES_AUTOVSCROLL | ES_MULTILINE | ES_READONLY,
            BOARD_RIGHTLINE, 600, 
			WND_WIDTH - BOARD_RIGHTLINE, 
			200, 
			hWnd, 
			(HMENU)TEXT_USER,
			((LPCREATESTRUCT)lParam)->hInstance, 
			NULL);

        G_info.GameState = GMD_INITED;
       

        }
        break;
    case WM_LBUTTONDOWN:
    {
        long x = LOWORD(lParam);
        long y = HIWORD(lParam);
        
        int i_y;
        int i_x;
        
        LifeGameLib::ActualPointToIndexPoint(x, y, i_x, i_y);
       
        DrawAPointColor(i_x, i_y, brushcolor::LightPink);
       

       
          
    }
        break;
    case WM_RBUTTONDOWN:
    {
        long x = LOWORD(lParam);
        long y = HIWORD(lParam);

        int i_y;
        int i_x;

        LifeGameLib::ActualPointToIndexPoint(x, y, i_x, i_y);

        
        DrawAPointColor(i_x, i_y, brushcolor::Black);
    }
        break;
    default:

        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        
        break;
    }
    return (INT_PTR)FALSE;
}
