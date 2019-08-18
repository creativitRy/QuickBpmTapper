if A_Args.Length() != 1
{
    MsgBox % "This script requires 2 parameters but it received " A_Args.Length() "."
    ExitApp
}

MsgBox % "Parameter number 1 is " A_Args[1] "."
