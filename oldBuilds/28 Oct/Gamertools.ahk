SetWorkingDir C:\Users\ronbo\Desktop\GamerToolz
#SingleInstance Force
#warn
SendMode Input

#include settings.rgt

^q::ExitApp

F1::Reload

>^Numpad0::ESONew()
>^Numpad1::StrophDeemer()
>^Numpad2::Panthera()
>^Numpad3::tesRun()
>^Numpad4::Chroma()
>^Numpad5::Khora()
>^Numpad6::Saryn()
>^Numpad7::Adaro()
>^Numpad8::FiveSec()
>^Numpad9::TenSec()

<^Numpad0::Send %Left0%

F2::
loop 8
{
SoundBeep, %Freq%, %DurB%
}

Return

Help(){
MsgBox, 0=Eso New`n1= Strophdeemer`n2= panthera`n3= (empty)`n4= Nidus`n5= Khora `n6= Saryn`n7= adaro`n8= 5sec`n9= 10sec
}

#include NorUseLib.rgt
#include preBui.rgt
#include PicSav.rgt

#IfWinExist, #dj - Discord
^+c::DJM()
#if

DJM(){
send ^a
sleep 200
send ^c 
sleep 200
WinActivate, #dj - Discord
sleep 200
send {Enter}
sleep 200
send {raw}!play 
sleep 200
send {space}
sleep 200
send ^v
sleep 200
Send {Enter}
sleep 200
return
}

ascertain(){
WPID := winexist("A")
WinSet, AlwaysOnTop, on, ahk_PID WPID
fileappend, %WPID%, %A_ScriptDir%\settings.rgt
}
