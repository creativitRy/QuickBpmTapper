if A_Args.Length() != 1
{
    MsgBox % "This script requires 1 parameter but it received " A_Args.Length() " parameters."
    Exit, 1
}

WinGet, winid ,, A

if WinExist("ahk_exe MusicBee.exe")
    WinActivate, ahk_exe MusicBee.exe
else
    Exit, 1

Send +{Enter}
Send +{Tab}
Send {Right}
Send {Tab 6}
Sleep 30
bpm := A_Args[1]
Send %bpm%
Send {Enter}

WinActivate ahk_id %winid%
