SetWorkingDir %A_ScriptDir%
#SingleInstance Force
#warn
SendMode Input

#include settings.rgt

^q::ExitApp

F1::Reload

>^Numpad0::ESONew()
>^Numpad1::StrophDeemer()
>^Numpad2::Panthera()
>^Numpad3::ESONew()
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
MsgBox, 0=Octavia`n1= stropha`n2= panthera`n3= ESONew`n4= Nidus`n5= Khora `n6= Saryn`n7= adaro`n8= 5sec`n9= 10sec
}

#include NorUseLib.rgt
#include PicSav.rgt

;IfWinActive, Warframe
>!,::Hanger()

Hanger(){
WinGet, cur, ID, A
Send #+s
OnClipboardChange("picSav")
return
}