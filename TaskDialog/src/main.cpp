#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <locale>
#include "resource.h"

HINSTANCE hInst;

void NotImplemented(HWND hWnd)
{
HRESULT hr;
int nClickedButton;

LPCWSTR szTitle     = L"Current state of the application";
LPCWSTR szHeader    = L"Command not yet implemented";
LPCWSTR szBodyText  = L"Do you like anyway this Win32 application example?";

  hr = TaskDialog ( hWnd, NULL,
                    szTitle, szHeader, szBodyText,
                    TDCBF_YES_BUTTON|TDCBF_NO_BUTTON,
                    TD_INFORMATION_ICON, &nClickedButton );

  if ( SUCCEEDED(hr) && IDYES == nClickedButton )
        {
            // do something...
        }
}

void OnAbout(HWND hWnd)
{
HRESULT hr;
int nClickedButton;

LPCWSTR szTitle     = L"About...";
LPCWSTR szHeader    = L"Task Dialog Win32 example";
LPCWSTR szBodyText  = L"MIT license - Copyright (c) 2020 Sergio Ferrari";

  hr = TaskDialog ( hWnd, NULL,
                    szTitle, szHeader, szBodyText,
                    TDCBF_YES_BUTTON,
                    TD_INFORMATION_ICON, &nClickedButton );

  if ( SUCCEEDED(hr) && IDYES == nClickedButton )
        {
            // do something...
        }
}

BOOL CALLBACK DlgMain(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HMENU hMenu = NULL;
    std::setlocale(LC_ALL, "");

    switch(uMsg)
    {
        case WM_INITDIALOG:
        {
            hMenu = LoadMenu(NULL, MAKEINTRESOURCE(IDW_MAIN));
            SetMenu(hDlg, hMenu);
        }
        return TRUE;

        case WM_CLOSE:
        {
            EndDialog(hDlg, 0);
        }
        return TRUE;

        case WM_COMMAND:
        {
            switch(LOWORD(wParam))
            {
                case IDM_FILE_NEW:
                case IDM_FILE_OPEN:
                case IDM_FILE_SAVE:
                case IDM_FILE_SAVEAS:
                case IDM_FILE_PREVIEW:
                case IDM_FILE_PRINT:    {
                                            NotImplemented(hDlg);
                                            return TRUE;
                                        }
                case IDM_HELP_ABOUT:    {
                                            OnAbout(hDlg);
                                            return TRUE;
                                        }

                case IDM_FILE_EXIT :    SendMessage(hDlg, WM_CLOSE, 0, 0);
                                        break;

            }
        }
        return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
