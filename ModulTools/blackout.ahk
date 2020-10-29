#SingleInstance force
^+F12::Reload

^F12::
Run, X:\blaOut.png, , max 
WinWait, blaOut.png - Paint
WinSet, Style, +0xC00000, A
WinSet, Redraw
WinMove, blaOut.png - Paint, , 2500, 50
winhide
winshow
sleep 700
send {f11}
Return