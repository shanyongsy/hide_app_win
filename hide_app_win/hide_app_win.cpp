// hide_app_win.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <afxwin.h>
#include <iostream>
#include <sstream>


// 定义函数来发送消息给其他窗口
BOOL ShowOrHideWindow(HWND hWnd, BOOL bShow) {
    if (bShow)
        return ShowWindow(hWnd, SW_SHOW);
    else
        return ShowWindow(hWnd, SW_HIDE);
}

void Pause()
{
    std::wcout << L"Press Enter to continue..." << std::endl;
    getchar(); // 等待用户按下回车键
}


int main()
{
    std::cout << "Hello World!\n";

    // 查找的窗口句柄
    const wchar_t* appName = L"FSOnline Class";
    HWND hWnd = FindWindow(appName, NULL);

    if (hWnd == NULL) {
        // MessageBox(NULL, L"无法找到指定窗口", L"错误", MB_OK | MB_ICONERROR);
        std::wcout << L"Unable to find the specified window: " << appName << std::endl;

        Pause();
        return 1;
    }

    // 隐藏窗口
    BOOL bVisible = IsWindowVisible(hWnd);
    int nRes = ShowOrHideWindow(hWnd, !bVisible);

    if (bVisible && nRes == 0 || !bVisible && nRes != 0) {
        DWORD err = GetLastError();

        std::wostringstream strInfo;
        if (bVisible)
        {
            // strInfo << L"无法隐藏指定窗口" << L",错误号为 " << err;
            std::wcout << L"Unable to hide specified window: " << appName << ", Err=" << err << std::endl;
        }
        else
        {
            // strInfo << L"无法隐藏指定窗口" << L",错误号为 " << err;
            std::wcout << L"Unable to display the specified window: " << appName << ", Err=" << err << std::endl;
        }

        // MessageBox(NULL, strInfo.str().c_str(), L"错误", MB_OK | MB_ICONERROR);
        Pause();
        return 1;
    }

    std::wcout << L"success" << std::endl;
    // Pause();
    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
