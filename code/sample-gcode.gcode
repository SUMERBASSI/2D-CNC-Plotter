G21 ; Set units to mm
G90 ; Absolute positioning
G28 ; Home (if enabled)

M3 S90 ; Pen down (adjust S for servo angle)
G0 X0 Y0
G1 X20 Y0 F500
G1 X20 Y20
G1 X0 Y20
G1 X0 Y0

M5 ; Pen up
G0 X0 Y0
M2 ; End program
