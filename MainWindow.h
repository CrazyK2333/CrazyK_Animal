//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ 生成的包含文件。
// 使用者 goBang.rc
#pragma once


#ifndef IDC_STATIC
#define IDC_STATIC				-1
#endif
//#include"framework.h"
#include"Board.h"
#include"Actor.h"
#include"Cat.h"
#include"Human.h"
#include"Pig.h"
#include"BasicDefines.h"



#define MAX_LOADSTRING 100
// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
std::list<std::wstring> Text_ComList;
std::list<std::wstring> Text_UserList;
HWND StartGameButton;
HWND GiveUpButton;
HWND TextCom;
int WinBlockNum = 5;
int MaxLineNum = 12;
HWND TextUser;
HPEN oldpen;  //画笔
HPEN usepen; //兼容画笔
HBITMAP oldmap; //位图
HBITMAP usemap;  //兼容位图
HDC memDc; //兼容DC
HDC mydc;
HWND MainWindow;
ULONGLONG t_now = 0;
ULONGLONG t_pre = 0;


//Only useful for index type point





//mostly for index points



//information of each single blockinfo

//Record All blocks information

    
    
//Board BoardGrids(NUMBLOCK, NUMBLOCK);

//std::vector<GridActor*> ActorWareHouse;
 
    
struct GameInfo
{
    int GameState;
    int G_round;
    int x;
    int y;
    int Winner;
    int pipeIndex;
    GameInfo()
    {
        GameState = 0;
        G_round = 1;
        x = 0;
        y = 0;
        Winner = 0;
        pipeIndex=0;
    }
    std::string TranslateInfoIntoString()
    {
        std::string tmpstr = "";
        char tmp[1024];
        sprintf_s(tmp, "%d;%d;%d;%d;%d;%d;", this->GameState, this->G_round, this->x, this->y,this->Winner,this->pipeIndex);
        tmpstr = tmp;
        tmpstr += "\n";
        return tmpstr;
    }
    void LoadStringToInfo(const std::string& inputstr)
    {
        std::string tmpstr = "";
        int index = 0;
        
        for (char per : inputstr)
        {

            if (per == ';')
            {
                index++;
                switch (index)
                {
                case 1:
                {
                    this->GameState = atoi(tmpstr.c_str());
                }
                break;
                case 2:
                {
                    this->G_round = atoi(tmpstr.c_str());
                }
                break;
                case 3:
                {
                    this->x = atoi(tmpstr.c_str());
                }
                break;
                case 4:
                {
                    this->y = atoi(tmpstr.c_str());
                }
                break;
                case 5:
                {
                    this->Winner = atoi(tmpstr.c_str());
                }
                break;
                case 6:
                    {
                        this->pipeIndex = atoi(tmpstr.c_str());
                    }
                    break;

                    
                default:
                {

                }
                    break;
                }
                tmpstr= "";


            }
            else
            {
                tmpstr += per;
            }

        }
    }
};

GameInfo G_info;
void AddTextToBox(int idc_num, std::list<std::wstring>& src, const std::wstring& add)
{
    auto tmp = GetDlgItem(MainWindow, idc_num);
    if (src.size() < 12)
    {
        src.push_back(add);
    }
    else
    {
        src.pop_front();
    }
    std::wstring tmpbuffer;
    for (auto p : src)
    {
        tmpbuffer.append(p);
    }
    SetWindowTextW(tmp, tmpbuffer.c_str());


}
void UpDateGame(float IntervalTime)
{
    for(GridActor* CurActor:GridActor::GetGlobalWareActorHouse()) 
    {
        CurActor->UpDate(IntervalTime);

    }
    for (GridActor* CurActor : GridActor::GetGlobalWareActorHouse())
    {
        CurActor->DrawActor();

    }
}
void InitialGame()
{
    
    //GridActor*ActorWareHouse[3]{ new Cat{ &BoardGrids,3,3,point{1,1} }, new Human{ &BoardGrids,5, 5,point{6,6} }, new Pig{ &BoardGrids,8,8,point{15,15} } };
    GridActor::GetGlobalWareActorHouse().push_back(new Cat{&Board::GetGlobalBoard(),3,3,point{10,1},"Cat",brushcolor::White});
    GridActor::GetGlobalWareActorHouse().push_back(new Human{ &Board::GetGlobalBoard(),5, 5,point{6,6},"Human",brushcolor::Blue});
    GridActor::GetGlobalWareActorHouse().push_back(new Pig{ &Board::GetGlobalBoard(),8,8,point{20,2},"Pig",brushcolor::Pink});
    
    
}
void EndGame()
{
    for(GridActor*CurActor: GridActor::GetGlobalWareActorHouse())
    {
        delete CurActor;
     
    }
    

}

void PainAction()
{
    mydc = GetDC(MainWindow);
    /*DeBugOutputW(L"GetDC =%d" ,GetDC);*/
    oldpen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
    LifeGameLib::Pinkbrush = CreateSolidBrush(COLORREF(0xff00ff));
    LifeGameLib::Whitebrush = CreateSolidBrush(COLORREF(0xffffff));
    LifeGameLib::Bluebrush = CreateSolidBrush(COLORREF(0xff0000));
    LifeGameLib::LightPinkbrush= CreateSolidBrush(COLORREF(0xc4b5ff));
    memDc = CreateCompatibleDC(mydc);
    oldmap = CreateCompatibleBitmap(mydc, BOARD_RIGHTLINE, BOARD_RIGHTLINE);
    usemap = (HBITMAP)SelectObject(memDc, oldmap);
    usepen = (HPEN)SelectObject(memDc, oldpen);



    //draw lines
    for (int i = 0; i <= NUMBLOCK; i++)
    {
        MoveToEx(memDc, 0, i * BLOCKLENGTH, nullptr);
        LineTo(memDc, BOARD_RIGHTLINE, i * BLOCKLENGTH);
        MoveToEx(memDc, i * BLOCKLENGTH, 0, nullptr);
        LineTo(memDc, i * BLOCKLENGTH, BOARD_RIGHTLINE);
    }
    //DrawBlocks
    for (int i = 0; i < NUMBLOCK * NUMBLOCK; i++)
    {
        Board::GetGlobalBoard().pB[i].DrawMySelfAsRectangle(memDc);
    }


    BitBlt(mydc, 0, 0, BOARD_RIGHTLINE, BOARD_RIGHTLINE, memDc, 0, 0, SRCCOPY);

    DeleteObject(oldpen);
    DeleteObject(oldmap);
    DeleteDC(memDc);
    ReleaseDC(MainWindow, mydc);
}



#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#endif
#endif
