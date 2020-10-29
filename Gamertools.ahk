SetWorkingDir %A_ScriptDir%
#SingleInstance Force
#warn
SendMode Input

#include settings.rgt

^q::ExitApp

F1::Reload
<^Numpad0::send %LCN0%
>^Numpad0::tesRun()
>^Numpad1::StrophDeemer()
>^Numpad2::Panthera()
>^Numpad3::tesRun()
>^Numpad4::Chroma()
>^Numpad5::Khora()
>^Numpad6::Saryn()
>^Numpad7::Adaro()
>^Numpad8::FiveSec()
>^Numpad9::TenSec()

F2::
loop 8
{
SoundBeep, %Freq%, %DurA%
}

Return

Help(){
MsgBox, 0=Eso New`n1= Strophdeemer`n2= panthera`n3= (empty)`n4= Nidus`n5= Khora `n6= Saryn`n7= adaro`n8= 5sec`n9= 10sec
}

#include WFToolz\actions.rgt
#include WFToolz\PicSav.rgt
#include WFToolz\DJCopPas.rgt