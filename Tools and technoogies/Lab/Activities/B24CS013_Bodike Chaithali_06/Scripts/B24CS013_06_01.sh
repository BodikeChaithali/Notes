#!/bin/bash

awk -F',' 'NR>1 {
  total = $3+$4+$5
  avg=total/3
  if( avg >= 75 ) 
          grade = "Distinction"
  else if ( avg >= 40 ) 
          grade = "Pass"
  else 
          grade = "Fail"
  printf "Roll No: %d, Name: %s, Total: %d, Average: %.2f, Grade: %s\n", $1 , $2 ,total ,avg , grade }' "$1" >> report_awk.txt

echo "Report Saved"
