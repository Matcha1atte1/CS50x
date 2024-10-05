-- Keep a log of any SQL queries you execute as you solve the mystery.

-- crime_scene_reports table to look for a crime scene report that matches the date and location of the crime
SELECT id
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- output id 295,297
