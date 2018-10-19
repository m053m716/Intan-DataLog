/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Gamepad module
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "gamepadmonitor.h"

#include <QtGamepad/QGamepad>

GamepadMonitor::GamepadMonitor(QObject *parent, MainWindow *inMainWindow)
    : QObject(parent)
    , m_gamepad(0)
{
    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);
    mainWindow = inMainWindow;

//    connect(m_gamepad,&QGamepad::connectedChanged,this,[](bool connectionStatus){
//        connectDisconnect(connectionStatus);
//    });
//    connectButtons();

    // Right-side buttons
    connect(m_gamepad, &QGamepad::buttonAChanged, this, [](bool pressed){
        button1Changed(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonBChanged, this, [](bool pressed){
        button2Changed(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonYChanged, this, [](bool pressed){
        button3Changed(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonXChanged, this, [](bool pressed){
        button4Changed(pressed);
    });

    // Direction-pad (D-pad) buttons
    connect(m_gamepad, &QGamepad::buttonDownChanged, this, [](bool pressed){
        button5Changed(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonUpChanged, this, [](bool pressed){
        button6Changed(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonLeftChanged, this, [](bool pressed){
        button7Changed(pressed);
    });
    connect(m_gamepad, &QGamepad::buttonRightChanged, this, [](bool pressed){
        button8Changed(pressed);
    });
}

GamepadMonitor::~GamepadMonitor()
{
    delete m_gamepad;
}

//void GamepadMonitor::connectButtons()
//{
//    // Right-side buttons
//    connect(m_gamepad, &QGamepad::buttonAChanged, this, [](bool pressed){
//        button1Changed(pressed);
//    });
//    connect(m_gamepad, &QGamepad::buttonBChanged, this, [](bool pressed){
//        button2Changed(pressed);
//    });
//    connect(m_gamepad, &QGamepad::buttonYChanged, this, [](bool pressed){
//        button3Changed(pressed);
//    });
//    connect(m_gamepad, &QGamepad::buttonXChanged, this, [](bool pressed){
//        button4Changed(pressed);
//    });

//    // Direction-pad (D-pad) buttons
//    connect(m_gamepad, &QGamepad::buttonDownChanged, this, [](bool pressed){
//        button5Changed(pressed);
//    });
//    connect(m_gamepad, &QGamepad::buttonUpChanged, this, [](bool pressed){
//        button6Changed(pressed);
//    });
//    connect(m_gamepad, &QGamepad::buttonLeftChanged, this, [](bool pressed){
//        button7Changed(pressed);
//    });
//    connect(m_gamepad, &QGamepad::buttonRightChanged, this, [](bool pressed){
//        button8Changed(pressed);
//    });
//}

//void GamepadMonitor::disconnectButtons()
//{
//    // Right-side buttons
//    disconnect(m_gamepad, &QGamepad::buttonAChanged, this, [](bool pressed){
//        button1Changed(pressed);
//    });
//    disconnect(m_gamepad, &QGamepad::buttonBChanged, this, [](bool pressed){
//        button2Changed(pressed);
//    });
//    disconnect(m_gamepad, &QGamepad::buttonYChanged, this, [](bool pressed){
//        button3Changed(pressed);
//    });
//    disconnect(m_gamepad, &QGamepad::buttonXChanged, this, [](bool pressed){
//        button4Changed(pressed);
//    });

//    // Direction-pad (D-pad) buttons
//    disconnect(m_gamepad, &QGamepad::buttonDownChanged, this, [](bool pressed){
//        button5Changed(pressed);
//    });
//    disconnect(m_gamepad, &QGamepad::buttonUpChanged, this, [](bool pressed){
//        button6Changed(pressed);
//    });
//    disconnect(m_gamepad, &QGamepad::buttonLeftChanged, this, [](bool pressed){
//        button7Changed(pressed);
//    });
//    disconnect(m_gamepad, &QGamepad::buttonRightChanged, this, [](bool pressed){
//        button8Changed(pressed);
//    });
//}

void GamepadMonitor::button1Changed(bool pressed)
{
//    mainWindow->keyEvent(49,pressed);
    emit buttonChanged(49,pressed);
}

void GamepadMonitor::button2Changed(bool pressed)
{
//    mainWindow->keyEvent(50,pressed);
    emit buttonChanged(50,pressed);
}

void GamepadMonitor::button3Changed(bool pressed)
{
//    mainWindow->keyEvent(51,pressed);
    emit buttonChanged(51,pressed);
}

void GamepadMonitor::button4Changed(bool pressed)
{
//    mainWindow->keyEvent(52,pressed);
    emit buttonChanged(52,pressed);
}

void GamepadMonitor::button5Changed(bool pressed)
{
//    mainWindow->keyEvent(53,pressed);
    emit buttonChanged(53,pressed);
}

void GamepadMonitor::button6Changed(bool pressed)
{
//    mainWindow->keyEvent(54,pressed);
    emit buttonChanged(54,pressed);
}

void GamepadMonitor::button7Changed(bool pressed)
{
//    mainWindow->keyEvent(55,pressed);
    emit buttonChanged(55,pressed);
}

void GamepadMonitor::button8Changed(bool pressed)
{
//    mainWindow->keyEvent(56,pressed);
    emit buttonChanged(56,pressed);
}

//void GamepadMonitor::connectDisconnect(bool connected)
//{
//    if (connected)
//    {
//        connectButtons();
//    } else {
//        disconnectButtons();
//    }
//}

//void GamepadMonitor::buttonChanged(int kID, bool pressed)
//{

//}
