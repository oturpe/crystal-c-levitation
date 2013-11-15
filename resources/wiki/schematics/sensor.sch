<Qucs Schematic 0.0.16>
<Properties>
  <View=-139,0,800,800,1,139,0>
  <Grid=10,10,1>
  <DataSet=sensor.dat>
  <DataDisplay=sensor.dpl>
  <OpenDisplay=1>
  <Script=sensor.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
  <.PortSym 40 20 1 0>
</Symbol>
<Components>
  <GND * 1 40 190 0 0 0 0>
  <GND * 1 40 270 0 0 0 2>
  <R R2 1 220 300 -52 43 0 1 "10 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 220 270 0 0 0 2>
  <R R1 1 220 160 -55 -82 0 1 "10 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 220 190 0 0 0 0>
  <Vfile Sensor_top 1 40 160 18 -26 0 1 "vfile.dat" 0 "linear" 0 "no" 0 "1" 0 "0" 0>
  <Vfile Sensor_bottom 1 40 300 27 -23 0 3 "vfile.dat" 0 "linear" 0 "no" 0 "1" 0 "0" 0>
  <OpAmp LM324 1 470 230 4 -57 0 0 "1e6" 0 "15 V" 0>
  <Port Position_signal 1 570 230 4 -33 0 2 "1" 0 "analog" 0>
  <R R6 1 470 320 -26 15 0 0 "470 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R5 1 420 120 -20 -77 0 1 "470 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <GND * 1 460 90 0 0 0 0>
  <R R3 1 370 210 -80 -51 0 0 "100 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R4 1 370 250 -80 12 0 0 "100 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
</Components>
<Wires>
  <510 230 570 230 "" 0 0 0 "">
  <220 330 260 330 "" 0 0 0 "">
  <220 130 260 130 "" 0 0 0 "">
  <420 250 440 250 "" 0 0 0 "">
  <40 130 220 130 "" 0 0 0 "">
  <40 330 220 330 "" 0 0 0 "">
  <500 320 510 320 "" 0 0 0 "">
  <510 230 510 320 "" 0 0 0 "">
  <420 250 420 320 "" 0 0 0 "">
  <420 320 440 320 "" 0 0 0 "">
  <420 90 460 90 "" 0 0 0 "">
  <420 210 440 210 "" 0 0 0 "">
  <420 150 420 210 "" 0 0 0 "">
  <400 210 420 210 "" 0 0 0 "">
  <260 130 260 210 "" 0 0 0 "">
  <260 210 340 210 "" 0 0 0 "">
  <400 250 420 250 "" 0 0 0 "">
  <260 250 260 330 "" 0 0 0 "">
  <260 250 340 250 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
  <Text 290 420 12 #000000 0 "For good accuracy, R3, R4, R5 and R6 should\nhave 1 % tolerances">
</Paintings>
