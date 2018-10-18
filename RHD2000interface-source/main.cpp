//  ------------------------------------------------------------------------
//
//  This file is part of the Intan Technologies RHD2000 Interface
//  Version 1.5.2
//  Copyright (C) 2013-2017 Intan Technologies
//
//  ------------------------------------------------------------------------
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QApplication>
#include <QMessageBox>
#include <QStyleFactory>

#include "mainwindow.h"
#include "guicon.h"
//#include "Windows.h"
//#include "winuser.h"

//#pragma comment(lib,"user32.lib")

//#define MOD_NOREPEAT 0x4000
//#define MOD_CTRL 0x0002
//#define MOD_ALT 0x0001
//#define MOD_SHIFT 0x0004

// Starts application main window.

int main(int argc, char *argv[]){
    //RedirectIOToConsole();

//    for (int kID=49; kID<57; kID++) {
//        RegisterHotKey(NULL,kID,MOD_NOREPEAT,kID);
//    }

    QApplication app(argc, argv);

#ifdef __APPLE__
    app.setStyle(QStyleFactory::create("Fusion"));
#endif

    MainWindow mainWin;
    mainWin.show();

//    app.processEvents();

//    MSG msg;
//    while(GetMessage(&msg, NULL, 0, 0))
//    {
//        if(mainWin.isClosing) {
//            return msg.wParam;
//        }
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//        if(msg.message == WM_HOTKEY)
//        {
//            for (int kID=49; kID<57; kID++) {
//                if (msg.wParam==kID) {
//                    mainWin.keyEvent(kID,true);
//                } else {
//                    mainWin.keyEvent(kID,false);
//                }
//            }
//        }
//    }


    return app.exec();
}
