rm *.lyx~

# Convert all LyX files to PDF
lyx -e pdf2 `find . | egrep "\.lyx"`

# Concatenate all PDFs in the correct order
pdfunite \
  ArduinoCourseDay01_Start.pdf \
  ArduinoCourseIntroduction.pdf \
  ArduinoCourseWhatIsArduino.pdf \
  ArduinoCourseConnectLed.pdf \
  ArduinoCourseSwitchLed.pdf \
  ArduinoCourseDay01_Exercises.pdf \
  ArduinoCourseDay02_Start.pdf \
  ArduinoCourseShortCircuit.pdf \
  ArduinoCourseAnalogRead.pdf \
  ArduinoCourseReadInput.pdf \
  ArduinoCourseDay02_Exercises.pdf \
  ArduinoCourseDay03_Start.pdf \
  ArduinoCourseReadSensor.pdf \
  ArduinoCourseSolarMotor.pdf \
  ArduinoCourseDay04_Start.pdf \
  ArduinoCourseMindset.pdf \
  ArduinoCourseAll.pdf  #Output

#Convert ArduinoCourseAll.pdf to handout format (4 columns, 2 rows)
java -cp Multivalent.jar tool.pdf.Impose -dim 4x2 -paper 84x29.7cm ArduinoCourseAll.pdf

#Rename the resulting PDF
mv ArduinoCourseAll-up.pdf ArduinoCourseAllHandouts.pdf

#Negate the resulting PDF
convert ArduinoCourseAllHandouts.pdf -negate ArduinoCourseAllHandoutsNegated.pdf
